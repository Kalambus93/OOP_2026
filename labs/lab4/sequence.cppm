export module sequence;

import std;

export class Sequence
{
public:
	virtual ~Sequence() = default;
	virtual int operator()(int n) const = 0;
	virtual std::string to_string() const = 0;
};