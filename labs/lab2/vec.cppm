export module vec;

import std;

export void manual_input(std::vector<int> &vector_for_using)
{

	std::println("Заполните вектор натуральными числами:");
	for (std::size_t i = 0; i < vector_for_using.size(); ++i)
	{
		std::print("Элемент №{}\t", i + 1);
		std::cin >> vector_for_using[i];

		if (vector_for_using[i] <= 0)
		{
			std::println("Вводите только натуральные числа:");
			--i;
		}
		std::println("");
	}
}

export void auto_input(std::vector<int> &vector_for_using)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 1000);

	for (std::size_t i = 0; i < vector_for_using.size(); ++i)
	{
		vector_for_using[i] = dis(gen);
	}

	std::println("");
}

export int manual_and_auto_work(const std::vector<int> &vec, int divider)
{
	int count = 0;
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] % divider == 0)
			++count;
	}
	return count;
}

export void conclusion(const std::vector<int> &vec, int numder_not_remains, int divider)
{
	std::println("Элементы последовательности:");

	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		std::print("{}\t", vec[i]);
	}

	std::println("");
	std::println("Количество: {}", vec.size());
	std::println("Делитель: {}", divider);
	std::println("Количество элементов последовательности, делящихся на {} без остатка: {}", divider, numder_not_remains);
}