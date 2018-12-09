#include"head.h"
void initii();
void render()
{
	extern struct custommap custom;
	extern int m_x[MAX_STEP][1];
	extern int m_y[MAX_STEP][1];
	extern int counter;
	extern char key;
	extern int map_wide;
	extern int map_high;
	extern int step;
	extern int map_i;
	extern int map_j;
	extern char map[MAX_STEP][50][50];
	extern char custommap[50][50];
	extern int sence;
	extern int level;
	PIMAGE wall = newimage();
	PIMAGE land = newimage();
	PIMAGE BoxYellow = newimage();
	PIMAGE BoxRed = newimage();
	PIMAGE aim = newimage();
	PIMAGE ManUP1 = newimage();
	PIMAGE ManUP2 = newimage();
	PIMAGE ManDOWN1 = newimage();
	PIMAGE ManDOWN2 = newimage();
	PIMAGE ManRIGHT1 = newimage();
	PIMAGE ManRIGHT2 = newimage();
	PIMAGE ManLEFT1 = newimage();
	PIMAGE ManLEFT2 = newimage();
	PIMAGE black = newimage();
	PIMAGE bg = newimage();
	PIMAGE write = newimage();
	PIMAGE write1 = newimage();


	getimage(wall, "resources\\image\\wall.jpg", 0, 0);
	getimage(land, "resources\\image\\land.jpg", 0, 0);
	getimage(BoxYellow, "resources\\image\\BoxYellow.jpg", 0, 0);
	getimage(BoxRed, "resources\\image\\BoxRed.jpg", 0, 0);
	getimage(aim, "resources\\image\\aim.jpg", 0, 0);
	getimage(ManUP1, "resources\\image\\ManUP1.jpg", 0, 0);
	getimage(ManUP2, "resources\\image\\ManUP2.jpg", 0, 0);
	getimage(ManDOWN1, "resources\\image\\ManDOWN1.jpg", 0, 0);
	getimage(ManDOWN2, "resources\\image\\ManDOWN2.jpg", 0, 0);
	getimage(ManRIGHT1, "resources\\image\\ManRIGHT1.jpg", 0, 0);
	getimage(ManRIGHT2, "resources\\image\\ManRIGHT2.jpg", 0, 0);
	getimage(ManLEFT1, "resources\\image\\ManLEFT1.jpg", 0, 0);
	getimage(ManLEFT2, "resources\\image\\ManLEFT2.jpg", 0, 0);
	getimage(black, "resources\\image\\black.jpg", 0, 0);
	getimage(bg, "resources\\image\\timg.jpg", 0, 0);
	getimage(write, "resources\\image\\write.jpg", 0, 0);
	getimage(write1, "resources\\image\\write1.jpg", 0, 0);
	char slevel[3];
	if (sence == 0)
	{
		initii();
		outtextxy(340, 290, "开始游戏（S）");
		outtextxy(340, 370, "操作说明（C）");
		outtextxy(340, 450, "退出游戏（Q）");
	}
	else if (sence == 1)
	{
		initii();
		outtextxy(340, 290, "从头开始（A）");
		outtextxy(340, 370, "  选关（S）");
		outtextxy(340, 450, "自定义地图（C）");
		outtextxy(340, 530, "返回上一级（R）");
	}
	else if (sence == 2)
	{
		initii();
		outtextxy(340, 290, "按A，D选关");
		sprintf(slevel, "%d", level);
		outtextxy(380, 370, slevel);
		outtextxy(340, 450, "返回上一级（R）");
	}
	else if (sence == 3)
	{
		cleardevice();
		setcolor(WHITE);
		//定义图片指针
		PIMAGE initlo = newimage();
		//加载init.jpg
		getimage(initlo, "resources\\image\\i.jpg");
		putimage(760, 0, initlo);
		putimage(10, 0, bg);
		putimage_alphablend(NULL, write, 760, 138, 0x33);
		setfillcolor(WHITE);
		//游戏区域与信息区域分界线
		bar(750, 0, 755, 700);
		bar(0, 0, 10, HEIGHT);
		bar(10, HEIGHT - 10, LONG - 10, LONG);
		bar(LONG - 10, 0, LONG, HEIGHT);
		setfont(48, 0, "楷体");
		setcolor(EGERGB(0x00, 0xcc, 0xff));
		char str[20];
		sprintf(str, "第%d关", level);
		outtextxy(800, 150, str);
		setfont(24, 0, "楷体");
		sprintf(str, "步数：%d", step);
		outtextxy(780, 250, str);

		outtextxy(780, 300, "重玩本关(R)");
		outtextxy(780, 350, "撤销(U)");
		outtextxy(780, 400, "暂停(ESC)");
		int i, t;
		for (i = 1; i <= map_i; i++)
		{
			for (t = 0; t < map_j; t++)
			{
				//if (map[step][i][t] == '|' || map[step][i][t] == '=')
				//	putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, black);
				if (map[step][i][t] == ' ')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, land);
				if (map[step][i][t] == 'O')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, BoxYellow);
				if (map[step][i][t] == 'Q')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, BoxRed);
				if (map[step][i][t] == '#')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, wall);
				if (map[step][i][t] == 'X')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, aim);

			}
			if (map[step][i][1] == '|')
				break;
		}
		if (key == 'd')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManRIGHT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManRIGHT2);
		}
		else if (key == 'a')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManLEFT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManLEFT2);
		}
		else if (key == 'w')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManUP1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManUP2);
		}
		else
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManDOWN1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManDOWN2);
		}
		delimage(initlo);
		delimage(bg);
	}
	else if (sence == 4)
	{
		initii();
		outtextxy(420, 250, "过关！");

		setfont(40, 0, "楷体");
		char str[20];
		sprintf(str, "本关总计步数:%d", step);
		outtextxy(350, 350, str);

		setfont(40, 0, "楷体");
		outtextxy(140, 450, "选关(X)");
		outtextxy(420, 450, "下一关(N)");
		outtextxy(700, 450, "菜单(M)");

	}
	else if (sence == 5)
	{
		initii();
		outtextxy(170, 290, "W：上  S：下  A：左  D：右");
		outtextxy(340, 370, "返回上级菜单（R）");
		outtextxy(340, 450, " 退出游戏（Q）");
	}
	else if (sence == 6)
	{
		initii();
		outtextxy(400, 280, "继续(ESC)");
		setfont(40, 0, "楷体");
		outtextxy(140, 380, "选关(X)");
		outtextxy(420, 380, "重玩(R)");
		outtextxy(700, 380, "主菜单(M)");
	}
	else if (sence == 7)
	{
		cleardevice();
		PIMAGE initlo = newimage();
		//加载init.jpg
		getimage(initlo, "resources\\image\\i.jpg", 0, 0);
		putimage(760, 0, initlo);
		delimage(initlo);
		putimage(10, 0, bg);
		putimage_alphablend(NULL, write, 757, 25, 0x33);
		//设置颜色
		setcolor(EGERGB(0x00, 0xcc, 0xff));
		//为增加美观，在窗口边缘添加填充条
		setfillcolor(WHITE);
		bar(750, 0, 755, 700);
		bar(0, 0, 10, HEIGHT);
		bar(10, HEIGHT - 10, LONG - 10, LONG);
		bar(LONG - 10, 0, LONG, HEIGHT);
		//设置文字背景模式为透明
		setbkmode(TRANSPARENT);
		//设置字体
		setfont(50, 0, "幼圆");
		putimage(760, 40, wall);
		outtextxy(765, 90, "1");
		putimage(820, 40, BoxYellow);
		outtextxy(825, 90, "2");
		putimage(880, 40, ManDOWN1);
		outtextxy(885, 90, "3");
		putimage(940, 40, aim);
		outtextxy(945, 90, "4");
		putimage(760, 160, BoxRed);
		outtextxy(765, 210, "5");
		putimage(820, 160, land);
		outtextxy(825, 210, "6");
		setfont(30, 0, "幼圆");
		outtextxy(760, 310, "选择对应图形后");
		outtextxy(760, 350, "使用WSAD");
		outtextxy(760, 390, "上下左右移动");
		outtextxy(760, 430, "按Q确定");
		outtextxy(760, 470, "按E完成创建");
		//xyprintf(760, 310, "选择对应\n图形后\n\n\n\n\n自定义开始游戏");
		int i, t;
		for (i = 1; i <= 13; i++)
		{
			for (t = 0; t < 17; t++)
			{
				/*if (custommap[i][t] == '|' || custommap[i][t] == '=')
					putimage(40 + t * 40, i * 40, black);*/
				if (custommap[i][t] == ' ')
					putimage(40 + t * 40, i * 40, land);
				if (custommap[i][t] == 'O')
					putimage(40 + t * 40, i * 40, BoxYellow);
				if (custommap[i][t] == 'Q')
					putimage(40 + t * 40, i * 40, BoxRed);
				if (custommap[i][t] == '#')
					putimage(40 + t * 40, i * 40, wall);
				if (custommap[i][t] == 'X')
					putimage(40 + t * 40, i * 40, aim);
				if (custommap[i][t] == '@')
					putimage(40 + t * 40, i * 40, ManDOWN1);
			}
		}
		if (custom.now == '#')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, wall);
		}
		else if (custom.now == 'O')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, BoxYellow);
		}
		else if (custom.now == '@')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, ManDOWN1);
		}
		else if (custom.now == 'X')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, aim);
		}
		else if (custom.now == 'Q')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, BoxRed);
		}
		else if (custom.now == ' ')
		{
			putimage(40 + custom.now_x * 40, 40 + custom.now_y * 40, land);
		}

	}
	else if (sence == 71)
	{
		cleardevice();
		setcolor(WHITE);
		//定义图片指针
		PIMAGE initlo = newimage();
		//加载init.jpg
		getimage(initlo, "resources\\image\\i.jpg");
		putimage(760, 0, initlo);
		putimage(10, 0, bg);
		putimage_alphablend(NULL, write, 760, 138, 0x33);
		setfillcolor(WHITE);
		//游戏区域与信息区域分界线
		bar(750, 0, 755, 700);
		bar(0, 0, 10, HEIGHT);
		bar(10, HEIGHT - 10, LONG - 10, LONG);
		bar(LONG - 10, 0, LONG, HEIGHT);
		setfont(48, 0, "楷体");
		setcolor(EGERGB(0x00, 0xcc, 0xff));
		char str[20];
		sprintf(str, "第%d关", level);
		outtextxy(800, 150, str);
		setfont(24, 0, "楷体");
		sprintf(str, "步数：%d", step);
		outtextxy(780, 250, str);

		outtextxy(780, 300, "重玩本关(R)");
		outtextxy(780, 350, "撤销(U)");
		outtextxy(780, 400, "暂停(ESC)");
		int i, t;
		for (i = 1; i <= map_i; i++)
		{
			for (t = 0; t < map_j; t++)
			{
				//if (map[step][i][t] == '|' || map[step][i][t] == '=')
				//	putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, black);
				if (map[step][i][t] == ' ')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, land);
				if (map[step][i][t] == 'O')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, BoxYellow);
				if (map[step][i][t] == 'Q')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, BoxRed);
				if (map[step][i][t] == '#')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, wall);
				if (map[step][i][t] == 'X')
					putimage(t * 40 + map_wide * 40, i * 40 + map_high * 40, aim);

			}
			if (map[step][i][1] == '|')
				break;
		}
		if (key == 'd')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManRIGHT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManRIGHT2);
		}
		else if (key == 'a')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManLEFT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManLEFT2);
		}
		else if (key == 'w')
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManUP1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManUP2);
		}
		else
		{
			if (counter > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManDOWN1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_high * 40, ManDOWN2);
		}
		delimage(initlo);
	}
	else if (key == 'm')
	{
		if (sence == 6 || sence == 4)
		{
			sence = 0;
			cleardevice();
			return;
		}
	}
	delimage(wall);
	delimage(land);
	delimage(BoxYellow);
	delimage(BoxRed);
	delimage(aim);
	delimage(ManUP1);
	delimage(ManUP2);
	delimage(ManDOWN1);
	delimage(ManDOWN2);
	delimage(ManRIGHT1);
	delimage(ManRIGHT2);
	delimage(ManLEFT1);
	delimage(ManLEFT2);
	delimage(black);
}

void initii()
{
	cleardevice();
	PIMAGE initmap = newimage();
	//initmap = newimage();
	//将initimg图片放进initmap指针
	getimage(initmap, "resources\\image\\initimg.jpg", 0, 0);
	putimage(LONG / 2 - INITIMAGEL / 2, HEIGHT*0.1, initmap);
	//设置颜色
	setcolor(EGERGB(0x00, 0xcc, 0xff));
	//为增加美观，在窗口边缘添加填充条
	setfillcolor(WHITE);
	bar(0, 590, 1000, 600);
	bar(0, 0, 10, 600);
	bar(990, 0, 1000, 600);
	delimage(initmap);
	setfontbkcolor(BLACK);
	//设置文字背景模式为透明
	setbkmode(TRANSPARENT);

	//设置字体
	setfont(50, 0, "幼圆");
}