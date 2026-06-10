import std;

using namespace std;

int main()
{
    std::println("Программа выводит все целые степени числа a от 1 до n");
    double a = 0;
    int n = 0;
    println("Введите число a в степень n");

    do
    {
        println("Введите числа a и n");
        cin >> a >> n;
    } while (a < 0 || n < 0);

    double res = 1;
    println("{}^0={}", a, res);

    for (int i = 0; i < n; ++i)
    {
        res *= a;
        println("{}^{}={}", a, i + 1, res);
    }

    return 0;
}