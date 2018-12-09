#include"head.h"
int map_hight, map_wide;//游戏地图偏移
int ifrun=1;//程序结束的开关
int sence;//用于存放场景图，0为主菜单，1为子菜单1（直接开始或选关），2为子菜单2（选关界面），3为游戏界面，4为下一关界面，5为操作说明界面，6为游戏暂停界面
char key;//用来存放用户输入的值
int level = 1;//记录关卡
int end;//用来存放游戏是否结束
int m_x[MAX_STEP][1], m_y[MAX_STEP][1];//用来存放人物坐标
int step;//用来记录步数
int next = 1;//用来判断是否下一关
int box_num[MAX_STEP];//用来记录箱子数
int box_size;//用来做箱位计数器
char map[MAX_STEP][50][50] = { 0 };//用来存放游戏地图
int boxx[10];//用于存放箱子坐标
int boxy[10];
int box_x[10];//用于存放箱位坐标
int box_y[10];//
int cont;
int map_i, map_j;//存放地图高和宽
int main()
{
	init();
	while (ifrun==1)
	{
		event();
		update();
		render();
		delay();
		isend();
	}
	clean();

}

