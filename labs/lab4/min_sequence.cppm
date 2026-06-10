export module min_sequence;

import std;
import sequence;
import squares;
import factorial;

export std::shared_ptr<Sequence> SearchMinSequence(const std::vector<std::shared_ptr<Sequence>> &sqnc, int n)
{
    if (sqnc.empty())
    {
        return nullptr;
    }

    auto min_seq = sqnc[0];
    int min_value = (*min_seq)(n);

    for (size_t i = 1; i < sqnc.size(); ++i)
    {
        int current_value = (*sqnc[i])(n);
        if (current_value < min_value)
        {
            min_value = current_value;
            min_seq = sqnc[i];
        }
    }

    return min_seq;
}