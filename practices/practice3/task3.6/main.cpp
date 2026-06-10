import std;

using namespace std;

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

int main()
{
	std::println("Программа находит наибольший общий делитель двух чисел алгоритмом Евклида");

	int n = 0;
	int m = 0;

	do
	{
		println("Вычисление НОД. Введите натуральные n и m:");
		cin >> n >> m;
	} while (n < 0 || m < 0);

	int a = gcd(n, m);
	println("{}", a);
	return 0;
}