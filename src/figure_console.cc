#include <figure/figure_console.h>
#include <string.h>

using namespace figure;
using namespace console;
using namespace std;
 
void console::text_menu() {
    system("cls");
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                Меню                               |" << endl;
	cout << " —-------------------------------------------------------------------" << endl;
	cout << " | 1 - Добавить фигуру в конец списка                                |" << endl;
	cout << " | 2 - Добавить фигуру в список по индексу                           |" << endl;
	cout << " | 3 - Удалить фигуру из списка по индексу                           |" << endl;
	cout << " | 4 - Рассчитать объём фигуры                                       |" << endl;
	cout << " | 5 - Рассчитать площадь поверхности фигуры                         |" << endl;
	cout << " | 6 - Поиск в наборе первой фигуры с максимальным объёмом           |" << endl;
	cout << " | 7 - Вывести список фигур                                          |" << endl;
	cout << " | 8 - Выйти из системы                                              |" << endl;
	cout << "  -------------------------------------------------------------------" << endl;
}

int console::get_key() {
    int key = _getch();
    if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56))
        return key;
}

Figure console::create_figure() {
    Figure fig;
    int type;
    Point p1;
    Point p2;
	float x1, y1, z1, x2, y2, z2;

    cout << "Введите тип фигуры: 1 - Шар    2 - Цилиндр    3 - Параллелепипед\n";
    cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Invalid type of figure!");
	if (type == 1) {
		cout << "Введите координаты центра\n";
		cout << "Координата X: ";
		cin >> x1;
		cout << "Координата Y: ";
		cin >> y1;
		cout << "Координата Z: ";
		cin >> z1;

		cout << "Введите координаты точки на поверхности\n";
		cout << "Координата X: ";
		cin >> x2;
		cout << "Координата Y: ";
		cin >> y2;
		cout << "Координата Z: ";
		cin >> z2;
		return Figure(BALL, Point(x1, y1,z1), Point(x2, y2, z2));
	}
	if (type == 2) {
		cout << "Введите координаты нижней диаметрально противоположной точки\n";
		cout << "Координата X: ";
		cin >> x1;
		cout << "Координата Y: ";
		cin >> y1;
		cout << "Координата Z: ";
		cin >> z1;

		cout << "Введите координаты верхней диаметрально противоположной точки\n";
		cout << "Координата X: ";
		cin >> x2;
		cout << "Координата Y: ";
		cin >> y2;
		cout << "Координата Z: ";
		cin >> z2;
		return Figure(CYLINDR, Point(x1, y1, z1), Point(x2, y2, z2));
	}
	if (type == 3) {
		cout << "Введите координаты нижней точки диагонали\n";
		cout << "Координата X: ";
		cin >> x1;
		cout << "Координата Y: ";
		cin >> y1;
		cout << "Координата Z: ";
		cin >> z1;

		cout << "Введите координаты верхней точки диагонали\n";
		cout << "Координата X: ";
		cin >> x2;
		cout << "Координата Y: ";
		cin >> y2;
		cout << "Координата Z: ";
		cin >> z2;
		return Figure(PARALLELEPIPED, Point(x1, y1, z1), Point(x2, y2, z2));

	}
}
