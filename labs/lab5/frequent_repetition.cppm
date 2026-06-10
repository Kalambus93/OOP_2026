export module frequent_repetition;

import std;

struct Frequent
{
    unsigned long int _count = 0;
    std::set<std::string> _max_words;

    Frequent(unsigned long int count, std::set<std::string> max_words) : _count(count), _max_words(max_words) {}
};

export Frequent FrequentRepetition(const std::vector<std::string> &words, const std::unordered_set<std::string> &stop_words)
{

    std::unordered_map<std::string, unsigned long int> frequency;

    for (size_t i = 0; i < words.size(); ++i)
    {
        if (stop_words.contains(words[i]))
            continue;
        frequency[words[i]]++;
    }

    unsigned long int max_count = 0;
    for (auto it = frequency.begin(); it != frequency.end(); ++it)
    {
        if (it->second > max_count)
        {
            max_count = it->second;
        }
    }

    std::set<std::string> most_frequent_words;
    for (auto it = frequency.begin(); it != frequency.end(); ++it)
    {
        if (it->second == max_count)
        {
            most_frequent_words.insert(it->first);
        }
    }

    return Frequent(max_count, most_frequent_words);
}