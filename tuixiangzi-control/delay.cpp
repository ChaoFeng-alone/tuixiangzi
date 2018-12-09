#include"head.h"
void delay()
{
	extern int stap;
	extern int boxx[10];
	extern int boxy[10];
	extern int box_num[MAX_STAP];
	extern int box_size;
	extern int m_x[MAX_STAP][1];
	extern int m_y[MAX_STAP][1];
	extern int sence;
	extern int next;
	extern int level;
	extern char map[MAX_STAP][50][50];
	extern int box_x[10];
	extern int box_y[10];
	//处理之前遗留的不能在箱位上移动的bug
	if (sence == 3)
	{
		for (int i = 1; i <= box_size; i++)
		{
			if (map[stap][box_x[i]][box_y[i]] != 'Q'&&map[stap][box_x[i]][box_y[i]] != 'X')
			{
				map[stap][box_x[i]][box_y[i]] = 'X';
			}
		}
	}
}