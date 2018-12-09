#include"head.h"
void init()
{

	//大小为LONG*WIDE
	initgraph(LONG, HEIGHT);
	//设置窗口标题
	setcaption("推箱子EGE");
	//cls
	cleardevice();
	//定义EGE图片指针
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
	outtextxy(340, 290, "开始游戏（S）");
	outtextxy(340, 370, "操作说明（C）");
	outtextxy(340, 450, "退出游戏（Q）");
	MUSIC bgm;
	bgm.OpenFile("resources\\music\\bgm.wav");
	bgm.Play(0);
	delay_fps(6000);
}