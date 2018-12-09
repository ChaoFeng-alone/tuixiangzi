#include"head.h"
	extern int box_size;
	extern int next;
	extern int box_num[MAX_STEP];
	extern int map_i;
	extern int step;
	extern char map[MAX_STEP][50][50];
	extern int m_x[MAX_STEP][1];
	extern int m_y[MAX_STEP][1];
	extern int level;
	extern int ifrun;
	extern char key;
	extern int sence;
void event()
{
	
	//kbhit函数用于判断是否有键盘输入，若有，则返回1，反之返回0
	if (kbhit())
	{
		key = getch();
		key = tolower(key);
		if (key == 's')
		{
			if (sence == 0)
			{
				sence = 1;
				return;
			}
			else if (sence == 1)
			{
				sence = 2;
				return;
			}
			else if (sence == 3)
			{
				//角色下方为空
				if (map[step][m_x[step][0] + 1][m_y[step][0]] == ' ' || map[step][m_x[step][0] + 1][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';

					return;
				}
				//角色下方为箱子,箱子下方为空
				if (map[step][m_x[step][0] + 1][m_y[step][0]] == 'O'&&map[step][m_x[step][0] + 2][m_y[step][0]] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] + 1][m_y[step][0]] = 'O';

					return;
				}
				//角色下方为箱子,箱子下方为箱位
				if (map[step][m_x[step][0] + 1][m_y[step][0]] == 'O'&&map[step][m_x[step][0] + 2][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] + 1][m_y[step][0]] = 'Q';

					box_num[step]--;
					return;
				}
				//推已经在箱位上的箱子，且这时它下面为箱位
				if (map[step][m_x[step][0] + 1][m_y[step][0]] == 'Q' && map[step][m_x[step][0] + 2][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] + 1][m_y[step][0]] = 'Q';

					return;
				}
				//推已经在箱位上的箱子，且这时它下面为空位
				if (map[step][m_x[step][0] + 1][m_y[step][0]] == 'Q' && map[step][m_x[step][0] + 2][m_y[step][0]] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] + 1][m_y[step][0]] = 'O';

					return;
				}
			}
		}
		else if (key == 'w')
		{
			//按下w，此时为游戏界面
			if (sence == 3)
			{
				//角色上方为空
				if (map[step][m_x[step][0] - 1][m_y[step][0]] == ' ' || map[step][m_x[step][0] - 1][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';

					return;
				}
				//角色上方为箱子,箱子上方为空
				if (map[step][m_x[step][0] - 1][m_y[step][0]] == 'O'&&map[step][m_x[step][0] - 2][m_y[step][0]] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] - 1][m_y[step][0]] = 'O';

					return;
				}
				//角色上方为箱子,箱子上方为箱位
				if (map[step][m_x[step][0] - 1][m_y[step][0]] == 'O'&&map[step][m_x[step][0] - 2][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] - 1][m_y[step][0]] = 'Q';

					box_num[step]--;
					return;
				}
				//推已经在箱位上的箱子，且这时它上面为箱位
				if (map[step][m_x[step][0] - 1][m_y[step][0]] == 'Q' && map[step][m_x[step][0] - 2][m_y[step][0]] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] - 1][m_y[step][0]] = 'Q';

					return;
				}
				//推已经在箱位上的箱子，且这时它上面为箱位
				if (map[step][m_x[step][0] - 1][m_y[step][0]] == 'Q' && map[step][m_x[step][0] - 2][m_y[step][0]] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);

					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_x[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0] - 1][m_y[step][0]] = 'O';

					return;
				}

			}
		}
		else if (key == 'a')
		{
			if (sence == 2)
			{
				if (level > 1)
				{
					level--;
					return;
				}
				else
					return;
			}
			else if (sence == 1)
			{
				sence = 3;
				level = 1;
				cleardevice();
				return;
			}
			else if (sence == 3)
			{
				//角色左边为空
				if (map[step][m_x[step][0]][m_y[step][0] - 1] == ' ' || map[step][m_x[step][0]][m_y[step][0] - 1] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';

					return;
				}
				//角色左边为箱子,箱子左边为空
				if (map[step][m_x[step][0]][m_y[step][0] - 1] == 'O'&&map[step][m_x[step][0]][m_y[step][0] - 2] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] - 1] = 'O';

					return;
				}
				//角色左边为箱子,箱子左边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] - 1] == 'O'&&map[step][m_x[step][0]][m_y[step][0] - 2] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] - 1] = 'Q';

					box_num[step]--;
					return;
				}
				//推已经在箱位上的箱子，且这时它左边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] - 1] == 'Q' && map[step][m_x[step][0]][m_y[step][0] - 2] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] - 1] = 'Q';

					return;
				}
				//推已经在箱位上的箱子，且这时它左边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] - 1] == 'Q' && map[step][m_x[step][0]][m_y[step][0] - 2] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]--;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] - 1] = 'O';

					return;
				}
			}
		}
		else if (key == 'd')
		{
			if (sence == 2)
			{
				if (level < 35)
				{
					level++;
					return;
				}
				else
					return;
			}
			else if (sence == 3)
			{
				//角色右边为空或者为箱位
				if (map[step][m_x[step][0]][m_y[step][0] + 1] == ' ' || map[step][m_x[step][0]][m_y[step][0] + 1] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';

					return;
				}
				//角色右边为箱子,箱子右边为空
				if (map[step][m_x[step][0]][m_y[step][0] + 1] == 'O'&&map[step][m_x[step][0]][m_y[step][0] + 2] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] + 1] = 'O';

					return;
				}
				//角色右边为箱子,箱子右边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] + 1] == 'O'&&map[step][m_x[step][0]][m_y[step][0] + 2] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] + 1] = 'Q';

					box_num[step]--;
					return;
				}
				//推已经在箱位上的箱子，且这时它右边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] + 1] == 'Q' && map[step][m_x[step][0]][m_y[step][0] + 2] == 'X')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] + 1] = 'Q';

					return;
				}
				//推已经在箱位上的箱子，且这时它右边为箱位
				if (map[step][m_x[step][0]][m_y[step][0] + 1] == 'Q' && map[step][m_x[step][0]][m_y[step][0] + 2] == ' ')
				{
					step++;
					for (int i = 0; i <= map_i; i++)
					{
						strcpy(map[step][i], map[step - 1][i]);
					}
					box_num[step] = box_num[step - 1];
					m_x[step][0] = m_x[step - 1][0];
					m_y[step][0] = m_y[step - 1][0];
					map[step][m_x[step][0]][m_y[step][0]] = ' ';
					m_y[step][0]++;
					map[step][m_x[step][0]][m_y[step][0]] = '@';
					map[step][m_x[step][0]][m_y[step][0] + 1] = 'O';

					return;
				}
			}
		}
		else if (key == 'r')
		{
			if (sence == 1)
			{
				sence = 0;
				return;
			}
			else if (sence == 5)
			{
				sence = 0;
				return;
			}
			else if (sence == 2)
			{
				sence = 1;
				return;
			}
			else if (sence == 6)
			{
				sence = 3;
				cleardevice();
				return;
			}
			if (sence == 3)
			{
				step = 0;
				setfillcolor(BLACK);
				bar(780, 250, 990, 280);
				return;
			}
		}
		else if (key == 'c')
		{
			if (sence == 0)
			{
				sence = 5;
				return;
			}
		}
		else if (key == 'q')
		{
			if (sence == 0 || sence == 5)
			{
				ifrun = 0;
			}
		}
		else if (key == 'u')
		{
			if (sence == 3)
			{
				if (step > 0)
					step--;
				else
					return;
			}
		}
		//游戏结束界面按下n进入下一关
		else if (key == 'n')
		{
			if (sence == 4)
			{
				next = 1;
				level++;
				box_size = 0;
				return;
			}

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
		else if (key == 'x')
		{
			if (sence == 6 || sence == 4)
			{
				sence = 2;
				return;
			}
		}
		//选关界面按下空格或回车  空格（32）回车（13）
		else if ((key == 13 || key == 32))
		{
			sence = 3;
			next = 1;
			cleardevice();
		}

		//ESC
		else if (key == 27)
		{
			if (sence == 3)
			{
				sence = 6;
				return;
			}
			else if (sence == 5)
			{
				sence = 0;
				return;
			}
			else if (sence == 6)
			{
				sence = 3;
				cleardevice();
				return;
			}
			else if (sence == 1)
			{
				sence = 0;
				return;
			}
		}
		//判定游戏结束（以箱子数为标准）
		if (sence == 3)
		{
			if (box_num[step] == 0)
			{
				sence = 4;
			}
		}
	}
}