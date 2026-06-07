import std;

class Fraction {
private:
	int _numerator = 0;
	int _denominator = 1;

	void normalize() {
		if (_denominator == 0) {
			_denominator = 1;
		}

		if (_numerator == 0) {
			_denominator = 1;
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

	Fraction& operator+=(const Fraction& fr) {
		_numerator = _numerator * fr.get_denominator() + _denominator * fr.get_numerator();
		_denominator = _denominator * fr.get_denominator();
		return *this;
	}

	Fraction& operator-=(const Fraction& fr) {
		_numerator = _numerator * fr.get_denominator() - _denominator * fr.get_numerator();
		_denominator = get_denominator() * fr.get_denominator();
		return *this;
	}

	Fraction& operator*=(const Fraction& fr) {
		_numerator *= fr.get_numerator();
		_denominator *= fr.get_denominator();
		return *this;
	}

	Fraction& operator++() {
		_numerator += _denominator;
		normalize();
		return *this;
	}//Префиксный инкремент, т.е. мы сначала ++, потом присваиваем значение

	Fraction operator++(int) {
		Fraction fr(*this);
		_numerator += _denominator;
		normalize();
		return fr;
	}//Постфиксный инкремент, т.е. мы сначала сохраняем значение в новую переменную, потом ++, потом возвращаем переменную (не возвращает ссылку)

};


Fraction operator+(Fraction fr_1, Fraction fr_2) {
	fr_1+=fr_2;
	return fr_1;
}

Fraction operator-(Fraction fr_1, Fraction fr_2) {
	fr_1 -= fr_2;
	return fr_1;
}

Fraction operator* (Fraction fr_1, Fraction fr_2) {
	fr_1 *= fr_2;
	return fr_1;
}

/*Рефакторинг*/
std::string to_string(Fraction fr) {
	return std::format("{}/{}", fr.get_numerator(), fr.get_denominator());
}

std::ostream& operator<<(std::ostream& out, const Fraction& fr) {
	out << fr.get_numerator() << "/" << fr.get_denominator();
	return out;
}

bool to_file(const std::string& path, const Fraction& fr) {
	std::ofstream str(path);  

	if (!str) {  
		return false;  
	}

	str << fr;
	return true;  
}

int main() {
	int n = 0;
	int d = 0;

	std::println("Enter the first fraction:");
	std::cin >> n >> d;
	Fraction fr_1(n, d);

	std::println("Enter the second fraction:");
	std::cin >> n >> d;
	Fraction fr_2(n, d);

	std::cout << "First fraction:" << fr_1 << "\nSecond fraction:" << fr_2;

	/*std::println("Enter PATH:");
	std::string path;
	std::cin >> path;
	to_file(path, fr_1);*/

	std::println("\nSelect operation:");
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
		Fraction res_mult = fr_1 * fr_2;
		std::println("{}*{}={}", to_string(fr_1), to_string(fr_2), to_string(res_mult));
	}

	return 0;
}