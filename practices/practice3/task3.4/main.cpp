import std;

using namespace std;

bool is_prime(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 0)
		{
			count++;
		}
	}

	if (count == 2)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	std::println("Программа проверяет, является ли число простым");
	int n = 0;
	println("Введите n для проверки простоты числа");
	cin >> n;
	println("Число простое? {}", is_prime(n));
	return 0;
}