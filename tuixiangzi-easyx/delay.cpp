#include"head.h"
void delay()
{
	//int timer = 0;
	//do
	//{
	//	Sleep(1);
	//	timer++;

	//} while (timer >100);
	extern int cont;
	extern int step;
	extern int boxx[10];
	extern int boxy[10];
	extern int box_num[MAX_STEP];
	extern int box_size;
	extern int m_x[MAX_STEP][1];
	extern int m_y[MAX_STEP][1];
	extern int sence;
	extern int next;
	extern int level;
	extern char map[MAX_STEP][50][50];
	extern int box_x[10];
	extern int box_y[10];
	//处理之前遗留的不能在箱位上移动的bug
	if (sence == 3)
	{
		for (int i = 1; i <= box_size; i++)
		{
			if (map[step][box_x[i]][box_y[i]] != 'Q'&&map[step][box_x[i]][box_y[i]] != 'X')
			{
				map[step][box_x[i]][box_y[i]] = 'X';
			}
		}
	}
	
	Sleep(33);
	cont += 2;
	if (cont > 60)
		cont = 0;
}