#include"head.h"
void init()
{
	//��ʼ��ͼ�񴰿ڴ�СΪLONG*WIDE
	initgraph(LONG, HEIGHT);
	//Ϊ�������ۣ��ڴ��ڱ�Ե��������
	setcolor(WHITE);
	bar(0, 0, 10, HEIGHT);
	bar(10, HEIGHT - 10, LONG - 10, LONG);
	bar(LONG - 10, 0, LONG, HEIGHT);
	//����ͼƬָ��
	IMAGE initmap;
	//����init.jpg
	loadimage(&initmap, "resources\\image\\init.jpg");
	//���������������ڴ��init.jpg�ĳ���
	int initl, inith;
	initl = initmap.getwidth();
	inith = initmap.getheight();
	//ʹinit.jpgλ�ھ��п��ϵ�λ��
	putimage(LONG / 2 - initl / 2, HEIGHT*0.1, &initmap);

	//��������
	settextstyle(50, 0, "����");
	settextcolor(RGB(0x00, 0xcc, 0xff));
	outtextxy(340, 290, "��ʼ��Ϸ��S��");
	outtextxy(340, 370, "����˵����C��");
	outtextxy(340, 450, "�˳���Ϸ��Q��");

}