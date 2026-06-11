export module helping_for_read;

import std;
import delete_error;
import sequence;

export void Index(int &index, const std::vector<std::shared_ptr<Sequence>> &sqnc)
{
	do
	{
		do
		{
			std::println("\nВведите индекс");
			std::cin >> index;
		} while (!FailHandling());

		if ((index < 0) || index >= static_cast<int>(sqnc.size()))
		{
			std::println("По правилам здравого смысла:\n"
						 "1. Нельзя выбрать отрицательный индекс\n"
						 "2. Индекс должен быть меньше размера массива (0-{})",
						 std::to_string(sqnc.size() - 1));
		}
	} while ((index < 0) || index >= static_cast<int>(sqnc.size()));
}

export void IndexForInsert(int &index, const std::vector<std::shared_ptr<Sequence>> &sqnc)
{
	do
	{
		do
		{
			std::println("\nВведите индекс для вставки");
			std::cin >> index;
		} while (!FailHandling());

		if ((index < 0) || index > static_cast<int>(sqnc.size()))
		{
			std::println("По правилам здравого смысла:\n"
						 "1. Нельзя выбрать отрицательный индекс\n"
						 "2. Индекс вставки должен быть от 0 до {}",
						 std::to_string(sqnc.size()));
		}
	} while ((index < 0) || index > static_cast<int>(sqnc.size()));
}

export void Type(int &type)
{
	do
	{
		do
		{
			std::println("\nВведите тип объекта");
			std::println("1. Квадратный многочлен\n"
						 "2. Факториал");
			std::cin >> type;
		} while (!FailHandling());

		if ((type != 1 && type != 2))
		{
			std::println("Вы ввели неверный тип. Пожалуйста, введите корректное значение");
		}
	} while (type != 1 && type != 2);
}

export void Ratio(int &c)
{
	do
	{
		std::println("Введите коэффицент");
		std::cin >> c;
	} while (!FailHandling());
}

export void NaturalNumber(int &n)
{
	do
	{
		do
		{
			std::println("Введите n");
			std::cin >> n;
		} while (!FailHandling());

		if (n <= 0)
		{
			std::println("Вы ввели ненатуральное число n");
		}
	} while (n <= 0);
}

export void ContainerPrint(const std::vector<std::shared_ptr<Sequence>> &sqnc)
{
	std::print("Квадратные многочлены:[");
	for (std::size_t i = 0; i < sqnc.size(); ++i)
	{
		std::print("{}", sqnc[i]->to_string());
		if (i != sqnc.size() - 1)
		{
			std::print(",");
		}
	}
	std::println("]");
}