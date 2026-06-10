export module squares;

import std;
import sequence;

export class Squares : public Sequence
{
private:
    int _c = 0;

public:
    Squares(int c) : _c(c) {}

    int operator()(int n) const override
    {
        return n * n + _c;
    }

    int get_free_ratio() const
    {
        return _c;
    }

    std::string to_string() const override
    {
        if (_c == 0)
        {
            return "n²";
        }
        else if (_c > 0)
        {
            return std::format("n² + {}", _c);
        }
        else
        {
            return std::format("n² - {}", std::abs(_c));
        }
    }
};