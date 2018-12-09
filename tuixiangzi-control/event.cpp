/*
墙为#，箱子为O，箱位为X，两边界为|，填充为=
*/
#include"head.h"
void event()
{
	extern bool loadcustommap;
	extern bool savecustommap;
	extern char custommap[50][50];
	extern struct custommap custom;
	extern int end;
	extern int map_i;
	extern int box_size;
	extern int next;
	extern int stap;
	extern int box_num[MAX_STAP];
	extern int level;
	extern char key;
	extern int sence;
	extern int m_x[MAX_STAP][1];
	extern int m_y[MAX_STAP][1];
	extern char map[MAX_STAP][50][50];
	extern int stap;

	key = _getch();
	//_getch();
	key = tolower(key);

	if (key == 's')
	{
		//按下s后，如果此时为初始界面，则跳转到菜单1
		if (sence == 0)
		{
			sence = 1;
			return;
		}
		//按下s，如果此时为菜单1，则跳转到选关界面
		else if (sence == 1)
		{
			sence = 2;
			system("cls");
			printf("\n\n\n\n");
			printf("\t\t\t在自定义模式中：\n");
			printf("\t\t\t按1为左右边界\n");
			printf("\t\t\t按2为边界与墙之间的填充\n");
			printf("\t\t\t按3为墙\n");
			printf("\t\t\t按4为箱子\n");
			printf("\t\t\t按5为人\n");
			printf("\t\t\t按6为箱位\n");
			printf("\t\t\t按7为放在箱位上的箱子\n");
			printf("\t\t\t按0为空（用于清除错误填充）\n");
			printf("\t\t\t如已知晓请按任意键");
			_getch();
			_getch();
			return;

		}
		//按下s，如果此时为游戏界面
		else if (sence == 3)
		{
			//角色下方为空
			if (map[stap][m_x[stap][0] + 1][m_y[stap][0]] == ' ' || map[stap][m_x[stap][0] + 1][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i+1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';

				return;
			}
			//角色下方为箱子,箱子下方为空
			if (map[stap][m_x[stap][0] + 1][m_y[stap][0]] == 'O'&&map[stap][m_x[stap][0] + 2][m_y[stap][0]] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i+1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] + 1][m_y[stap][0]] = 'O';

				return;
			}
			//角色下方为箱子,箱子下方为箱位
			if (map[stap][m_x[stap][0] + 1][m_y[stap][0]] == 'O'&&map[stap][m_x[stap][0] + 2][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] + 1][m_y[stap][0]] = 'Q';

				box_num[stap]--;
				return;
			}
			//推已经在箱位上的箱子，且这时它下面为箱位
			if (map[stap][m_x[stap][0] + 1][m_y[stap][0]] == 'Q' && map[stap][m_x[stap][0] + 2][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] + 1][m_y[stap][0]] = 'Q';

				return;
			}
			//推已经在箱位上的箱子，且这时它下面为空位
			if (map[stap][m_x[stap][0] + 1][m_y[stap][0]] == 'Q' && map[stap][m_x[stap][0] + 2][m_y[stap][0]] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] + 1][m_y[stap][0]] = 'O';

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
			if (map[stap][m_x[stap][0] - 1][m_y[stap][0]] == ' ' || map[stap][m_x[stap][0] - 1][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';

				return;
			}
			//角色上方为箱子,箱子上方为空
			if (map[stap][m_x[stap][0] - 1][m_y[stap][0]] == 'O'&&map[stap][m_x[stap][0] - 2][m_y[stap][0]] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] - 1][m_y[stap][0]] = 'O';

				return;
			}
			//角色上方为箱子,箱子上方为箱位
			if (map[stap][m_x[stap][0] - 1][m_y[stap][0]] == 'O'&&map[stap][m_x[stap][0] - 2][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] - 1][m_y[stap][0]] = 'Q';

				box_num[stap]--;
				return;
			}
			//推已经在箱位上的箱子，且这时它上面为箱位
			if (map[stap][m_x[stap][0] - 1][m_y[stap][0]] == 'Q' && map[stap][m_x[stap][0] - 2][m_y[stap][0]] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] - 1][m_y[stap][0]] = 'Q';

				return;
			}
			//推已经在箱位上的箱子，且这时它上面为箱位
			if (map[stap][m_x[stap][0] - 1][m_y[stap][0]] == 'Q' && map[stap][m_x[stap][0] - 2][m_y[stap][0]] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);

				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_x[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0] - 1][m_y[stap][0]] = 'O';

				return;
			}

		}
	}
	else if (key == 'a')
	{
		//按下a，如果此时为菜单1，则跳转到游戏界面，并设置关卡为1
		if (sence == 1)
		{
			sence = 3;
			level = 1;
			next = 1;
		}
		else if (sence == 3)
		{
			//角色左边为空
			if (map[stap][m_x[stap][0]][m_y[stap][0] - 1] == ' ' || map[stap][m_x[stap][0]][m_y[stap][0] - 1] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';

				return;
			}
			//角色左边为箱子,箱子左边为空
			if (map[stap][m_x[stap][0]][m_y[stap][0] - 1] == 'O'&&map[stap][m_x[stap][0]][m_y[stap][0] - 2] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] - 1] = 'O';

				return;
			}
			//角色左边为箱子,箱子左边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] - 1] == 'O'&&map[stap][m_x[stap][0]][m_y[stap][0] - 2] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] - 1] = 'Q';

				box_num[stap]--;
				return;
			}
			//推已经在箱位上的箱子，且这时它左边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] - 1] == 'Q' && map[stap][m_x[stap][0]][m_y[stap][0] - 2] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] - 1] = 'Q';

				return;
			}
			//推已经在箱位上的箱子，且这时它左边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] - 1] == 'Q' && map[stap][m_x[stap][0]][m_y[stap][0] - 2] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]--;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] - 1] = 'O';

				return;
			}
		}
	}
	else if (key == 'd')
	{
		//按下d，如果为游戏界面
		if (sence == 3)
		{
			//角色右边为空或者为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] + 1] == ' ' || map[stap][m_x[stap][0]][m_y[stap][0] + 1] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';

				return;
			}
			//角色右边为箱子,箱子右边为空
			if (map[stap][m_x[stap][0]][m_y[stap][0] + 1] == 'O'&&map[stap][m_x[stap][0]][m_y[stap][0] + 2] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] + 1] = 'O';

				return;
			}
			//角色右边为箱子,箱子右边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] + 1] == 'O'&&map[stap][m_x[stap][0]][m_y[stap][0] + 2] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] + 1] = 'Q';

				box_num[stap]--;
				return;
			}
			//推已经在箱位上的箱子，且这时它右边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] + 1] == 'Q' && map[stap][m_x[stap][0]][m_y[stap][0] + 2] == 'X')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] + 1] = 'Q';

				return;
			}
			//推已经在箱位上的箱子，且这时它右边为箱位
			if (map[stap][m_x[stap][0]][m_y[stap][0] + 1] == 'Q' && map[stap][m_x[stap][0]][m_y[stap][0] + 2] == ' ')
			{
				stap++;
				for (int i = 0; i <= map_i + 1; i++)
				{
					strcpy(map[stap][i], map[stap - 1][i]);
				}
				box_num[stap] = box_num[stap - 1];
				m_x[stap][0] = m_x[stap - 1][0];
				m_y[stap][0] = m_y[stap - 1][0];
				map[stap][m_x[stap][0]][m_y[stap][0]] = ' ';
				m_y[stap][0]++;
				map[stap][m_x[stap][0]][m_y[stap][0]] = '@';
				map[stap][m_x[stap][0]][m_y[stap][0] + 1] = 'O';

				return;
			}
		}
	}
	//设置撤销功能
	else if (key == 'u')
	{
		if (sence == 3)
		{
			if (stap > 0)
				stap--;
			else
				return;
		}
	}
	//重置功能
	else if (key == 'r')
	{
		if (sence == 6)
		{
			sence = 3;
		}
		if (sence == 3)
		{
			stap = 0;
		}

	}
	//退出按钮，用于初始界面和菜单1
	else if (key == 'q')
	{
		if (sence == 0 || sence == 1 || sence == 5)
			end = 1;
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
	else if (key == 'c')
	{
		if (sence == 0)
		{
			sence = 5;
		}
	}
	else if (key == 'm')
	{
		sence = 0;
		return;
	}
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
			return;
		}

	}
	else if (key == 'x')
	{
		if (sence == 6)
		{
			sence = 2;
			return;
		}
	}
	//判定游戏结束（以箱子数为标准）
	if (sence == 3)
	{
		if (box_num[stap] == 0)
		{
			sence = 4;
		}
	}
	else if (sence == 2)
	{
		if (key == '1')
			custom.now = '|';
		else if (key == '2')
			custom.now = '=';
		else if (key == '3')
			custom.now = '#';
		else if (key == '4')
			custom.now = 'O';
		else if (key == '5')
			custom.now = '@';
		else if (key == '6')
			custom.now = 'X';
		else if (key == '7')
			custom.now = 'Q';
		else if (key == '0')
			custom.now = ' ';
		else if (key == 's')
		{
			if(custom.now_y<28)
			custom.now_y ++;
		}
		else if (key == 'w')
		{
			if (custom.now_y > 0)
				custom.now_y--;
		}
		else if (key == 'd')
		{
			if (custom.now_x < 30)
			custom.now_x++;
		}
		else if (key == 'a')
		{
			if (custom.now_x > 0)
				custom.now_x--;
		}
		else if (key == 32)
		{
			custommap[custom.now_y][custom.now_x] = custom.now;
			system("cls");

			if (custom.now_y > custom.cusmap_i)
				custom.cusmap_i = custom.now_y;
			if (custom.now_x > custom.cusmap_j)
				custom.cusmap_j = custom.now_x;
		}
		else if (key == 13)
		{
			savecustommap = true;
			loadcustommap = true;
		}
	}
	/*if (key == 'a')
	{
		sence = 3;
		level = 1;
	}*/
}