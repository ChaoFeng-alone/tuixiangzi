#include"head.h"
void init()
{

	//��СΪLONG*WIDE
	initgraph(LONG, HEIGHT);
	//���ô��ڱ���
	setcaption("������EGE");
	//cls
	cleardevice();
	//����EGEͼƬָ��
	PIMAGE initmap = newimage();
	//initmap = newimage();
	//��initimgͼƬ�Ž�initmapָ��
	getimage(initmap, "resources\\image\\initimg.jpg", 0, 0);
	putimage(LONG / 2 - INITIMAGEL / 2, HEIGHT*0.1, initmap);
	//������ɫ
	setcolor(EGERGB(0x00, 0xcc, 0xff));
	//Ϊ�������ۣ��ڴ��ڱ�Ե��������
	setfillcolor(WHITE);
	bar(0, 590, 1000, 600);
	bar(0, 0, 10, 600);
	bar(990, 0, 1000, 600);
	delimage(initmap);
	setfontbkcolor(BLACK);
	//�������ֱ���ģʽΪ͸��
	setbkmode(TRANSPARENT);

	//��������
	setfont(50, 0, "��Բ");
	outtextxy(340, 290, "��ʼ��Ϸ��S��");
	outtextxy(340, 370, "����˵����C��");
	outtextxy(340, 450, "�˳���Ϸ��Q��");
	MUSIC bgm;
	bgm.OpenFile("resources\\music\\bgm.wav");
	bgm.Play(0);
	delay_fps(6000);
}