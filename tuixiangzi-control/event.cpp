/*
ǽΪ#������ΪO����λΪX�����߽�Ϊ|�����Ϊ=
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
		//����s�������ʱΪ��ʼ���棬����ת���˵�1
		if (sence == 0)
		{
			sence = 1;
			return;
		}
		//����s�������ʱΪ�˵�1������ת��ѡ�ؽ���
		else if (sence == 1)
		{
			sence = 2;
			system("cls");
			printf("\n\n\n\n");
			printf("\t\t\t���Զ���ģʽ�У�\n");
			printf("\t\t\t��1Ϊ���ұ߽�\n");
			printf("\t\t\t��2Ϊ�߽���ǽ֮������\n");
			printf("\t\t\t��3Ϊǽ\n");
			printf("\t\t\t��4Ϊ����\n");
			printf("\t\t\t��5Ϊ��\n");
			printf("\t\t\t��6Ϊ��λ\n");
			printf("\t\t\t��7Ϊ������λ�ϵ�����\n");
			printf("\t\t\t��0Ϊ�գ��������������䣩\n");
			printf("\t\t\t����֪���밴�����");
			_getch();
			_getch();
			return;

		}
		//����s�������ʱΪ��Ϸ����
		else if (sence == 3)
		{
			//��ɫ�·�Ϊ��
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
			//��ɫ�·�Ϊ����,�����·�Ϊ��
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
			//��ɫ�·�Ϊ����,�����·�Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
		//����w����ʱΪ��Ϸ����
		if (sence == 3)
		{
			//��ɫ�Ϸ�Ϊ��
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
			//��ɫ�Ϸ�Ϊ����,�����Ϸ�Ϊ��
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
			//��ɫ�Ϸ�Ϊ����,�����Ϸ�Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ������Ϊ��λ
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
		//����a�������ʱΪ�˵�1������ת����Ϸ���棬�����ùؿ�Ϊ1
		if (sence == 1)
		{
			sence = 3;
			level = 1;
			next = 1;
		}
		else if (sence == 3)
		{
			//��ɫ���Ϊ��
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
			//��ɫ���Ϊ����,�������Ϊ��
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
			//��ɫ���Ϊ����,�������Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ�����Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ�����Ϊ��λ
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
		//����d�����Ϊ��Ϸ����
		if (sence == 3)
		{
			//��ɫ�ұ�Ϊ�ջ���Ϊ��λ
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
			//��ɫ�ұ�Ϊ����,�����ұ�Ϊ��
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
			//��ɫ�ұ�Ϊ����,�����ұ�Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ���ұ�Ϊ��λ
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
			//���Ѿ�����λ�ϵ����ӣ�����ʱ���ұ�Ϊ��λ
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
	//���ó�������
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
	//���ù���
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
	//�˳���ť�����ڳ�ʼ����Ͳ˵�1
	else if (key == 'q')
	{
		if (sence == 0 || sence == 1 || sence == 5)
			end = 1;
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
	//�ж���Ϸ��������������Ϊ��׼��
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