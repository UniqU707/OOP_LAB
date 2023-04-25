#include <figure/figure_console.h>
#include <string.h>

using namespace figure;
using namespace console;
using namespace std;
 
void console::text_menu() {
    system("cls");
	cout << " ____________________________________________________________________" << endl;
	cout << " |                                ����                               |" << endl;
	cout << " �-------------------------------------------------------------------" << endl;
	cout << " | 1 - �������� ������ � ����� ������                                |" << endl;
	cout << " | 2 - �������� ������ � ������ �� �������                           |" << endl;
	cout << " | 3 - ������� ������ �� ������ �� �������                           |" << endl;
	cout << " | 4 - ���������� ����� ������                                       |" << endl;
	cout << " | 5 - ���������� ������� ����������� ������                         |" << endl;
	cout << " | 6 - ����� � ������ ������ ������ � ������������ �������           |" << endl;
	cout << " | 7 - ������� ������ �����                                          |" << endl;
	cout << " | 8 - ����� �� �������                                              |" << endl;
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

    cout << "������� ��� ������: 1 - ���    2 - �������    3 - ��������������\n";
    cin >> type;
	if (type != 1 && type != 2 && type != 3)
		throw runtime_error("Invalid type of figure!");
	if (type == 1) {
		cout << "������� ���������� ������\n";
		cout << "���������� X: ";
		cin >> x1;
		cout << "���������� Y: ";
		cin >> y1;
		cout << "���������� Z: ";
		cin >> z1;

		cout << "������� ���������� ����� �� �����������\n";
		cout << "���������� X: ";
		cin >> x2;
		cout << "���������� Y: ";
		cin >> y2;
		cout << "���������� Z: ";
		cin >> z2;
		return Figure(BALL, Point(x1, y1,z1), Point(x2, y2, z2));
	}
	if (type == 2) {
		cout << "������� ���������� ������ ������������ ��������������� �����\n";
		cout << "���������� X: ";
		cin >> x1;
		cout << "���������� Y: ";
		cin >> y1;
		cout << "���������� Z: ";
		cin >> z1;

		cout << "������� ���������� ������� ������������ ��������������� �����\n";
		cout << "���������� X: ";
		cin >> x2;
		cout << "���������� Y: ";
		cin >> y2;
		cout << "���������� Z: ";
		cin >> z2;
		return Figure(CYLINDR, Point(x1, y1, z1), Point(x2, y2, z2));
	}
	if (type == 3) {
		cout << "������� ���������� ������ ����� ���������\n";
		cout << "���������� X: ";
		cin >> x1;
		cout << "���������� Y: ";
		cin >> y1;
		cout << "���������� Z: ";
		cin >> z1;

		cout << "������� ���������� ������� ����� ���������\n";
		cout << "���������� X: ";
		cin >> x2;
		cout << "���������� Y: ";
		cin >> y2;
		cout << "���������� Z: ";
		cin >> z2;
		return Figure(PARALLELEPIPED, Point(x1, y1, z1), Point(x2, y2, z2));

	}
}
