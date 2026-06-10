export module Queue;

import std;
import IEnumerator;
import IEnumerable;

template <typename T>
class QueueIterator : public IEnumerator<T>
{
private:
    typename std::deque<T>::iterator _current;
    typename std::deque<T>::iterator _end;
    bool _started = false;

public:
    QueueIterator(typename std::deque<T>::iterator begin, typename std::deque<T>::iterator end)
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
class Queue : public IEnumerable<T>
{
private:
    std::deque<T> _queue;

public:
    int Count() const
    {
        return static_cast<int>(_queue.size());
    }

    void Enqueue(T item)
    {
        _queue.push_back(item);
    }

    T Dequeue()
    {
        if (_queue.empty())
        {
            throw std::logic_error("The queue is empty");
        }
        T first_item = _queue.front();
        _queue.pop_front();
        return first_item;
    }

    const T &Peek() const
    {
        if (_queue.empty())
        {
            throw std::logic_error("The queue is empty");
        }
        return _queue.front();
    }

    std::unique_ptr<IEnumerator<T>> GetEnumerator() override
    {
        return std::make_unique<QueueIterator<T>>(_queue.begin(), _queue.end());
    }
};