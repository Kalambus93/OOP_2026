export module IEnumerable;

import std;
import IEnumerator;

export template <typename T>
class IEnumerable
{
public:
    virtual ~IEnumerable() = default;
    virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() = 0;
};