#include"base.h"

int game_2048::read_number(void)
{
	int a = 0;
	char b = 0;

	do
	{
		if (scanf_s("%d", &a))
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
			puts("\t1,ʹ��W,S,A,D�����ƶ�");
			puts("\t2,��Ϸ�����а�Esc��������ǰ��Ϸ,�˻ص���ʼ�˵�\n");

			system("pause");
			return true;

		case 0:
			cout << "���˳�!" << endl;
			return false;

		default:
			cout << "\aû�ж�Ӧѡ��!��������������ѡ��" << endl;
			continue;
		}
	} while (true);
}

void game_2048::board_add(void)
{
	bool q = false;
	vector<int*>cur(0);
	srand(static_cast<unsigned int>(time(nullptr)));

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < H; j++)
		{
			if (board.at(i).at(j) == 0)
			{
				q = true;
				cur.push_back(&board.at(i).at(j));
			}
		}
	}

	if (q)
	{
		int m = rand() % (cur.size() - 1);
		*cur.at(m) = 2;
	}

	return;

}

void game_2048::display_board(void)
{
	system("cls");

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < H; j++)
		{
			cout << board.at(i).at(j) << "\t";
		}
		cout << endl << endl << endl;
	}
}

int game_2048::go_to(void)
{
	char to_where = 0;
	int exp = 0;

	do
	{
		to_where = _getch();

		switch (to_where)
		{
			//��Сдw
		case 87:
		case 119:

			//��
		//case 72:
			goto up;

			//��Сдs
		case 83:
		case 115:

			//��
		//case 80:
			goto down;

			//��Сдa
		case 65:
		case 97:

			//��
		//case 75:
			goto left;

			//��Сдd
		case 68:
		case 100:

			//��
		//case 77:
			goto right;

			//ESC
		case 27:
			for (auto& i : board)
			{
				for (auto& j : board.at(exp++))
				{
					j = 0;
				}
			}

			return -1;

		default:
			cout << "��ƥ�䰴��!����������" << endl;
			continue;
		}

	} while (true);

	//left��right�ȽϺ�д,д����������,ֻ���Ƚ�һ�и���Ϊһ��,������left(right)����
up:
	{
		vector<int> cur(0);
		vector<int> cur_(0);
		bool q = false;

		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < H; j++)
			{
				if (board.at(j).at(i) != 0)
				{
					q = true;
					break;
				}
			}

			if (q)
			{
				for (size_t j = 0; j < H; j++)
				{
					cur.push_back(board.at(j).at(i));
				}

				if (cur.at(0) == cur.at(1))
				{
					cur.at(0) *= 2;
					cur.at(1) = 0;
					q = false;
				}
				if (cur.at(1) == cur.at(2) && cur.at(1) != 0)
				{
					cur.at(1) *= 2;
					cur.at(2) = 0;
					q = false;
				}
				if (cur.at(1) == 0 && cur.at(0) == cur.at(2))
				{
					cur.at(0) *= 2;
					cur.at(2) = 0;
					q = false;
				}
				if (cur.at(2) == cur.at(3))
				{
					cur.at(2) *= 2;
					cur.at(3) = 0;
					q = false;
				}

				if (q)
				{
					int* ptr1 = nullptr;
					int* ptr2 = nullptr;

					for (size_t k = 0; q && (k + 1 < H); k++)
					{
						if (cur.at(k) == 0)
						{
							continue;
						}

						q = false;
						ptr1 = &cur.at(k);

						for (size_t l = k + 1; l < H; l++)
						{
							if (cur.at(l) == 0)
							{
								continue;
							}

							ptr2 = &cur.at(l);

							if (*ptr1 == *ptr2)
							{
								*ptr1 *= 2;
								*ptr2 = 0;
								ptr1 = ptr2 = nullptr;

								break;
							}
							else
							{
								ptr1 = ptr2;
								ptr2 = nullptr;
								continue;
							}
						}

						ptr1 = ptr2 = nullptr;
					}

					ptr1 = ptr2 = nullptr;
				}

				for (auto j : cur)
				{
					if (j == 0)
					{
						continue;
					}

					cur_.push_back(j);
				}

				cur_.resize(4, 0);

				for (size_t j = 0; j < H; j++)
				{
					board.at(j).at(i) = cur_.at(j);
				}

				cur.clear();
				cur_.clear();
				q = false;
			}
		}

		return 0;
	}

down:
	{
		vector<int> cur(0);
		bool q = false;

		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < H; j++)
			{
				if (board.at(j).at(i) != 0)
				{
					q = true;
					break;
				}
			}

			if (q)
			{
				//ע��0
				for (int j = 3; j >= 0; j--)
				{
					cur.push_back(board.at(j).at(i));
				}

				if (cur.at(0) == cur.at(1))
				{
					cur.at(0) *= 2;
					cur.at(1) = 0;
					q = false;
				}
				if (cur.at(1) == cur.at(2) && cur.at(1) != 0)
				{
					cur.at(1) *= 2;
					cur.at(2) = 0;
					q = false;
				}
				if (cur.at(1) == 0 && cur.at(0) == cur.at(2))
				{
					cur.at(0) *= 2;
					cur.at(2) = 0;
					q = false;
				}
				if (cur.at(2) == cur.at(3))
				{
					cur.at(2) *= 2;
					cur.at(3) = 0;
					q = false;
				}

				if (q)
				{
					int* ptr1 = nullptr;
					int* ptr2 = nullptr;

					for (size_t k = 0; q && (k + 1 < H); k++)
					{
						if (cur.at(k) == 0)
						{
							continue;
						}

						q = false;
						ptr1 = &cur.at(k);

						for (size_t l = k + 1; l < H; l++)
						{
							if (cur.at(l) == 0)
							{
								continue;
							}

							ptr2 = &cur.at(l);

							if (*ptr1 == *ptr2)
							{
								*ptr1 *= 2;
								*ptr2 = 0;
								ptr1 = ptr2 = nullptr;

								break;
							}
							else
							{
								ptr1 = ptr2;
								ptr2 = nullptr;
								continue;
							}
						}

						ptr1 = ptr2 = nullptr;
					}

					ptr1 = ptr2 = nullptr;
				}

				vector<int> cur_(0);
				for (auto j : cur)
				{
					if (j == 0)
					{
						continue;
					}

					cur_.push_back(j);
				}

				reverse(cur_.begin(), cur_.end());
				cur_.insert(cur_.begin(), (H - cur_.size()), 0);

				for (size_t j = 0; j < H; j++)
				{
					board.at(j).at(i) = cur_.at(j);
				}

				cur.clear();
				cur_.clear();
				q = false;
			}

		}

		return 0;
	}

left:
	{
		vector<int> cur(0);
		bool q = false;

		for (size_t i = 0; i < H; i++)
		{
			//����ĸ���ȫΪ��,��ֱ���˳�,�ж���һ��
			for (size_t j = 0; j < H; j++)
			{
				if (board.at(i).at(j) != 0)
				{
					q = true;
					break;
				}
			}

			if (q)
			{
				//1,2λ���Ƿ���ͬ
				if (board.at(i).at(0) == board.at(i).at(1))
				{
					board.at(i).at(0) *= 2;
					board.at(i).at(1) = 0;
					q = false;
				}

				//2,3λ���Ƿ���ͬ�Ҳ�����0
				if (board.at(i).at(1) == board.at(i).at(2) && board.at(i).at(1) != 0)
				{
					board.at(i).at(1) *= 2;
					board.at(i).at(2) = 0;
					q = false;
				}

				//1,3λ���Ƿ���ͬ��2λ�ò�����0
				if (board.at(i).at(1) == 0 && board.at(i).at(0) == board.at(i).at(2))
				{
					board.at(i).at(0) *= 2;
					board.at(i).at(2) = 0;
					q = false;
				}

				//3,4λ���Ƿ���ͬ�Ҳ�����0
				if (board.at(i).at(2) == board.at(i).at(3))
				{
					board.at(i).at(2) *= 2;
					board.at(i).at(3) = 0;
					q = false;
				}

				//���������������,����˫ָ�뷨
				if (q)
				{
					int* ptr1 = nullptr;
					int* ptr2 = nullptr;

					for (size_t j = 0; q && (j + 1 < H); j++)
					{
						if (board.at(i).at(j) == 0)
						{
							continue;
						}

						q = false;
						ptr1 = &board.at(i).at(j);

						for (size_t k = j + 1; k < H; k++)
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

								break;
							}
							else
							{
								ptr1 = ptr2;
								ptr2 = nullptr;
								continue;
							}
						}

						ptr1 = ptr2 = nullptr;
					}
				}

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

				q = false;
			}

		}

		return 0;
	}

	//right�Ĳ���������left����,�ʲ���׸��
right:
	{
		vector<int> cur(0);
		bool q = false;

		for (size_t i = 0; i < H; i++)
		{
			for (size_t j = 0; j < H; j++)
			{
				if (board.at(i).at(j) != 0)
				{
					q = true;
					break;
				}
			}

			if (q)
			{
				if (board.at(i).at(2) == board.at(i).at(3))
				{
					board.at(i).at(3) *= 2;
					board.at(i).at(2) = 0;
					q = false;
				}
				if (board.at(i).at(1) == board.at(i).at(2) && board.at(i).at(1) != 0)
				{
					board.at(i).at(2) *= 2;
					board.at(i).at(1) = 0;
					q = false;
				}
				if (board.at(i).at(2) == 0 && board.at(i).at(1) == board.at(i).at(3))
				{
					board.at(i).at(3) *= 2;
					board.at(i).at(1) = 0;
					q = false;
				}
				if (board.at(i).at(1) == board.at(i).at(0))
				{
					board.at(i).at(1) *= 2;
					board.at(i).at(0) = 0;
					q = false;
				}

				if (q)
				{
					int* ptr1 = nullptr;
					int* ptr2 = nullptr;

					//ע��0
					for (int j = 3; q && (j >= 0); j--)
					{
						if (board.at(i).at(j) == 0)
						{
							continue;
						}

						q = false;
						ptr1 = &board.at(i).at(j);

						//ע��0
						for (int k = j - 1; k >= 0; k--)
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

								break;
							}
							else
							{
								ptr1 = ptr2;
								ptr2 = nullptr;
								continue;
							}
						}

						ptr1 = ptr2 = nullptr;
					}
				}

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

				q = false;
			}

		}

		return 0;
	}
}

int game_2048::is_win(void)
{
	int a;
	bool q = false;

	for (size_t i = 0; i < H; i++)
	{
		for (size_t j = 0; j < H; j++)
		{
			if (board.at(i).at(j) == 2048)
			{
				cout << "\a��Ӯ��!" << endl;

				a = 1;
				return a;
			}

			if (board.at(i).at(j) == 0)
			{
				q = true;
			}
		}
	}

	if (q)
	{
		a = 0;
		return 0;
	}

	cout << "\a������!" << endl;
	system("pause");

	a = -1;
	return a;

}
