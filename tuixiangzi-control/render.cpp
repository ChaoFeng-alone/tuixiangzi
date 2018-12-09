#include"head.h"
void gotoxy(int x, int y);
void render()
{
	extern struct custommap custom;
	extern char custommap[50][50];
	extern int next;
	extern int level;
	extern char initmap[20][30];
	extern char shuoming[20][50];
	extern int box_num[MAX_STAP];
	extern int box_x[10];
	extern int box_y[10];
	extern int box_size;
	extern int stap;
	extern int m_x[MAX_STAP][1];
	extern int m_y[MAX_STAP][1];
	extern char chosemap[20][30];
	extern char map[MAX_STAP][50][50];
	extern int map_i;
	extern int sence;
	system("cls");//首先清屏
	if (sence == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			puts(initmap[i]);
		}
	}
	else if (sence == 1)
	{
		for (int i = 0; i <= 10; i++)
		{
			puts(chosemap[i]);
		}
	}
	else if (sence == 2)
	{
		for (int i = 0; i <= custom.cusmap_i; i++)
		{
			puts(custommap[i]);
		}
		gotoxy(custom.now_x + 1, custom.now_y);
		printf("\b");
		printf("%c", custom.now);
		return;
	}
	else if (sence == 3)
	{
		for (int i = 0; i <= map_i; i++)
		{
			puts(map[stap][i]);
		}
		printf("       --------------第%d关--------------\n",level);
		printf("      ||           步数：%3d           ||\n", stap);
		printf("      ||     撤销（U）    重置（R）    ||\n");
		printf("      || 箱子总数：%2d   剩余箱子数：%2d ||\n", box_num[0], box_num[stap]);
		printf("       ---------------------------------\n");
		//该函数功能是将光标定位到gotoxy(x,y)中的xy处，应注意：该x是横向，y是纵向
		gotoxy(m_y[stap][0] + 1, m_x[stap][0]);
		printf("\b");
		printf("@");
	}
	else if (sence == 4)
	{
		for (int i = 0; i <= map_i; i++)
		{
			puts(map[stap][i]);
		}
		printf("\n\n");
		printf("\t\t\t\t\t\t 恭喜通关\n");
		printf("\t\t\t\t\t\t 步数：%d\n", stap);
		printf("\t\t\t\t\t\t下一关（N）\n");
	}
	else if (sence == 5)
	{
		for (int i = 0; i <= 10; i++)
		{
			puts(shuoming[i]);
		}
	}
	else if (sence == 6)
	{
		printf("\n\n\n\n");
		printf("\t\t\t\t\t\t 第%2d关\n",level);
		printf("\t\t\t\t\t\t继续（ESC）\n");
		printf("\t\t\t\t   自定义（X）   重玩（R）   主菜单（M）\n");
		printf("\n\n\t\t\t\t\t\t操作说明\n");
		printf("\t\t\t\t\t分别使用wsad向上下左右移动\n");
		printf("\t\t\t\t\t@：人   O：箱子    X：终点\n");
	}
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
//---------------------
//作者：radjedef
//来源：CSDN
//原文：https ://blog.csdn.net/radjedef/article/details/79028329 
//版权声明：本文为博主原创文章，转载请附上博文链接！