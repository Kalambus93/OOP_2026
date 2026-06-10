import std;

int main()
{
	std::println("------------------------------\n"
				 "ЛР №: 1\n"
				 "Группа: 6112-100503D\n"
				 "Автор: Трофимов Максим\n"
				 "Вариант: 28\n"
				 "Программа: подсчет элементов,\nделящихся без остатка\n"
				 "------------------------------");

	std::println("------------------------------\n"
				 "\tВвод данных\n"
				 "------------------------------");

	int divider = 0;
	do
	{
		std::println("Введите натуральный делитель:");
		std::cin >> divider;
	} while (divider <= 0);

	int quantity = 0;
	do
	{
		std::println("Введите кол-во элементов последовательности:");
		std::cin >> quantity;
	} while (quantity <= 0);

	std::println("Введите элементы последовательности:");

	int element = 0;
	int number_not_remains = 0;

	for (int i = 0; i < quantity; ++i)
	{
		std::cin >> element;
		if (element % divider == 0)
			++number_not_remains;
	}

	std::println("Количество элементов последовательности, делящихся на {} без остатка: {}", divider, number_not_remains);

	return 0;
}