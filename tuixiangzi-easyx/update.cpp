#include"head.h"
void LoadMap(int level, char(*map)[50]);
void update()
{
	
	extern int map_i;
	extern int map_j;
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
				for (int t = 0; t <= i; t++)
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
		//��ͼ��ȡ��ɺ󽲲�����Ϊ1
		step = 0;
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
		//���Ƿ���е�ͼ��������Ϊ��
		/*next = 0;*/
	}
}
void LoadMap(int level, char(*map)[50]) {
	extern int map_hight;
	extern int map_wide;
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
	map_hight = map_i;
	//��ȡ��ͼ������
	fscanf(fp, "%d", &map_j);
	for (int i = 0;; i++) {//ѭ����ȡ�ļ����ݣ�ֱ���ﵽ�˳�����
		fgets(map[i], 256, fp);//��ȡһ���ַ���
		map[i][strlen(map[i]) - 1] = '\0';//���ַ���ĩβ�ֶ����Ͻ�����'\0'
		if (map[i][1] == '|') {//���ַ����ڶ�λ����'|'ʱ��ʾ����Ϊ���һ�У��ļ���ȡ����
			map_i = i;/*map[i][1] = '=';*///����λ�ַ�����Ϊ'='
			break;//����ѭ��
		}
		
	}
	map_hight = (13 - map_hight) / 2;
	map_wide = (19 - map_j) / 2;
	fclose(fp);//�ر��ļ�ָ��
}
