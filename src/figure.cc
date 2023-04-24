#include <figure/figure.h>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace figure;
using namespace std;


Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z) {}

Point::Point(const Point& point): _x(point._x), _y(point._y), _z(point._z){}

void Point::swap(Point& another) {
	std::swap(_x, another._x);
	std::swap(_y, another._y);
	std::swap(_z, another._z);
}

Point& Point:: operator=(Point& another) {
	swap(another);
	return *this;
}

float Point::get_x()const { return _x; }
float Point::get_y()const { return _y; }
float Point::get_z()const { return _z; }

PointPtr Point::clone()const {
	return new Point(_x, _y, _z);
}




Figure::Figure(const FigureTypes type, PointPtr& p1,PointPtr& p2): _type(type), _p1(p1), _p2(p2) {}

Figure::Figure(const Figure& fig) : _type(fig._type), _p1(fig._p1->clone()), _p2(fig._p2->clone()) {}

void Figure::swap(Figure& another) {
	std::swap(_type, another._type);
	std::swap(_p1, another._p1);
	std::swap(_p2, another._p2);
}

Figure& Figure:: operator=(Figure& another) {
	swap(another);
	return *this;
}

Figure::~Figure() {
	delete[] _p1;
	delete[] _p2;
}


FigureTypes Figure::get_figure_type()const { return _type; }
PointPtr Figure::get_p1()const { return _p1; };
PointPtr Figure::get_p2()const { return _p2; };

FigurePtr Figure::clone() {
	return new Figure(_type, _p1,_p2);
}




float Figure::figure_surface_area()const {
	switch (_type)
	{
		float length = (fabs((*_p1).get_x() - (*_p2).get_x()));
		float width = (fabs((*_p1).get_y() - (*_p2).get_y()));
		float height = (fabs((*_p1).get_z() - (*_p2).get_z()));

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

	switch (_type)
	{
		float length = (fabs((*_p1).get_x() - (*_p2).get_x()));
		float width = (fabs((*_p1).get_y() - (*_p2).get_y()));
		float height = (fabs((*_p1).get_z() - (*_p2).get_z()));

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



bool figure::operator==(const Figure& fig, const Figure& another) {
	return
		fig.get_figure_type() == another.get_figure_type() &&
		(fig.get_p1() - another.get_p1() == 0) && 
		(fig.get_p2() - another.get_p2() == 0);
	
}

bool figure::operator!=(const Figure& fig, const Figure& another) {
	return !(fig == another);
}