#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX_STAP 500
//��������

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
�ж��Ƿ���Ϸ����
*/
void isend();

/*
ò���ò���
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