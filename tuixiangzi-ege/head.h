#include<stdio.h>
#include"ege.h"
#include"graphics.h"
#define map_nums 35
#define	LONG 1000
#define HEIGHT 600
#define MAX_STEP 500
#define INITIMAGEL 397
#define INITIMAGEH 178

/*
初始化游戏
打印主菜单
修改标题
*/
void init();

/*
事件判定
判定用户输入内容
*/
void event();

/*
变量更新
*/
void update();

/*
重新打印屏幕
*/
void render();

/*
延时
*/
void delay();


/*
结束处理
*/
void clean();

struct custommap
{
	char now = ' ';
	int now_x = 0;
	int now_y = 0;
	int cusmap_i = 0;
	int cusmap_j = 0;
};