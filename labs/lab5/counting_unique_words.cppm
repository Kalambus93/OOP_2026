export module counting_unique_words;

import std;

export unsigned long int Counter(const std::vector<std::string> &vector_for_count, const std::unordered_set<std::string> &stop_words)
{
	std::unordered_set<std::string> unique_words;

	for (auto i = 0; i < vector_for_count.size(); ++i)
	{
		if (stop_words.contains(vector_for_count[i]))
			continue;
		else
			unique_words.insert(vector_for_count[i]);
	}

	return static_cast<unsigned long int>(unique_words.size());
}