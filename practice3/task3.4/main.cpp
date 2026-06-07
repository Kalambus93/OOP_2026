import std;

using namespace std;

bool is_prime(int n) {
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) { count++; }
	}
	
	if (count == 2) { return true; }
	else return false;
}

int main() {
	bool n = 0;
	println("Введите n для проверки простоты числа");
	cin >> n;
	n = is_prime(n);
	println("Число простое? {}", n);
	return 0;
}