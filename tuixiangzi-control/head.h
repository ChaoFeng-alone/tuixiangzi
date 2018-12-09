#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX_STAP 500
//函数声明

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
判定是否游戏结束
*/
void isend();

/*
貌似用不上
*/
void clean();

struct custommap
{
	char now=' ';
	int now_x = 0;
	int now_y = 0;
	int cusmap_i=0;
	int cusmap_j=0;
};