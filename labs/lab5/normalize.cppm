export module normalize;

import std;

export std::vector<std::string> Normalize(const std::vector<std::string> &vector_words)
{

    std::vector<std::string> result;

    for (size_t i = 0; i < vector_words.size(); ++i)
    {
        const std::string &word = vector_words[i];

        std::string clean;

        for (size_t j = 0; j < word.size(); ++j)
        {
            unsigned char uc = static_cast<unsigned char>(word[j]);
            if (std::isalpha(uc))
            {
                clean += static_cast<char>(std::tolower(uc));
            }
            else if (uc == '-' && !clean.empty() && clean.back() != '-')
            {
                clean += '-';
            }
        }

        while (!clean.empty() && clean.front() == '-')
        {
            clean.erase(0, 1);
        }

        while (!clean.empty() && clean.back() == '-')
        {
            clean.pop_back();
        }

        if (!clean.empty())
        {
            result.push_back(std::move(clean));
        }
    }

    return result;
}