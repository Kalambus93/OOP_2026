import std;

class Fraction
{
private:
	int _numerator = 0;
	int _denominator = 0;

	void normalize()
	{
		if (_numerator == 0)
		{
			_denominator = 0;
		}

		if (_denominator < 0)
		{
			_denominator = std::abs(_denominator);
		}

		int gcd_number = std::gcd(_numerator, _denominator);
		_numerator = _numerator / gcd_number;
		_denominator = _denominator / gcd_number;
	}

public:
	Fraction(int numerator)
	{
		_numerator = numerator;
	}

	Fraction(int numerator, int denominator)
	{
		_numerator = numerator;
		_denominator = denominator;
	}

	int get_numerator() const
	{
		return _numerator;
	}

	int get_denominator() const
	{
		return _denominator;
	}
};

Fraction operator+(Fraction fr1, Fraction fr2)
{
	int sum_numerator = fr1.get_numerator() * fr2.get_denominator() + fr1.get_denominator() * fr2.get_numerator();
	int sum_denominator = fr1.get_denominator() * fr2.get_denominator();

	Fraction result(sum_numerator, sum_denominator);

	return result;
}

Fraction operator*(Fraction fr1, Fraction fr2)
{
	int mult_numerator = fr1.get_numerator() * fr2.get_numerator();
	int mult_denominator = fr1.get_denominator() * fr2.get_denominator();

	Fraction result(mult_numerator, mult_denominator);

	return result;
}

std::string to_string(Fraction fr)
{
	return std::format("{}/{}", fr.get_numerator(), fr.get_denominator());
}

int main()
{

	return 0;
}