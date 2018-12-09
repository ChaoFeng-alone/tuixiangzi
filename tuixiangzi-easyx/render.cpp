#include"head.h"
void initii();
void render()
{
	extern int cont;
	extern char key;
	extern int m_x[MAX_STEP][1];
	extern int m_y[MAX_STEP][1];
	extern int next;
	extern int map_j;
	extern int map_i;
	extern char map[MAX_STEP][50][50];
	extern int map_wide;
	extern int map_hight;
	extern int step;
	extern int sence;
	extern int level;
	//����ͼƬ
	IMAGE wall;
	IMAGE land;
	IMAGE BoxYellow;
	IMAGE BoxRed;
	IMAGE aim;
	IMAGE ManUP1;
	IMAGE ManUP2;
	IMAGE ManDOWN1;
	IMAGE ManDOWN2;
	IMAGE ManRIGHT1;
	IMAGE ManRIGHT2;
	IMAGE ManLEFT1;
	IMAGE ManLEFT2;
	IMAGE black;
	loadimage(&wall, "resources\\image\\wall.jpg", 0, 0);
	loadimage(&land, "resources\\image\\land.jpg", 0, 0);
	loadimage(&BoxYellow, "resources\\image\\BoxYellow.jpg", 0, 0);
	loadimage(&BoxRed, "resources\\image\\BoxRed.jpg", 0, 0);
	loadimage(&aim, "resources\\image\\aim.jpg", 0, 0);
	loadimage(&ManUP1, "resources\\image\\ManUP1.jpg", 0, 0);
	loadimage(&ManUP2, "resources\\image\\ManUP2.jpg", 0, 0);
	loadimage(&ManDOWN1, "resources\\image\\ManDOWN1.jpg", 0, 0);
	loadimage(&ManDOWN2, "resources\\image\\ManDOWN2.jpg", 0, 0);
	loadimage(&ManRIGHT1, "resources\\image\\ManRIGHT1.jpg", 0, 0);
	loadimage(&ManRIGHT2, "resources\\image\\ManRIGHT2.jpg", 0, 0);
	loadimage(&ManLEFT1, "resources\\image\\ManLEFT1.jpg", 0, 0);
	loadimage(&ManLEFT2, "resources\\image\\ManLEFT2.jpg", 0, 0);
	loadimage(&black, "resources\\image\\black.jpg", 0, 0);


	char slevel[3];
	if (sence == 0)
	{
		initii();
		outtextxy(340, 290, "��ʼ��Ϸ��S��");
		outtextxy(340, 370, "����˵����C��");
		outtextxy(340, 450, "�˳���Ϸ��Q��");
	}
	else if (sence == 1)
	{
		initii();
		outtextxy(340, 290, "��ͷ��ʼ��A��");
		outtextxy(340, 370, "  ѡ�أ�S��");
		outtextxy(340, 450, "������һ����R��");
	}
	else if (sence == 2)
	{
		initii();
		outtextxy(340, 290, "��A��Dѡ��");
		sprintf(slevel, "%d", level);
		outtextxy(380, 370, slevel);
		outtextxy(340, 450, "������һ����R��");
	}
	else if (sence == 3)
	{
		if (next == 1)
		{
			cleardevice();
			next = 0;
		}
		setcolor(WHITE);
		//����ͼƬָ��
		IMAGE initlo;
		//����init.jpg
		loadimage(&initlo, "resources\\image\\i.jpg");
		putimage(760, 0, &initlo);
		
		setfillcolor(WHITE);
		//��Ϸ��������Ϣ����ֽ���
		bar(750, 0, 755, 700);
		bar(0, 0, 10, HEIGHT);
		bar(10, HEIGHT - 10, LONG - 10, LONG);
		bar(LONG - 10, 0, LONG, HEIGHT);


		settextstyle(48, 0, "����");
		settextcolor(RGB(0x00, 0xcc, 0xff));
		char str[20];
		sprintf(str, "��%d��", level);
		outtextxy(800, 150, str);
		settextstyle(24, 0, "����");
		sprintf(str, "������%d", step);
		outtextxy(780, 250, str);

		outtextxy(780, 300, "���汾��(R)");
		outtextxy(780, 350, "����(U)");
		outtextxy(780, 400, "��ͣ(ESC)");


		for (int i = 1; i <= map_i; i++)
		{
			for (int t = 0; t < map_j; t++)
			{
				if (map[step][i][t] == '|' || map[step][i][t] == '=')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &black);
				if (map[step][i][t] == ' ')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &land);
				if (map[step][i][t] == 'O')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &BoxYellow);
				if (map[step][i][t] == 'Q')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &BoxRed);
				if (map[step][i][t] == '#')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &wall);
				if (map[step][i][t] == 'X')
					putimage(t * 40 + map_wide * 40, i * 40 + map_hight * 40, &aim);
				if (map[step][i][t] == '@')
				{
					if (key == 'w')
					{
						if (cont > 30)
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManUP1);
						else
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManUP2);
					}
					else if (key == 's')
					{
						if (cont > 30)
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManDOWN1);
						else
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManDOWN2);
					}
					else if (key == 'a')
					{
						if (cont > 30)
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManLEFT1);
						else
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManLEFT2);
					}
					else if (key == 'd')
					{
						if (cont > 30)
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManRIGHT1);
						else
							putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManRIGHT2);
					}
				}
			}
			
			if (map[step][i][1] == '|')
				break;
		}
		if (key == 'w')
		{
			if (cont > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManUP1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManUP2);
		}
		else if (key == 's')
		{
			if (cont > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManDOWN1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManDOWN2);
		}
		else if (key == 'a')
		{
			if (cont > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManLEFT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManLEFT2);
		}
		else if (key == 'd')
		{
			if (cont > 30)
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManRIGHT1);
			else
				putimage(m_y[step][0] * 40 + map_wide * 40, m_x[step][0] * 40 + map_hight * 40, &ManRIGHT2);
		}
		
	}
	else if (sence == 4)
	{
		initii();
		outtextxy(420, 250, "���أ�");

		setfont(40, 0, "����");
		char str[20];
		sprintf(str, "�����ܼƲ���:%d", step);
		outtextxy(350, 350, str);

		setfont(40, 0, "����");
		outtextxy(140, 450, "ѡ��(X)");
		outtextxy(420, 450, "��һ��(N)");
		outtextxy(700, 450, "�˵�(M)");

	}
	else if (sence == 5)
	{
		initii();
		outtextxy(170, 290, "W����  S����  A����  D����");
		outtextxy(340, 370, "�����ϼ��˵���R��");
		outtextxy(340, 450, " �˳���Ϸ��Q��");
	}
	else if (sence == 6)
	{
	initii();
	outtextxy(400, 280, "����(ESC)");
	settextstyle(40, 0, "����");
	outtextxy(140, 380, "ѡ��(X)");
	outtextxy(420, 380, "����(R)");
	outtextxy(700, 380, "���˵�(M)");
	}
}

void initii()
{
	cleardevice();
	setcolor(WHITE);
	bar(0, 0, 10, HEIGHT);
	bar(10, HEIGHT - 10, LONG - 10, LONG);
	bar(LONG - 10, 0, LONG, HEIGHT);
	//����ͼƬָ��
	IMAGE initmap;
	//����init.jpg
	loadimage(&initmap, "resources\\image\\init.jpg");
	//���������������ڴ��init.jpg�ĳ���
	int initl, inith;
	//initl = initmap.loadwidth();
	//inith = initmap.loadheight();
	//ʹinit.jpgλ�ھ��п��ϵ�λ��
	putimage(301, 60, &initmap);
	//��������
	settextstyle(50, 0, "����");
	settextcolor(RGB(0x00, 0xcc, 0xff));
}