import std;

using namespace std;

int digit_sum(int n)
{
	if (n > 9)
	{
		return n % 10 + digit_sum(n / 10);
	}
	else
		return n;
}

int main()
{
	std::println("Программа находит сумму цифр числа");
	int n = 0;
	do
	{
		println("Введите натуральное число:");
		cin >> n;
	} while (n < 0);

	int a = digit_sum(n);

	std::println("Сумма цифр: {}", a);
	return 0;
}