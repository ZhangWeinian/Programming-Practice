#include"base.h"

int game_2048::read_number(void)
{
	int a = 0;
	char b = 0;

	do
	{
		if (scanf_s("%d",&a))
		{
			return a;
		}
		else
		{
			cout << "\a�����ַ���������!����������" << endl;
			while ((b = getchar()) != '\n' && b != EOF);

			continue;
		}
	} while (true);
}

bool game_2048::begin(void)
{
	system("cls");

	puts("***************************");
	puts("           ��ѡ��");
	puts("       1,PLAY GAME!");
	puts("       0,EXIT GAME!");
	puts("***************************");
	puts("����������ѡ��:");

	do
	{
		int a = read_number();

		switch (a)
		{
		case 1:
			system("cls");

			cout << "��Ϸ��ʼ!" << endl << endl;
			puts("��ע��:");
			puts("\t1,ʹ��W,S,A,D������,��,��,�ҿ����ƶ�");
			puts("\t2,��Ϸ�����а�Esc��������ǰ��Ϸ,�˻ص���ʼ�˵�\n");

			system("pause");
			return true;

		case 0:
			cout << "\a���˳�!" << endl;
			return false;

		default:
			cout << "\aû�ж�Ӧѡ��!������ѡ��:" << endl;
			continue;
		}
	} while (true);
}

void game_2048::board_add(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	do
	{
		int m = rand() % 4;
		int n = rand() % 4;

		if (board.at(m).at(n) != 0)
		{
			continue;
		}
		else
		{
			board.at(m).at(n) = 2;
			break;
		}
	} while (true);
}

void game_2048::display_board(void)
{
	system("cls");

	for(size_t i = 0; i < H; ++i)
	{
		for(size_t j = 0; j < H; ++j)
		{
			cout << board.at(i).at(j) << "\t";
		}
		cout << endl << endl << endl;
	}
}

int game_2048::go_to(void)
{
	char to_where = 0;

	do
	{
		to_where = _getch();

		switch (to_where)
		{
			//��Сдw
		case 87:
		case 119:
			//��
		case 72:
			++number;
			goto up;

			//��Сдs
		case 83:
		case 115:
			//��
		case 80:
			++number;
			goto down;

			//��Сдa
		case 65:
		case 97:
			//��
		case 75:
			++number;
			goto left;

			//��Сдd
		case 68:
		case 100:
			//��
		case 77:
			++number;
			goto right;

			//ESC
		case 27:
			return -1;

		default:
			cout << "��ƥ�䰴��!����������" << endl;
			continue;
		}

		return 0;
	} while (true);

up:
	{
		vector<int> cur(0);
		bool q = true;
		bool p = true;

		for(size_t i = 0; i < H; ++i)
		{
			for(size_t j = 0; j < H; ++j)
			{
				cur.push_back(board.at(j).at(i));
			}

			if(cur.at(0) == cur.at(1))
			{
				cur.at(0) *= 2;
				cur.at(1) = 0;
				q = false;
			}
			if(cur.at(1) == cur.at(2))
			{
				cur.at(1) *= 2;
				cur.at(2) = 0;
				q = false;
			}
			if(cur.at(2) == cur.at(3))
			{
				cur.at(2) *= 2;
				cur.at(3) = 0;
				q = false;
			}

			if(q)
			{
				int *ptr1 = nullptr;
				int *ptr2 = nullptr;

				for(size_t k = 0; p && (k + 1 < H); ++k)
				{
					if(cur.at(k) == 0)
					{
						continue;
					}

					ptr1 = &cur.at(k);

					for(size_t l = k + 1; l < H; ++l)
					{
						if(cur.at(l) == 0)
						{
							continue;
						}

						ptr2 = &cur.at(l);

						if(*ptr1 == *ptr2)
						{
							*ptr1 *= 2;
							*ptr2 = 0;
							ptr1 = ptr2 = nullptr;
							p = false;

							break;
						}
						else
						{
							p = false;
							break;
						}
					}

					ptr1 = ptr2 = nullptr;
				}

				ptr1 = ptr2 = nullptr;
			}

			vector<int> cur_(0);
			for(auto j : cur)
			{
				if(j == 0)
				{
					continue;
				}

				cur_.push_back(j);
			}

			cur_.resize(4, 0);

			for(size_t j = 0; j < H; ++j)
			{
				board.at(j).at(i) = cur_.at(j);
			}

			cur.clear();
			cur_.clear();
			p = q = true;
		}

		return 0;
	}

down:
	{
		vector<int> cur(0);
		bool q = true;
		bool p = true;

		for(size_t i = 0; i < H; ++i)
		{
			for(int j = 3; j >= 0; --j)
			{
				cur.push_back(board.at(j).at(i));
			}

			if(cur.at(0) == cur.at(1))
			{
				cur.at(0) *= 2;
				cur.at(1) = 0;
				q = false;
			}
			if(cur.at(1) == cur.at(2))
			{
				cur.at(1) *= 2;
				cur.at(2) = 0;
				q = false;
			}
			if(cur.at(2) == cur.at(3))
			{
				cur.at(2) *= 2;
				cur.at(3) = 0;
				q = false;
			}

			if(q)
			{
				int *ptr1 = nullptr;
				int *ptr2 = nullptr;

				for(size_t k = 0; p && (k + 1 < H); ++k)
				{
					if(cur.at(k) == 0)
					{
						continue;
					}

					ptr1 = &cur.at(k);

					for(size_t l = k + 1; l < H; ++l)
					{
						if(cur.at(l) == 0)
						{
							continue;
						}

						ptr2 = &cur.at(l);

						if(*ptr1 == *ptr2)
						{
							*ptr1 *= 2;
							*ptr2 = 0;
							ptr1 = ptr2 = nullptr;
							p = false;

							break;
						}
						else
						{
							p = false;
							break;
						}
					}

					ptr1 = ptr2 = nullptr;
				}

				ptr1 = ptr2 = nullptr;
			}

			vector<int> cur_(0);
			for(auto j : cur)
			{
				if(j == 0)
				{
					continue;
				}

				cur_.push_back(j);
			}

			reverse(cur_.begin(), cur_.end());
			cur_.insert(cur_.begin(), (H - cur_.size()), 0);

			for(size_t j = 0; j < H; ++j)
			{
				board.at(j).at(i) = cur_.at(j);
			}

			cur.clear();
			cur_.clear();
			p = q = true;
		}
		return 0;
	}

left:
	{
		for (int i = 0; i < H; ++i)
		{
			bool q = true;
			bool p = true;

			if (board.at(i).at(0) == board.at(i).at(1))
			{
				board.at(i).at(0) *= 2;
				board.at(i).at(1) = 0;
				q = false;
			}
			if (board.at(i).at(1) == board.at(i).at(2))
			{
				board.at(i).at(1) *= 2;
				board.at(i).at(2) = 0;
				q = false;
			}
			if (board.at(i).at(2) == board.at(i).at(3))
			{
				board.at(i).at(2) *= 2;
				board.at(i).at(3) = 0;
				q = false;
			}

			if (q)
			{
				int* ptr1 = nullptr;
				int* ptr2 = nullptr;

				for (size_t j = 0; p && (j + 1 < H); ++j)
				{
					if (board.at(i).at(j) == 0)
					{
						continue;
					}

					ptr1 = &board.at(i).at(j);

					for (size_t k = j + 1; k < H; ++k)
					{
						if (board.at(i).at(k) == 0)
						{
							continue;
						}

						ptr2 = &board.at(i).at(k);

						if (*ptr1 == *ptr2)
						{
							*ptr1 *= 2;
							*ptr2 = 0;
							ptr1 = ptr2 = nullptr;
							p = false;

							break;
						}
						else
						{
							p = false;
							break;
						}
					}

					ptr1 = ptr2 = nullptr;
				}
			}

			vector<int> cur(0);
			for (auto j : board.at(i))
			{
				if (j == 0)
				{
					continue;
				}

				cur.push_back(j);
			}

			cur.resize(4, 0);
			board.at(i) = cur;
			cur.clear();
		}

		return 0;
	}

right:
	{
		for (int i = 0; i < H; ++i)
		{
			bool q = true;
			bool p = true;

			if (board.at(i).at(2) == board.at(i).at(3))
			{
				board.at(i).at(3) *= 2;
				board.at(i).at(2) = 0;
				q = false;
			}
			if (board.at(i).at(1) == board.at(i).at(2))
			{
				board.at(i).at(2) *= 2;
				board.at(i).at(1) = 0;
				q = false;
			}
			if (board.at(i).at(0) == board.at(i).at(1))
			{
				board.at(i).at(1) *= 2;
				board.at(i).at(0) = 0;
				q = false;
			}

			if (q)
			{
				int* ptr1 = nullptr;
				int* ptr2 = nullptr;

				for (size_t j = H - 1; p && (j >= 0); --j)
				{
					if (board.at(i).at(j) == 0)
					{
						continue;
					}

					ptr1 = &board.at(i).at(j);

					for (size_t k = j + 1; k < H; ++k)
					{
						if (board.at(i).at(k) == 0)
						{
							continue;
						}

						ptr2 = &board.at(i).at(k);

						if (*ptr1 == *ptr2)
						{
							*ptr1 *= 2;
							*ptr2 = 0;
							ptr1 = ptr2 = nullptr;
							p = false;

							break;
						}
						else
						{
							p = false;
							break;
						}
					}

					ptr1 = ptr2 = nullptr;
				}
			}

			vector<int> cur(0);
			for (auto j : board.at(i))
			{
				if (j == 0)
				{
					continue;
				}

				cur.push_back(j);
			}

			cur.insert(cur.begin(), (H - cur.size()), 0);
			board.at(i) = cur;
			cur.clear();
		}

		return 0;
	}
}

int game_2048::is_win(void)
{
	if (number < 12)
	{
		return 0;
	}

	int a;

	for (size_t i = 0; i < H; ++i)
	{
		for (size_t j = 0; j < H; ++j)
		{

			if (board.at(i).at(j) == 2048)
			{
				cout << "��Ӯ��!" << endl;

				a = 1;
				return a;
			}

			if (board.at(i).at(j) == 0)
			{
				a = 0;
				return a;
			}
		}
	}

	cout << "������!" << endl;

	a = -1;
	return a;

}
