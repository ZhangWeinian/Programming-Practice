#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<conio.h>

using namespace std;

class game_2048
{
private:
	//棋盘规格
	const int H = 4;

	//棋盘构造
	vector<vector<int>> board{ H, vector<int>(H, 0) };

	//次数统计
	int number = 0;

public:
	//开始
	bool begin(void);

	//读取一个数字
	int read_number(void);

	//棋盘随机落子
	void board_add(void);

	//打印棋盘
	void display_board(void);

	//移动
	int go_to(void);

	//判断输赢
	int is_win(void);
	//1,赢了
	//0,继续
	//-1,输了
};