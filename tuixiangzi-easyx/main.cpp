#include"head.h"
int map_hight, map_wide;//��Ϸ��ͼƫ��
int ifrun=1;//��������Ŀ���
int sence;//���ڴ�ų���ͼ��0Ϊ���˵���1Ϊ�Ӳ˵�1��ֱ�ӿ�ʼ��ѡ�أ���2Ϊ�Ӳ˵�2��ѡ�ؽ��棩��3Ϊ��Ϸ���棬4Ϊ��һ�ؽ��棬5Ϊ����˵�����棬6Ϊ��Ϸ��ͣ����
char key;//��������û������ֵ
int level = 1;//��¼�ؿ�
int end;//���������Ϸ�Ƿ����
int m_x[MAX_STEP][1], m_y[MAX_STEP][1];//���������������
int step;//������¼����
int next = 1;//�����ж��Ƿ���һ��
int box_num[MAX_STEP];//������¼������
int box_size;//��������λ������
char map[MAX_STEP][50][50] = { 0 };//���������Ϸ��ͼ
int boxx[10];//���ڴ����������
int boxy[10];
int box_x[10];//���ڴ����λ����
int box_y[10];//
int cont;
int map_i, map_j;//��ŵ�ͼ�ߺͿ�
int main()
{
	init();
	while (ifrun==1)
	{
		event();
		update();
		render();
		delay();
		isend();
	}
	clean();

}

