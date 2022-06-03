#include"base.h"

int main(void)
{
	game_2048 play_game;

	do
	{
		//是否开始游戏
		if (!play_game.begin())
		{
			return 0;
		}

		//先落两子
		play_game.board_add();
		play_game.board_add();

		//打印棋盘
		play_game.display_board();

		do
		{
			//开始操作
			int num = play_game.go_to();
			if (num == -1)
			{
				break;
			}

			//随机落子
			play_game.board_add();

			system("cls");

			//打印棋盘
			play_game.display_board();

			//判断输赢
			int win = play_game.is_win();
			if (win == 1 || win == -1)
			{
				break;
			}

		} while (true);

	} while (true);

	return 0;
}
