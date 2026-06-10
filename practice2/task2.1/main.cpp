import std;

using namespace std;

int main()
{
	std::println("Программа находит сумму и произведение цифр трёхзначного числа");
	int number = 0;
	do
	{
		println("Привет! Пожалуйста, введите число от 100 до 999:");
		cin >> number;
	} while (number < 100 || number > 999);

	int sum = 0;
	int prod = 1;

	while (number > 0)
	{
		sum += number % 10;
		prod *= number % 10;
		number /= 10;
	}

	println("Сумма: {}", sum);
	println("Произведение: {}", prod);

	return 0;
}