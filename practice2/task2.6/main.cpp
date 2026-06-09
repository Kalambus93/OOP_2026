import std;

using namespace std;

int main()
{

	std::println("Программа определяет количество дней в году (обычный или високосный)");
	int year = 0;
	println("Введите номер года:");
	cin >> year;

	bool leap_year = false;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		leap_year = true;
	}

	println("Год високосный? {}", leap_year);

	return 0;
}