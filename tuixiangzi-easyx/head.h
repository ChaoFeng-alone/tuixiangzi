#include"graphics.h"
#include"easyx.h"
#include<stdio.h> 
#include<conio.h>
#define	LONG 1000
#define HEIGHT 600
#define MAX_STEP 500

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
结束处理
*/
void clean();
