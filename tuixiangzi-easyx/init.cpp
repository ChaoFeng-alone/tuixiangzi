#include"head.h"
void init()
{
	//初始化图像窗口大小为LONG*WIDE
	initgraph(LONG, HEIGHT);
	//为增加美观，在窗口边缘添加填充条
	setcolor(WHITE);
	bar(0, 0, 10, HEIGHT);
	bar(10, HEIGHT - 10, LONG - 10, LONG);
	bar(LONG - 10, 0, LONG, HEIGHT);
	//定义图片指针
	IMAGE initmap;
	//加载init.jpg
	loadimage(&initmap, "resources\\image\\init.jpg");
	//定义两个变量用于存放init.jpg的长宽
	int initl, inith;
	initl = initmap.getwidth();
	inith = initmap.getheight();
	//使init.jpg位于居中靠上的位置
	putimage(LONG / 2 - initl / 2, HEIGHT*0.1, &initmap);

	//设置字体
	settextstyle(50, 0, "楷体");
	settextcolor(RGB(0x00, 0xcc, 0xff));
	outtextxy(340, 290, "开始游戏（S）");
	outtextxy(340, 370, "操作说明（C）");
	outtextxy(340, 450, "退出游戏（Q）");

}