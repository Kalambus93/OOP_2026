import std;

using namespace std;

int main() {
	int number = 0;
	do {
		println("Введите число от 0 до 86400");
		cin >> number;
		if (number > 86400) { println("Это число > 86400, это уже другие сутки"); }
	} while (number < 0 || number > 86400);

	number = number % 3600;
	number = number / 60;

	println("Вот сколько минут прошло с последнего часа: {}", number);

	return 0;
}