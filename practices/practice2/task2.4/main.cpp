import std;

using namespace std;

int main()
{
	std::println("Программа проверяет, образуют ли цифры трёхзначного числа возрастающую последовательность");
	int number = 0;
	do
	{
		println("Введите трехзначное число:");
		cin >> number;
	} while (number > 999 || number < 100);

	bool result = (number / 100) < ((number % 100) / 10) && ((number % 100) / 10) < (number % 10);

	println("{}", result);

	return 0;
}