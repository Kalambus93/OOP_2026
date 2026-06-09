import std;

using namespace std;

int main()
{
    std::println("Программа выводит словесное описание трёхзначного числа от 100 до 999");

    int number = 0;

    do
    {
        println("Введите число от 100 до 999: ");
        cin >> number;
    } while (number < 100 || number > 999);

    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;

    string result = "";

    switch (hundreds)
    {
    case 1:
        result += "сто";
        break;
    case 2:
        result += "двести";
        break;
    case 3:
        result += "триста";
        break;
    case 4:
        result += "четыреста";
        break;
    case 5:
        result += "пятьсот";
        break;
    case 6:
        result += "шестьсот";
        break;
    case 7:
        result += "семьсот";
        break;
    case 8:
        result += "восемьсот";
        break;
    case 9:
        result += "девятьсот";
        break;
    }

    int lastTwo = number % 100;

    if (lastTwo >= 10 && lastTwo <= 19)
    {
        result += " ";
        switch (lastTwo)
        {
        case 10:
            result += "десять";
            break;
        case 11:
            result += "одиннадцать";
            break;
        case 12:
            result += "двенадцать";
            break;
        case 13:
            result += "тринадцать";
            break;
        case 14:
            result += "четырнадцать";
            break;
        case 15:
            result += "пятнадцать";
            break;
        case 16:
            result += "шестнадцать";
            break;
        case 17:
            result += "семнадцать";
            break;
        case 18:
            result += "восемнадцать";
            break;
        case 19:
            result += "девятнадцать";
            break;
        }
    }
    else
    {
        if (tens >= 2)
        {
            result += " ";
            switch (tens)
            {
            case 2:
                result += "двадцать";
                break;
            case 3:
                result += "тридцать";
                break;
            case 4:
                result += "сорок";
                break;
            case 5:
                result += "пятьдесят";
                break;
            case 6:
                result += "шестьдесят";
                break;
            case 7:
                result += "семьдесят";
                break;
            case 8:
                result += "восемьдесят";
                break;
            case 9:
                result += "девяносто";
                break;
            }
        }

        if (units > 0)
        {
            result += " ";
            switch (units)
            {
            case 1:
                result += "один";
                break;
            case 2:
                result += "два";
                break;
            case 3:
                result += "три";
                break;
            case 4:
                result += "четыре";
                break;
            case 5:
                result += "пять";
                break;
            case 6:
                result += "шесть";
                break;
            case 7:
                result += "семь";
                break;
            case 8:
                result += "восемь";
                break;
            case 9:
                result += "девять";
                break;
            }
        }
    }

    println("{} — \"{}\"", number, result);

    return 0;
}