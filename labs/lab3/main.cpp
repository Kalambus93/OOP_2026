import std;
import ssmodule;
import delete_error;

int main()
{

	std::println("------------------------------\n"
				 "ЛР №: 3\n"
				 "Группа: 6112-100503D\n"
				 "Автор: Трофимов Максим\n"
				 "Вариант: 10\n"
				 "Программа: Последовательность\nквадратов натуральных чисел\nс произвольным целым сдвигом C\n"
				 "------------------------------");

	std::println("------------------------------\n"
				 "\tВвод данных\n"
				 "------------------------------");

	int point_menu = 0;
	int n = 0;
	std::vector<SquareSequence> sequence_vec;

	while (point_menu != 4)
	{
		std::print("Квадратные многочлены: [");
		for (std::size_t i = 0; i < sequence_vec.size(); ++i)
		{
			std::print("n² + {}", sequence_vec[i].GetFreeCoefficient());
			if (i != sequence_vec.size() - 1)
			{
				std::print(", ");
			}
		}
		std::println("]");

		std::println("Выберите пункт меню\n"
					 "1. Вставить новый квадратный многочлен в массив квадратных многочленов\n"
					 "2. Удалить квадратный многочлен\n"
					 "3. Найти последовательность с минимальным n-ым членом при заданном n\n"
					 "4. Выход из программы\n");

		do
		{
			std::cin >> point_menu;
		} while (!FailHandling());

		switch (point_menu)
		{
		case 1:
		{
			int c = 0;
			std::println("Впиши свободный коэффицент с");

			do
			{
				std::cin >> c;
			} while (!FailHandling());

			int index = 0;

			do
			{
				std::println("Впиши индекс добавляемого многочлена");

				do
				{
					std::cin >> index;
				} while (!FailHandling());

			} while (index > sequence_vec.size() || index < 0);

			sequence_vec.insert(sequence_vec.begin() + index, SquareSequence(c));

			break;
		}
		case 2:
		{
			if (sequence_vec.empty())
			{
				std::println("Нет элементов для удаления");
				break;
			}

			int index = 0;
			std::println("Впиши индекс удаляемого многочлена");

			do
			{
				std::cin >> index;
			} while (!FailHandling());

			if (index >= static_cast<int>(sequence_vec.size()) || index < 0)
			{
				std::println("Не существует многочлена с таким индексом");
				break;
			}

			sequence_vec.erase(sequence_vec.begin() + index);

			break;
		}
		case 3:
		{
			std::println("Введите n");

			do
			{
				std::cin >> n;
			} while (!FailHandling());

			int min = FindMember(sequence_vec, n);

			if (min == -1)
			{
				std::println("Нет многочленов для нахождения минимального члена");
				break;
			}
			std::println("Минимальный член последовательности равен {}² + {} = {}", n, sequence_vec[min].GetFreeCoefficient(), sequence_vec[min](n));
			break;
		}
		case 4:
		{
			std::println("Программа завершена. Всего хорошего.");
			break;
		}
		default:
		{
			std::println("Вы ввели неправильный пункт меню. Пожалуйста введите цифру заново.");
		}
		}
	}
	return 0;
}