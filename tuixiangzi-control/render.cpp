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
	system("cls");//��������
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
		printf("       --------------��%d��--------------\n",level);
		printf("      ||           ������%3d           ||\n", stap);
		printf("      ||     ������U��    ���ã�R��    ||\n");
		printf("      || ����������%2d   ʣ����������%2d ||\n", box_num[0], box_num[stap]);
		printf("       ---------------------------------\n");
		//�ú��������ǽ���궨λ��gotoxy(x,y)�е�xy����Ӧע�⣺��x�Ǻ���y������
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
		printf("\t\t\t\t\t\t ��ϲͨ��\n");
		printf("\t\t\t\t\t\t ������%d\n", stap);
		printf("\t\t\t\t\t\t��һ�أ�N��\n");
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
		printf("\t\t\t\t\t\t ��%2d��\n",level);
		printf("\t\t\t\t\t\t������ESC��\n");
		printf("\t\t\t\t   �Զ��壨X��   ���棨R��   ���˵���M��\n");
		printf("\n\n\t\t\t\t\t\t����˵��\n");
		printf("\t\t\t\t\t�ֱ�ʹ��wsad�����������ƶ�\n");
		printf("\t\t\t\t\t@����   O������    X���յ�\n");
	}
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}
//---------------------
//���ߣ�radjedef
//��Դ��CSDN
//ԭ�ģ�https ://blog.csdn.net/radjedef/article/details/79028329 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�