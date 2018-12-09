#include"head.h"
void delay()
{
	extern int sence;
	extern int step;
	extern int box_size;
	extern char map[MAX_STEP][50][50];
	extern int m_x[MAX_STEP][1];
	extern int m_y[MAX_STEP][1];
	extern int box_x[10];
	extern int box_y[10];
	extern int counter;
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
	counter += 2;
	if (counter > 60)
		counter = 0;
}