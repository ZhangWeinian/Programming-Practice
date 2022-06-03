#include"base.h"

int main(void)
{
	game_2048 play_game;

	do
	{
		//�Ƿ�ʼ��Ϸ
		if (!play_game.begin())
		{
			return 0;
		}

		//��������
		play_game.board_add();
		play_game.board_add();

		//��ӡ����
		play_game.display_board();

		do
		{
			//��ʼ����
			int num = play_game.go_to();
			if (num == -1)
			{
				break;
			}

			//�������
			play_game.board_add();

			system("cls");

			//��ӡ����
			play_game.display_board();

			//�ж���Ӯ
			int win = play_game.is_win();
			if (win == 1 || win == -1)
			{
				break;
			}

		} while (true);

	} while (true);

	return 0;
}
