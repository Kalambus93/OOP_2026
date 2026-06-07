export module List;

import std;
import IEnumerator;
import ICollection;

template <typename T>
class ListIterator : public IEnumerator<T>
{
private:
    typename std::vector<T>::iterator _current;
    typename std::vector<T>::iterator _end;
    bool _started = false;

public:
    ListIterator(typename std::vector<T>::iterator begin,
                 typename std::vector<T>::iterator end)
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
        if (_started && _current != _end)
        {
            return *_current;
        }
        else
        {
            throw std::runtime_error("Недопустимое состояние итератора");
        }
    }
};

export template <typename T>
class List : public ICollection<T>
{
private:
    std::vector<T> _list;

public:
    List() = default;

    int Count() const override
    {
        return static_cast<int>(_list.size());
    }

    void Add(T item) override
    {
        _list.push_back(item);
    }

    void Clear() override
    {
        _list.clear();
    }

    bool Contains(T item) const override
    {
        return std::find(_list.begin(), _list.end(), item) != _list.end();
    }

    bool Remove(T item) override
    {
        auto iter = std::find(_list.begin(), _list.end(), item);
        if (iter != _list.end())
        {
            _list.erase(iter);
            return true;
        }
        else
            return false;
    }

    int Capacity()
    {
        return static_cast<int>(_list.capacity());
    }

    void SetCapacity(int capacity)
    {
        _list.reserve(capacity);
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= static_cast<int>(_list.size()))
        {
            throw std::out_of_range("Неправильный индекс");
        }
        else
        {
            return _list[index];
        }
    }

    void Insert(int index, T item)
    {
        if (index < 0 || index > static_cast<int>(_list.size()))
        {
            throw std::out_of_range("Неправильный индекс");
        }
        else
        {
            _list.insert(_list.begin() + index, item);
        }
    }

    void RemoveAt(int index)
    {
        if (index < 0 || index >= static_cast<int>(_list.size()))
        {
            throw std::out_of_range("Неправильный индекс");
        }
        _list.erase(_list.begin() + index);
    }

    std::unique_ptr<IEnumerator<T>> GetEnumerator() override
    {
        return std::make_unique<ListIterator<T>>(_list.begin(), _list.end());
    }
};