export module factorial;

import std;
import sequence;

export class Factorial : public Sequence
{
public:
	Factorial() {}

	int operator()(int n) const override
	{
		int result = 1;

		for (int i = 1; i <= n; ++i)
		{
			result *= i;
		}
		return result;
	};

	std::string to_string() const override
	{
		return "n!";
	}
};