import std;

using namespace std;

int main() {
	int number = 0;
	do {
		println("Hello! Please enter a number from 100 to 999:");
		cin >> number;
	} while (number < 100 || number > 999);

	int sum = 0;
	int prod = 1;

	while (number > 0) {
		sum += number % 10;
		prod *= number % 10;
		number /= 10;
	}

	println("Summa: {}", sum);
	println("Product: {}", prod);

	return 0;
}