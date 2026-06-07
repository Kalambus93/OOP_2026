export module Dictionary;

import std;
import IEnumerator;
import ICollection;

export template <typename TKey, typename TValue>
class KeyValuePair
{
private:
    TKey _key;
    TValue _value;

public:
    KeyValuePair() = default;
    KeyValuePair(TKey key, TValue value) : _key(key), _value(value) {}

    const TKey &Key() const
    {
        return _key;
    }

    const TValue &Value() const
    {
        return _value;
    }
};

template <typename TKey, typename TValue, typename Hash = std::hash<TKey>, typename KeyEqual = std::equal_to<TKey>>
class DictionaryIterator : public IEnumerator<KeyValuePair<TKey, TValue>>
{
private:
    typename std::unordered_map<TKey, TValue, Hash, KeyEqual>::iterator _current;
    typename std::unordered_map<TKey, TValue, Hash, KeyEqual>::iterator _end;
    bool _started = false;

public:
    DictionaryIterator(std::unordered_map<TKey, TValue, Hash, KeyEqual>::iterator begin, std::unordered_map<TKey, TValue, Hash, KeyEqual>::iterator end) : _current(begin), _end(end) {}

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

    KeyValuePair<TKey, TValue> Current() const override
    {
        if (_started && _current != _end)
        {
            return KeyValuePair<TKey, TValue>(_current->first, _current->second);
        }
        else
        {
            throw std::runtime_error("Недопустимое состояние итератора");
        }
    }
};

template <typename TKey, typename TValue, typename Hash = std::hash<TKey>, typename KeyEqual = std::equal_to<TKey>>
class Dictionary : public ICollection<KeyValuePair<TKey, TValue>>
{
private:
    std::unordered_map<TKey, TValue, Hash, KeyEqual> _map;

public:
    Dictionary() = default;

    int Count() const override
    {
        return static_cast<int>(_map.size());
    }

    void Add(KeyValuePair<TKey, TValue> item) override
    {
        auto add_item = _map.insert({item.Key(), item.Value()});

        if (add_item.second == false)
        {
            throw std::runtime_error("Такой ключ уже есть");
        }
    }

    void Clear() override
    {
        _map.clear();
    }

    bool Contains(KeyValuePair<TKey, TValue> item) const override
    {
        auto key_item = item.Key();
        auto it = _map.find(key_item);
        return (it != _map.end());
    }

    bool Remove(KeyValuePair<TKey, TValue> item) override
    {
        if (_map.find(item.Key()) == _map.end())
        {
            throw std::logic_error("Ключ не найден");
        }
        else
        {
            return _map.erase(item.Key()) > 0;
        }
    }

    int Capacity() const
    {
        return static_cast<int>(_map.bucket_count());
    }

    void SetCapacity(int capacity)
    {
        _map.reserve(capacity);
    }

    TValue &operator[](const TKey &key)
    {
        return _map[key];
    }

    std::unique_ptr<IEnumerator<KeyValuePair<TKey, TValue>>> GetEnumerator() override
    {
        return std::make_unique<DictionaryIterator<TKey, TValue, Hash, KeyEqual>>(_map.begin(), _map.end());
    }
};