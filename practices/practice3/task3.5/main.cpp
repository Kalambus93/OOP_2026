import std;

using namespace std;

int fact(int n)
{
	if (n > 1)
		return n * fact(n - 1);
	else
		return 1;
}

int main()
{
	std::println("Программа вычисляет факториал натурального числа");
	int n = 0;
	do
	{
		println("Введите число, принадлежащее расширенному множеству натуральных чисел::");
		cin >> n;
	} while (n < 0);
	n = fact(n);
	println("Факториал числа: {}", n);
	return 0;
}