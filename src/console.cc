#include <figure/figure_console.h>
#include "figure/figure.h"
#include <Windows.h>

using namespace figure;
using namespace console;
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	FigureList list;
	Figure fig;

	console::text_menu();

	while (true)
	{
		int alternative = console::get_key();
		int ind = 0;


		system("cls");
		console::text_menu();


		if (alternative == 56) {
			list.clear();
			break;
		}

		switch (alternative)
		{

		case 49:
			list.add(create_figure());
			break;

		case 50:
			cout << "������� ������, �� �������� ����� �������� ����� ������: ";
			cin >> ind;
			list.insert(ind, create_figure());
			break;


		case 51:
			cout << "������� ������, �� �������� ����� ������� ������: ";
			cin >> ind;
			list.remove(ind);
			break;

		case 52:
			cout << "������� ������ ������, � ������� ����� ��������� �����: ";
			cin >> ind;
			cout << "�������� = " << list[ind].figure_volume() << endl;
			break;

		case 53:
			cout << "������� ������ ������, � ������� ����� ��������� ������� �����������: ";
			cin >> ind;
			cout << "������� = " << list[ind].figure_surface_area() << endl;
			break;

		case 54:
			cout << "������ ������ � ������������ �������: " << list.figure_max_volume();
			break;

		case 55:
			cout << list;
			break;
		}
	}
	return 0;
}