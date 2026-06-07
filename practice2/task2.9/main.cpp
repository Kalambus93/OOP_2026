import std;

using namespace std;

int main() {
    int a = 0;
    int b = 0;

    do {
        println("Введите числа a и b");
        cin >> a >> b;
    } while (b < a);

    println("");

    for (; b >= a; a++) {
        println("{}", a);
    }

    return 0;
}