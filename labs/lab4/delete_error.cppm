export module delete_error;
import std;
import sequence;

export bool FailHandling()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::println("Ошибка ввода. Пожалуйста, введите число.");
        return false;
    }
    return true;
}

export bool EmptyVector(std::vector<std::shared_ptr<Sequence>> &sqnc)
{

    if (sqnc.size() < 1)
    {
        std::println("Многочленов для счета не найдено");
        return false;
    }

    return true;
}