import std;

using namespace std;

int add_right_digit(int n, int d)
{
	n = n * 10 + d;
	return n;
}

int main()
{
	std::println("Программа добавляет цифру справа к числу");
	int n = 0;
	int d = 0;
	println("Введите n и какую цифру d добавить справа");
	cin >> n >> d;
	n = add_right_digit(n, d);
	println("{}", n);
	return 0;
}