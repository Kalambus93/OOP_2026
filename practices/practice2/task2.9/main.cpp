import std;

using namespace std;

int main()
{
    std::println("Программа выводит все целые числа между a и b включительно и их количество");
    int a = 0;
    int b = 0;
    int count = 0;

    do
    {
        println("Введите числа a и b");
        cin >> a >> b;
    } while (b < a);

    println("");

    for (; b >= a; ++a)
    {
        println("{}", a);
        ++count;
    }

    println("Количество чисел: {}", count);

    return 0;
}