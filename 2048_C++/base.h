#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<conio.h>

using namespace std;

class game_2048
{
private:
	//���̹��
	const int H = 4;

	//���̹���
	vector<vector<int>> board{ H, vector<int>(H, 0) };

	//����ͳ��
	int number = 0;

public:
	//��ʼ
	bool begin(void);

	//��ȡһ������
	int read_number(void);

	//�����������
	void board_add(void);

	//��ӡ����
	void display_board(void);

	//�ƶ�
	int go_to(void);

	//�ж���Ӯ
	int is_win(void);
	//1,Ӯ��
	//0,����
	//-1,����
};