#include <figure/figure.h>
#include <cmath>
#include <stdexcept>

using namespace figure;
using namespace std;


Point::Point() :_x(0), _y(0), _z(0) {};

Point::Point(double x_ref, double y_ref, double z_ref) : _x(x_ref), _y(y_ref), _z(z_ref) {};

double Point::get_x()const { return _x; }
double Point::get_y()const { return _y; }
double Point::get_z()const { return _z; }

void Point::set_x(double x) { _x = x; }
void Point::set_y(double y) { _y = y; }
void Point::set_z(double z) { _z = z; }

Figure::Figure() {
	_type = BALL;
	_p1 = Point(0, 0, 0);
	_p2 = Point(1, 1, 1);
}

Figure::Figure(FigureTypes type, const Point& p1, const Point& p2) {
	_type = type;
	_p1 = p1;
	_p2 = p2;
}

FigureTypes Figure::get_figure_type()const { return _type; }

void Figure::set_figure_type(FigureTypes type) { _type = type; }

Point Figure::get_p1()const { return _p1; };
Point Figure::get_p2()const { return _p2; };
void Figure::set_p1(Point p1) {
	_p1 = p1;
}
void Figure::set_p2(Point p2) {
	_p2 = p2;
}

double Figure::figure_surface_area()const {
	switch (_type)
	{
	case BALL:
		double rad;
		rad = (sqrt(
			(_p1.get_x() - _p2.get_x()) * (_p1.get_x() - _p2.get_x()) +
			(_p1.get_y() - _p2.get_y()) * (_p1.get_y() - _p2.get_y()) +
			(_p1.get_z() - _p2.get_z()) * (_p1.get_z() - _p2.get_z())));
		return 4 * PI * rad * rad;

	case CYLINDR:
		double rad1, height;
		height = (fabs(_p1.get_z() - _p2.get_z()));
		rad1 = (sqrt(
			(_p1.get_x() - _p2.get_x()) * (_p1.get_x() - _p2.get_x()) +
			(_p1.get_y() - _p2.get_y()) * (_p1.get_y() - _p2.get_y())));
		return 2 * PI * rad1 * (rad1 + height);

	case PARALLELEPIPED:
		double length, height1, width;
		height1 = (fabs(_p1.get_z() - _p2.get_z()));
		length = (fabs(_p1.get_x() - _p2.get_x()));
		width = (fabs(_p1.get_y() - _p2.get_y()));
		return 2 * (length * height1 + length * width + height1 * width);
	}
	return 0;
}

double Figure::figure_volume()const {

	switch (_type)
	{
	case BALL:
		double rad;
		rad = (sqrt(
			(_p1.get_x() - _p2.get_x()) * (_p1.get_x() - _p2.get_x()) +
			(_p1.get_y() - _p2.get_y()) * (_p1.get_y() - _p2.get_y()) +
			(_p1.get_z() - _p2.get_z()) * (_p1.get_z() - _p2.get_z())));
		return 4 * PI * rad * rad * rad / 3;

	case CYLINDR:
		double rad1, height;
		height = (fabs(_p1.get_z() - _p2.get_z()));
		rad1 = (sqrt(
			(_p1.get_x() - _p2.get_x()) * (_p1.get_x() - _p2.get_x()) +
			(_p1.get_y() - _p2.get_y()) * (_p1.get_y() - _p2.get_y())));
		return PI * rad1 * rad1 * height;

	case PARALLELEPIPED:
		double length, height1, width;
		height1 = (fabs(_p1.get_z() - _p2.get_z()));
		length = (fabs(_p1.get_x() - _p2.get_x()));
		width = (fabs(_p1.get_y() - _p2.get_y()));
		return length * height1 * width;
	}

	return 0;
}