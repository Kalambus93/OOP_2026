import std;
import vec;

int main()
{
	std::println("------------------------------\n"
				 "ЛР №: 2\n"
				 "Группа: 6112-100503D\n"
				 "Автор: Трофимов Максим\n"
				 "Вариант: 28\n"
				 "Программа: подсчет элементов,\nделящихся без остатка\n"
				 "------------------------------");

	std::println("------------------------------\n"
				 "\tВвод данных\n"
				 "------------------------------");

	int n = 0;
	while (n <= 0)
	{
		std::println("Введите количество элементов последовательности:");
		std::cin >> n;
	}

	std::vector<int> vec(n);

	int divider = 0;
	while (divider <= 0)
	{
		std::println("Введите делитель:");
		std::cin >> divider;
	}

	int write_to_vector = 0;
	while (write_to_vector != 1 && write_to_vector != 2)
	{
		std::println("\nВыберите способ заполнения вектора:\n"
					 "1. Чтобы задать вектор вручную нажмите 1\n"
					 "2. Чтобы задать вектор случайно нажмите 2");
		std::cin >> write_to_vector;
	}

	int number_not_remains = 0;

	switch (write_to_vector)
	{
	case 1:
		std::println("");
		manual_input(vec);
		number_not_remains = manual_and_auto_work(vec, divider);
		break;
	case 2:
		auto_input(vec);
		number_not_remains = manual_and_auto_work(vec, divider);
		break;
	}

	conclusion(vec, number_not_remains, divider);

	return 0;
}