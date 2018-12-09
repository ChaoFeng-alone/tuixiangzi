#include"head.h"
void LoadMap(int level, char(*map)[50]);
void savecusmap();
void loadcusmap(char(*map)[50]);
void update()
{
	extern bool loadcustommap;
	extern bool savecustommap;
	extern int map_i;
	extern int map_j;
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
	//����һ����ʱ��ŵ�ͼ�Ķ�ά���飬��������LoadMap�����ĵ���
	char promap[50][50] = { 0 };
	if ((sence == 3 || sence == 4) && next == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			box_x[i] = 0;
			box_y[i] = 0;
		}
		LoadMap(level, promap);
		box_size = 0;
		box_num[0] = 0;
		for (int i = 0;; i++)
		{
			if (promap[i][1] == '|')
			{//���ַ����ڶ�λ����'|'ʱ��ʾ����Ϊ���һ�У��ļ���ȡ����
				promap[i][1] = '=';//����λ�ַ�����Ϊ'='
				for (int t = 0; t <= i+1; t++)
				{
					int j;
					//���ݴ��ͼ���Ƶ�map��ʼ��ͼ��
					for ( j = 0; j <= strlen(promap[i]); j++)
					{
						map[0][t][j] = promap[t][j];
						
					}
					map[0][t][j] = '\0';
				}
				break;//����ѭ��
			}
		}
		//��ͼ��ȡ��ɺ󽲲�����Ϊ1
		stap = 0;
		//����Ϊ��Ϸ����
		sence = 3;
		//Ѱ����������
		for (int i = 0; i < 20; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == '@')
				{
					m_x[0][0] = i;
					m_y[0][0] = t;
					break;
				}
		}
		//�������Ӹ���
		for (int i = 0; i < 20; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == 'O')
				{
					box_num[0]+=1;
					boxx[box_num[0]] = i;
					boxy[box_num[0]] = t;
				}
		}
		//ɨ���ͼ�����ӵ�λ�ú���ľ����¼
		for (int i = 0; i < 50; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == 'X'|| map[0][i][t] == 'Q')
				{
					box_size++;
					box_x[box_size] = i;
					box_y[box_size] = t;
				}
		}
		//���Ƿ���е�ͼ��������Ϊ��
		next = 0;
	}
	else if (sence == 2 && savecustommap == true)
	{
		savecusmap();
		savecustommap = false;
	}
	else if (sence == 2 && loadcustommap == true)
	{
		loadcusmap(promap);
		loadcustommap = false;
		box_size = 0;
		box_num[0] = 0;
		for (int i = 0;; i++)
		{
			if (promap[i][1] == '|')
			{//���ַ����ڶ�λ����'|'ʱ��ʾ����Ϊ���һ�У��ļ���ȡ����
				promap[i][1] = '=';//����λ�ַ�����Ϊ'='
				for (int t = 0; t <= i+1; t++)
				{
					int j;
					//���ݴ��ͼ���Ƶ�map��ʼ��ͼ��
					for (j = 0; j <= strlen(promap[i]); j++)
					{
						map[0][t][j] = promap[t][j];

					}
					map[0][t][j] = '\0';
				}
				break;//����ѭ��
			}
		}
		//��ͼ��ȡ��ɺ󽲲�����Ϊ0
		stap = 0;
		//����Ϊ��Ϸ����
		sence = 3;
		//Ѱ����������
		for (int i = 0; i < 20; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == '@')
				{
					m_x[0][0] = i;
					m_y[0][0] = t;
					break;
				}
		}
		//�������Ӹ���
		for (int i = 0; i < 20; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == 'O')
				{
					box_num[0] += 1;
					boxx[box_num[0]] = i;
					boxy[box_num[0]] = t;
				}
		}
		//ɨ���ͼ�����ӵ�λ�ú���ľ����¼
		for (int i = 0; i < 50; i++)
		{
			for (int t = 0; map[0][i][t] != '\0'; t++)
				if (map[0][i][t] == 'X' || map[0][i][t] == 'Q')
				{
					box_size++;
					box_x[box_size] = i;
					box_y[box_size] = t;
				}
		}
	}
}
void LoadMap(int level, char(*map)[50]) {
	extern int map_i;
	extern int map_j;
	char buffer[256];//�ַ��������������ڴ�Źؿ��ļ�·��
	FILE *fp;//���ڴ򿪹ؿ��ļ����ļ�ָ��
	sprintf(buffer, "data\\Map\\%d.txt", level);//ͨ��sprintf������ʽ���ļ�·��Ϊ����Ҫ��ȡ���ļ�
	if ((fp = fopen(buffer, "r")) == NULL)
	{
		printf("Could't found the map file");
		system("pause");
		exit(1);
	}
	//��ȡ��ͼ������
	fscanf(fp, "%d", &map_i);
	//��ȡ��ͼ������
	fscanf(fp, "%d", &map_j);
	for (int i = 0;; i++) {//ѭ����ȡ�ļ����ݣ�ֱ���ﵽ�˳�����
		fgets(map[i], 256, fp);//��ȡһ���ַ���
		map[i][strlen(map[i]) - 1] = '\0';//���ַ���ĩβ�ֶ����Ͻ�����'\0'
		if (map[i][1] == '|') {//���ַ����ڶ�λ����'|'ʱ��ʾ����Ϊ���һ�У��ļ���ȡ����
			//map_i = i;/*map[i][1] = '=';*///����λ�ַ�����Ϊ'='
			break;//����ѭ��
		}
	}
	fclose(fp);//�ر��ļ�ָ��
}

void savecusmap()
{
	extern char custommap[50][50];
	extern struct custommap custom;
	custom.cusmap_i += 2;
	custom.cusmap_j += 2;
	for (int t = 0; t < custom.cusmap_j; t++)
	{
		custommap[0][t] = '=';
		custommap[custom.cusmap_i][t] = '=';
	}
	custommap[0][0] = '|';
	custommap[0][custom.cusmap_j] = '|';
	custommap[custom.cusmap_i][0] = '|';
	custommap[custom.cusmap_i][custom.cusmap_j] = '|';
	for (int i = 0; i < custom.cusmap_i; i++)
	{
		custommap[i][0] = '|';
		custommap[i][custom.cusmap_j] = '|';
	}
	for (int i = 0; i < custom.cusmap_i; i++)
	{
		for (int t = 1; t < custom.cusmap_j; t++)
		{
			if (custommap[i][t] == '|' || custommap[i][t] == '#')
			{
				break;
			}
			else
			{
				custommap[i][t] = '=';
			}
		}
	}
	for (int i = 0; i < custom.cusmap_i; i++)
	{
		for (int t = custom.cusmap_j; t > 0; t--)
		{
			if (custommap[i][t] == '|' || custommap[i][t] == '#')
			{
				break;
			}
			else
			{
				custommap[i][t] = '=';
			}
		}
	}
	custommap[custom.cusmap_i][1] = '|';
	FILE *p;
	int n;
	char numbers[50];
	sprintf(numbers, "data\\Map\\custom.txt");
	if ((p = fopen(numbers, "w+")) == NULL)
		printf("sorry");
	fprintf(p, "%d %d\n", custom.cusmap_i, custom.cusmap_j + 1);
	for (int t = 0; t <= custom.cusmap_i; t++)
	{
		custommap[t][custom.cusmap_j + 1] = '\0';
		fputs(custommap[t], p);
		fprintf(p, "\n");
	}
	fclose(p);

}
void loadcusmap(char(*map)[50])
{
	extern int map_i;
	extern int map_j;
	extern int level;
	map_i = 0;
	map_j = 0;
	char buffer[256];
	FILE *fp;
	sprintf(buffer, "data\\Map\\custom.txt");
	if ((fp = fopen(buffer, "r")) == NULL)
	{
		printf("Could't found the map file");
		system("pause");
		exit(1);
	}
	//��ȡ��ͼ������
	fscanf(fp, "%d", &map_i);
	//��ȡ��ͼ������
	fscanf(fp, "%d", &map_j);
	for (int i = 0;; i++) {//ѭ����ȡ�ļ����ݣ�ֱ���ﵽ�˳�����
		fgets(map[i], 256, fp);//��ȡһ���ַ���
		map[i][strlen(map[i]) - 1] = '\0';//���ַ���ĩβ�ֶ����Ͻ�����'\0'
		if (map[i][1] == '|') {//���ַ����ڶ�λ����'|'ʱ��ʾ����Ϊ���һ�У��ļ���ȡ����
			//map_i = i;/*map[i][1] = '=';*///����λ�ַ�����Ϊ'='
			break;//����ѭ��
		}
	}
	fclose(fp);
}