export module download_text;

import std;

export std::vector<std::string> DownloadText(const std::filesystem::path &text)
{
	std::ifstream file(text);

	std::vector<std::string> words;
	std::string word;

	if (!file.is_open())
	{
		return words;
	}

	while (file >> word)
	{
		words.push_back(word);
	}

	return words;
}