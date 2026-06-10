export module delete_error;
import std;

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