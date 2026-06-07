import std;

using namespace std;

int invert_digit(int n) {
	int reserved = 0;
	while (n > 0) {
		reserved = (reserved * 10) + (n % 10);
		n /= 10;
	}
	return reserved;
}

int main() {
	int n = 0;
	println("Введите число");
	cin >> n;
	n = invert_digit(n);
	println("{}", n);
	return 0;
}