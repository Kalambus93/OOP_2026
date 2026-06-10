import std;

int Summa(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

int Prod(int number)
{
	int prod = 1;
	while (number > 0)
	{
		prod *= number % 10;
		number /= 10;
	}
	return prod;
}

bool IncreasingSequence(int number)
{
	if ((number / 100) < ((number % 100) / 10) && ((number % 100) / 10) < (number % 10))
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
	int n = 0;

	do
	{
		std::println("Привет! Пожалуйста, введите число от 100 до 999:");
		std::cin >> n;
	} while (n < 100 || n > 999);

	std::println("Сумма: {}", Summa(n));
	std::println("Произведение: {}", Prod(n));

	if (IncreasingSequence(n))
	{
		std::println("Цифры трёхзначного числа образуют возрастающую последовательность");
	}
	else
	{
		std::println("Цифры трёхзначного числа не образуют возрастающую последовательность");
	}
	return 0;
}