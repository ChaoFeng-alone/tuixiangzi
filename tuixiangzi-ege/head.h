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
��ʼ����Ϸ
��ӡ���˵�
�޸ı���
*/
void init();

/*
�¼��ж�
�ж��û���������
*/
void event();

/*
��������
*/
void update();

/*
���´�ӡ��Ļ
*/
void render();

/*
��ʱ
*/
void delay();


/*
��������
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