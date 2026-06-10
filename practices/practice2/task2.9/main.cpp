import std;

using namespace std;

int main()
{
    std::println("Программа выводит все целые числа между a и b включительно и их количество");
    int a = 0;
    int b = 0;

    do
    {
        println("Введите числа a и b");
        cin >> a >> b;
    } while (b < a);

    println("");

    for (; b >= a; a++)
    {
        println("{}", a);
    }

    return 0;
}