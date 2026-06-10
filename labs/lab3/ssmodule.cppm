export module ssmodule;

import std;

export class SquareSequence
{
private:
	int _c = 0;

public:
	SquareSequence(int c) : _c(c) {}

	int operator()(int n) const
	{
		return n * n + _c;
	}

	int GetFreeCoefficient() const
	{
		return _c;
	}
};

export int FindMember(const std::vector<SquareSequence> &vec_for_member_sequence, int n)
{

	if (vec_for_member_sequence.size() == 0)
	{
		return -1;
	}

	int temporary_variable = vec_for_member_sequence[0](n);

	int index = 0;

	for (std::size_t i = 0; i < vec_for_member_sequence.size(); ++i)
	{
		if (temporary_variable > vec_for_member_sequence[i](n))
		{
			temporary_variable = vec_for_member_sequence[i](n);
			index = i;
		}
	}

	return index;
}