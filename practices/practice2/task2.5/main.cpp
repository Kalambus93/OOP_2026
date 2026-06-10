import std;

using namespace std;

int main()
{
	std::println("Программа проверяет, может ли ладья за один ход перейти с одного поля шахматной доски на другое");
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	do
	{
		println("Поочередно введите координаты x1, x2, y1, y2");
		cin >> x1;
		cin >> x2;
		cin >> y1;
		cin >> y2;
	} while (x1 < 1 || x1 > 8 || x2 < 1 || x2 > 8 || y1 < 1 || y1 > 8 || y2 < 1 || y2 > 8);

	bool result = !(x1 == x2 || y1 == y2);

	print("Правда ли что сходили ладьей?{}", result);
	return 0;
}