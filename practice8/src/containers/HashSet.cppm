export module HashSet;

import std;
import IEnumerator;
import ICollection;

template <typename T, typename Hash = std::hash<T>, typename KeyEqual = std::equal_to<T>>
class HashSetIterator : public IEnumerator<T>
{
private:
    typename std::unordered_set<T, Hash, KeyEqual>::iterator _current;
    typename std::unordered_set<T, Hash, KeyEqual>::iterator _end;
    bool _started = false;

public:
    HashSetIterator(std::unordered_set<T, Hash, KeyEqual>::iterator begin, std::unordered_set<T, Hash, KeyEqual>::iterator end) : _current(begin), _end(end) {}

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
            throw std::runtime_error("Invalid iterator state");
        }
    }
};

export template <typename T, typename Hash = std::hash<T>, typename KeyEqual = std::equal_to<T>>
class HashSet : public ICollection<T>
{
private:
    std::unordered_set<T, Hash, KeyEqual> _set;

public:
    HashSet() = default;

    int Count() const override
    {
        return static_cast<int>(_set.size());
    }

    void Add(T item) override
    {
        _set.insert(item);
    }

    void Clear() override
    {
        _set.clear();
    }

    bool Contains(T item) const override
    {
        return _set.find(item) != _set.end();
    }

    bool Remove(T item) override
    {
        return _set.erase(item) != 0;
    }

    int Capacity() const
    {
        return static_cast<int>(_set.bucket_count());
    }

    void SetCapacity(int capacity)
    {
        _set.reserve(capacity);
    }

    std::unique_ptr<IEnumerator<T>> GetEnumerator() override
    {
        return std::make_unique<HashSetIterator<T, Hash, KeyEqual>>(_set.begin(), _set.end());
    }
};