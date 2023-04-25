#include <figure/figure.h>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace figure;
using namespace std;

Point::Point() :_x(0), _y(0), _z(0) {};
Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z) {}

float Point::get_x()const { return _x; }
float Point::get_y()const { return _y; }
float Point::get_z()const { return _z; }

void Point::set_x(float x) { _x = x; }
void Point::set_y(float y) { _y = y; }
void Point::set_z(float z) { _z = z; }



Figure::Figure() {
	_type = BALL;
	_p1 = Point(0, 0, 0);
	_p2 = Point(1, 1, 1);
}
Figure::Figure(const FigureTypes type, Point p1, Point p2) : _type(type), _p1(p1), _p2(p2) {};
Figure::Figure(const Figure& fig) : _type(fig._type), _p1(fig._p1), _p2(fig._p2) {}

FigureTypes Figure::get_figure_type()const { return _type; }
std::string Figure::get_type() const {
	switch (_type)
	{
	case FigureTypes::BALL:
		return "Ball";
	case FigureTypes::CYLINDR:
		return "Cylindr";
	case FigureTypes::PARALLELEPIPED:
		return "Parallelepiped";
	default:
		throw runtime_error("Unknown type of figure");
	}
}
Point Figure::get_p1()const { return _p1; };
Point Figure::get_p2()const { return _p2; };

float Figure::figure_surface_area()const {
	float length = (fabs(_p1.get_x() - _p2.get_x()));
	float width = (fabs(_p1.get_y() - _p2.get_y()));
	float height = (fabs(_p1.get_z() - _p2.get_z()));
	switch (_type)
	{
	case BALL:
		float rad;
		rad = (sqrt((length * length) + (width * width) + (height * height)));
		return 4 * PI * rad * rad;

	case CYLINDR:
		float rad1;
		rad1 = (sqrt((length * length) + (width * width)));
		return 2 * PI * rad1 * (rad1 + height);

	case PARALLELEPIPED:
		return 2 * (length * height + length * width + height * width);
	}
	return 0;
}

float Figure::figure_volume()const {
	float length = (fabs(_p1.get_x() - _p2.get_x()));
	float width = (fabs(_p1.get_y() - _p2.get_y()));
	float height = (fabs(_p1.get_z() - _p2.get_z()));

	switch (_type)
	{
	case BALL:
		float rad;
		rad = (sqrt((length * length) + (width * width) + (height * height)));
		return 4 * PI * rad * rad * rad / 3;

	case CYLINDR:
		float rad1;
		rad1 = (sqrt((length * length) + (width * width)));
		return PI * rad1 * rad1 * height;

	case PARALLELEPIPED:
		return length * height * width;
	}

	return 0;
}

std::ostream& figure::operator<<(std::ostream& stream, const Figure& fig) {
	if (fig.get_type() == "Ball")
		stream << "Тип фигуры: " << fig.get_type() << " \n "
		<< "Координаты центра: X = " << fig.get_p1().get_x() << " Y = " << fig.get_p1().get_y() << " Z = " << fig.get_p1().get_z() << "\n"
		<< "Координаты точки поверхности: X = " << fig.get_p2().get_x() << " Y = " << fig.get_p2().get_y() << " Z = " << fig.get_p2().get_z() << "\n" << endl;
	if (fig.get_type() == "Cylindr")
		stream << "Тип фигуры: " << fig.get_type() << " \n "
		<< "Нижняя диаметрально противоположная точка: X = " << fig.get_p1().get_x() << " Y = " << fig.get_p1().get_y() << " Z = " << fig.get_p1().get_z() << "\n"
		<< "Верхняя диаметрально противоположная точка: X = " << fig.get_p2().get_x() << " Y = " << fig.get_p2().get_y() << " Z = " << fig.get_p2().get_z() << "\n" << endl;
	if (fig.get_type() == "Parallelepiped")
		stream << "Тип фигуры: " << fig.get_type() << " \n "
		<< "Нижняя точка диагонали: X = " << fig.get_p1().get_x() << " Y = " << fig.get_p1().get_y() << " Z = " << fig.get_p1().get_z() << "\n"
		<< "Верхняя точка диагонали: X = " << fig.get_p2().get_x() << " Y = " << fig.get_p2().get_y() << " Z = " << fig.get_p2().get_z() << "\n" << endl;
	return stream;
}