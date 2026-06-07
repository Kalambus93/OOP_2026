import std;

class Fraction {
private:
	int _numerator = 0;
	int _denominator = 0;

	void normalize() {
		if (_denominator == 0) {
			_denominator = 1;
		}

		if (_numerator == 0) {
			_denominator = 0;
		}

		if (_denominator < 0) {
			_denominator = std::abs(_denominator);
		}

		int gcd_number = std::gcd(_numerator, _denominator);
		_numerator = _numerator / gcd_number;
		_denominator = _denominator / gcd_number;
	}
public:

	Fraction(int numerator) {
		_numerator = numerator;

		normalize();
	}

	Fraction(int numerator, int denominator) {
		_numerator = numerator;
		_denominator = denominator;

		normalize();
	}

	int get_numerator() const{
		return _numerator;
	}

	int get_denominator() const{
		return _denominator;
	}
};

Fraction operator+(Fraction fr1, Fraction fr2) {
	int sum_numerator = fr1.get_numerator() * fr2.get_denominator() + fr1.get_denominator() * fr2.get_numerator();
	int sum_denominator = fr1.get_denominator() * fr2.get_denominator();

	Fraction result(sum_numerator, sum_denominator);

	return result;
}

Fraction operator-(Fraction fr1, Fraction fr2) {
	int dif_numerator = fr1.get_numerator() * fr2.get_denominator() - fr1.get_denominator() * fr2.get_numerator();
	int dif_denominator = fr1.get_denominator() * fr2.get_denominator();

	Fraction result(dif_numerator, dif_denominator);

	return result;
}

Fraction operator* (Fraction fr1, Fraction fr2) {
	int mult_numerator = fr1.get_numerator() * fr2.get_numerator();
	int mult_denominator = fr1.get_denominator() * fr2.get_denominator();

	Fraction result(mult_numerator, mult_denominator);

	return result;
}

std::string to_string(Fraction fr) {
	return std::format("{}/{}", fr.get_numerator(), fr.get_denominator());
}

int main() {
	int n = 0;
	int d = 0;

	std::println("Введите первую дробь:");
	std::cin >> n >> d;
	Fraction fr_1(n, d);

	std::println("Введите вторую дробь:");
	std::cin >> n >> d;
	Fraction fr_2(n, d);

	std::println("Выберите операцию:");
	std::string op;
	std::cin >> op;

	if (op == "+") {
		Fraction res_sum = fr_1 + fr_2;
		std::println("{}+{}={}", to_string(fr_1), to_string(fr_2), to_string(res_sum));
	}
	if (op == "-") {
		Fraction res_dif = fr_1 - fr_2;
		std::println("{}-{}={}", to_string(fr_1), to_string(fr_2), to_string(res_dif));
	}
	if (op == "*") {
		Fraction res_mult = fr_1 + fr_2;
		std::println("{}+{}={}", to_string(fr_1), to_string(fr_2), to_string(res_mult));
	}

	return 0;
}