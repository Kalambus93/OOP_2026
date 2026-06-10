import std;

using namespace std;

int main()
{
	std::println("Программа выводит строковое описание целого числа от 1 до 999");

	int number = 0;

	do
	{
		println("Введите натуральное число:");
		cin >> number;
	} while (number > 999 || number < 1);

	if (number % 2 == 0)
	{
		println("Число четное");
	}
	else
	{
		println("Число нечетное");
	}

	return 0;
}