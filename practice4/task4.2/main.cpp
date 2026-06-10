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
};

int main()
{

	return 0;
}