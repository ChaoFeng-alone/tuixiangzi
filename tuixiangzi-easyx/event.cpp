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
	
	//kbhit���������ж��Ƿ��м������룬���У��򷵻�1����֮����0
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
				//��ɫ�·�Ϊ��
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
				//��ɫ�·�Ϊ����,�����·�Ϊ��
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
				//��ɫ�·�Ϊ����,�����·�Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
			//����w����ʱΪ��Ϸ����
			if (sence == 3)
			{
				//��ɫ�Ϸ�Ϊ��
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
				//��ɫ�Ϸ�Ϊ����,�����Ϸ�Ϊ��
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
				//��ɫ�Ϸ�Ϊ����,�����Ϸ�Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
				//��ɫ���Ϊ��
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
				//��ɫ���Ϊ����,�������Ϊ��
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
				//��ɫ���Ϊ����,�������Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ�����Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ�����Ϊ��λ
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
				//��ɫ�ұ�Ϊ�ջ���Ϊ��λ
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
				//��ɫ�ұ�Ϊ����,�����ұ�Ϊ��
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
				//��ɫ�ұ�Ϊ����,�����ұ�Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ���ұ�Ϊ��λ
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
				//���Ѿ�����λ�ϵ����ӣ�����ʱ���ұ�Ϊ��λ
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
		//��Ϸ�������水��n������һ��
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
		//ѡ�ؽ��水�¿ո��س�  �ո�32���س���13��
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
		//�ж���Ϸ��������������Ϊ��׼��
		if (sence == 3)
		{
			if (box_num[step] == 0)
			{
				sence = 4;
			}
		}
	}
}