#include"head.h"
void init()
{
	extern char initmap[20][30];
	extern int level;
	extern int next;
	extern int sence;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取窗口句柄
	CONSOLE_CURSOR_INFO cci;//实列化一个控制台光标信息类
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息

	system("title control1.0");//设定窗口名称
	system("mode con cols=120 lines=30");//设定窗口大小
		system("cls");
		for (int i = 0; i < 13; i++)
			puts(initmap[i]);
	
	
}
