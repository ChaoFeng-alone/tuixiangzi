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
	//定义一个暂时存放地图的二维数组，方便后面的LoadMap函数的调用
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
			{//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
				promap[i][1] = '=';//将该位字符设置为'='
				for (int t = 0; t <= i; t++)
				{
					int j;
					//把暂存地图复制到map初始地图中
					for (j = 0; j <= strlen(promap[i]); j++)
					{
						map[0][t][j] = promap[t][j];

					}
					map[0][t][j] = '\0';
				}
				break;//跳出循环
			}
		}
		//地图读取完成后讲步数设为1
		step = 0;
		//设置为游戏界面
		sence = 3;
		//寻找人物坐标
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
		//计算箱子个数
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
		//扫描地图中箱子的位置和树木并记录
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
		//将是否进行地图导入设置为否
		/*next = 0;*/
	}
}
void LoadMap(int level, char(*map)[50]) {
	extern int map_hight;
	extern int map_wide;
	extern int map_i;
	extern int map_j;
	char buffer[256];//字符串缓冲区，用于存放关卡文件路径
	FILE *fp;//用于打开关卡文件的文件指针
	sprintf(buffer, "data\\Map\\%d.txt", level);//通过sprintf函数格式化文件路径为我们要读取的文件
	if ((fp = fopen(buffer, "r")) == NULL)
	{
		printf("Could't found the map file");
		system("pause");
		exit(1);
	}
	//读取地图的行数
	fscanf(fp, "%d", &map_i);
	map_hight = map_i;
	//读取地图的列数
	fscanf(fp, "%d", &map_j);
	for (int i = 0;; i++) {//循环读取文件内容，直到达到退出条件
		fgets(map[i], 256, fp);//读取一行字符串
		map[i][strlen(map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'
		if (map[i][1] == '|') {//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
			map_i = i;/*map[i][1] = '=';*///将该位字符设置为'='
			break;//跳出循环
		}
		
	}
	map_hight = (13 - map_hight) / 2;
	map_wide = (19 - map_j) / 2;
	fclose(fp);//关闭文件指针
}
