#include"head.h"
//ȫ�ֱ�������
char key;//��ż��̼����ֵ
/*
�����Ϸ������0Ϊ���˵���1Ϊ�Ӳ˵�1��ֱ�ӿ�ʼ��ѡ�أ���2Ϊ�Ӳ˵�2��ѡ�ؽ��棩��3Ϊ��Ϸ���棬
4Ϊ��һ�ؽ��棬5Ϊ����˵�����棬6Ϊ��ͣ���棬7Ϊ�Զ�����档
*/
int sence;
int level=1;//��ŵڼ���
int counter;//��ʱ��
bool isend=false;
int map_high, map_wide;//��Ϸ��ͼƫ��
int ifrun = 1;//��������Ŀ���
int end;//���������Ϸ�Ƿ����
int m_x[MAX_STEP][1], m_y[MAX_STEP][1];//���������������
int step;//������¼����
int next = 0;//�����ж��Ƿ���һ��
int box_num[MAX_STEP];//������¼������
int box_size;//��������λ������
char map[MAX_STEP][50][50] = { 0 };//���������Ϸ��ͼ
int boxx[10];//���ڴ����������
int boxy[10];
int box_x[10];//���ڴ����λ����
int box_y[10];//
int cont;
int map_i, map_j;//��ŵ�ͼ�ߺͿ�
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
};//30*30�Ŀյ��Զ����ͼ

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