#include"head.h"
void init()
{
	extern char initmap[20][30];
	extern int level;
	extern int next;
	extern int sence;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���ھ��
	CONSOLE_CURSOR_INFO cci;//ʵ�л�һ������̨�����Ϣ��
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ

	system("title control1.0");//�趨��������
	system("mode con cols=120 lines=30");//�趨���ڴ�С
		system("cls");
		for (int i = 0; i < 13; i++)
			puts(initmap[i]);
	
	
}
