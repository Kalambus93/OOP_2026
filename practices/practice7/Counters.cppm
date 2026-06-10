export module Counters;

import std;

export class ICounter
{
protected:
	int _count = 0;
	int _max = 0;

public:
	virtual ~ICounter() = default;

	virtual void increment() = 0;
	virtual void reset() = 0;
	virtual int getValue() const = 0;
	virtual bool IsLimitReached() const = 0;
	virtual std::string getType() const = 0;
};

export class BoundedCounter : public ICounter
{
private:
public:
	BoundedCounter(int max)
	{
		_max = max;
	}

	void increment() override
	{
		if (_count < _max)
		{
			++_count;
		}
	}

	void reset() override
	{
		_count = 0;
	}

	int getValue() const override
	{
		return _count;
	}

	bool IsLimitReached() const override
	{

		if (_count == _max)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	std::string getType() const override
	{
		return std::format("Type: BoundedCounter, Parameters: max = {}", _max);
	}
};

export class CyclicCounter : public ICounter
{
private:
public:
	CyclicCounter(int max)
	{
		_max = max;
	}

	void increment() override
	{
		if (_count < _max)
		{
			++_count;
		}

		else
		{
			_count = 0;
		}
	}

	void reset() override
	{
		_count = 0;
	}

	int getValue() const override
	{
		return _count;
	}

	bool IsLimitReached() const override
	{

		if (_count == _max)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	std::string getType() const override
	{
		return std::format("Type: CyclicCounter, Parameters: max = {}", _max);
	}
};

export class StepCounter : public ICounter
{
private:
	int _step = 0;

public:
	StepCounter(int max, int step) : _step(step)
	{
		_max = max;
	}

	void increment() override
	{
		if (_count + _step <= _max)
		{
			_count += _step;
		}
	}

	void reset() override
	{
		_count = 0;
	}

	int getValue() const override
	{
		return _count;
	}

	bool IsLimitReached() const override
	{

		if (_count == _max || _count + _step > _max)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	std::string getType() const override
	{
		return std::format("Type: StepCounter, Parameters: max = {}, step = {}", _max, _step);
	}
};