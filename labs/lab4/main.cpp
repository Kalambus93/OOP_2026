import std;
import sequence;
import squares;
import factorial;
import delete_error;
import helping_for_read;
import min_sequence;

int main()
{

	std::println("-----------------------------------\n"
				 "\tЛР №: 4\n"
				 "\tГруппа: 6112\n"
				 "\tАвтор: Трофимов Максим\n"
				 "\tВариант: 10\n"
				 "-----------------------------------");

	std::println("-----------------------------------\n"
				 "\tВвод данных\n"
				 "-----------------------------------");

	int point_menu = 0;
	std::vector<std::shared_ptr<Sequence>> sequences;

	while (point_menu != 6)
	{

		std::println("\nВыберите пункт меню\n"
					 "1. Вставка нового элемента в контейнер\n"
					 "2. Удаление элемента из контейнера\n"
					 "3. Вывод содержимого контейнера\n"
					 "4. Вычисление n-го элемента последовательности при заданном n\n"
					 "5. Поиск последовательности с минимальным n-ым членом при заданном n\n"
					 "6. Выход из программы");

		do
		{
			std::cin >> point_menu;
		} while (!FailHandling());

		int index = 0;
		int type = 0;
		int n = 0;
		int c = 0;

		switch (point_menu)
		{
		case 1:
		{
			std::println("\nВставка нового элемента в контейнер");
			IndexForInsert(index, sequences);
			Type(type);

			switch (type)
			{

			case 1:
			{
				Ratio(c);
				sequences.insert(sequences.begin() + index, std::make_shared<Squares>(c));
				break;
			}

			case 2:
			{
				sequences.insert(sequences.begin() + index, std::make_shared<Factorial>());
				break;
			}
			}
			break;
		}

		case 2:
		{
			std::println("\nУдаление элемента из контейнера");

			if (!EmptyVector(sequences))
			{
				break;
			}

			ContainerPrint(sequences);
			std::println("\nВведите индекс удаляемого объекта");
			Index(index, sequences);
			sequences.erase(sequences.begin() + index);

			break;
		}

		case 3:
		{
			std::println("\nВывод содержимого контейнера\n");
			ContainerPrint(sequences);
			break;
		}

		case 4:
		{
			std::println("\nВычисление n-го элемента последовательности при заданном n\n");

			if (!EmptyVector(sequences))
			{
				break;
			}

			NaturalNumber(n);
			std::println("Выберите, в какой объект Вы хотите вставить значение n = {}. Укажите индекс", n);
			Index(index, sequences);

			std::println("Вы вставили n = {} в многочлен {}, => Ответ: {}", n, sequences[index]->to_string(), (*sequences[index])(n));

			break;
		}

		case 5:
		{
			std::println("\nПоиск последовательности с минимальным n-ым членом при заданном n\n");

			if (!EmptyVector(sequences))
			{
				break;
			}

			NaturalNumber(n);

			std::println("Поиск последовательности с минимальным n-ым членом при заданном n в квадратных многочленах");
			auto temp = SearchMinSequence(sequences, n);
			std::println("Минимальная последовательность: {}", temp->to_string());
			std::println("Значение при n = {}: {}", n, (*temp)(n));
			break;
		}

		case 6:
		{
			std::println("До свидания!");
		}
		}
	}
	return 0;
}