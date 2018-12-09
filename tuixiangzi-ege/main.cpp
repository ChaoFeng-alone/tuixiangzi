#include"head.h"
//全局变量申明
char key;//存放键盘键入的值
/*
存放游戏场景，0为主菜单，1为子菜单1（直接开始或选关），2为子菜单2（选关界面），3为游戏界面，
4为下一关界面，5为操作说明界面，6为暂停界面，7为自定义界面。
*/
int sence;
int level=1;//存放第几关
int counter;//计时器
bool isend=false;
int map_high, map_wide;//游戏地图偏移
int ifrun = 1;//程序结束的开关
int end;//用来存放游戏是否结束
int m_x[MAX_STEP][1], m_y[MAX_STEP][1];//用来存放人物坐标
int step;//用来记录步数
int next = 0;//用来判断是否下一关
int box_num[MAX_STEP];//用来记录箱子数
int box_size;//用来做箱位计数器
char map[MAX_STEP][50][50] = { 0 };//用来存放游戏地图
int boxx[10];//用于存放箱子坐标
int boxy[10];
int box_x[10];//用于存放箱位坐标
int box_y[10];//
int cont;
int map_i, map_j;//存放地图高和宽
struct custommap custom;

bool savecustommap = false;
bool loadcustommap = false;
char custommap[50][50] = {
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
	"                              ",
};//30*30的空的自定义地图

int main()
{
	init();
	for (;!isend;delay_fps(6000000))
	{
		event();
		update();
		render();
		delay();
	}
	clean();
	return 0;
}