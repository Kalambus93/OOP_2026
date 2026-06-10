export module Stack;

import std;
import IEnumerator;
import IEnumerable;

template <typename T>
class StackIterator : public IEnumerator<T>
{
private:
    typename std::vector<T>::iterator _current;
    typename std::vector<T>::iterator _end;
    bool _started = false;

public:
    StackIterator(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
        : _current(begin), _end(end) {}

    bool MoveNext() override
    {
        if (!_started)
        {
            _started = true;
            return (_current != _end);
        }
        ++_current;
        return (_current != _end);
    }

    T Current() const override
    {
        if (!_started || _current == _end)
            throw std::runtime_error("Invalid iterator state");
        return *_current;
    }
};

export template <typename T>
class Stack : public IEnumerable<T>
{
private:
    std::vector<T> _stack;

public:
    int Count() const
    {
        return static_cast<int>(_stack.size());
    }

    void Push(T item)
    {
        _stack.push_back(item);
    }

    const T &Peek() const
    {
        if (_stack.empty())
        {
            throw std::logic_error("The stack is empty");
        }
        return _stack.back();
    }

    T Pop()
    {
        if (_stack.empty())
        {
            throw std::logic_error("The stack is empty");
        }
        T pop_item = _stack.back();
        _stack.pop_back();
        return pop_item;
    }

    std::unique_ptr<IEnumerator<T>> GetEnumerator() override
    {
        return std::make_unique<StackIterator<T>>(_stack.begin(), _stack.end());
    }
};