import std;

using namespace std;

int main() {
	int n = 0;
	int k = 0;
	do {
		println("Введите номер дня года:");
		cin >> n;
		println("Введите номер недели:");
		cin >> k;
	} while (k < 1 || k > 7 || n < 1 || n > 365);
	
	int day = (k + n - 2) % 7 + 1;

	println("{}", day);

	return 0;
}