#pragma once

namespace figure {

	const float PI = 3.1411592f;

	enum FigureTypes {
		BALL,
		CYLINDR,
		PARALLELEPIPED
	};

	class Point {
		double _x, _y, _z;
	public:
		Point();
		Point(double x, double y, double z);
		double get_x()const;
		double get_y()const;
		double get_z()const;
		void set_x(double x);
		void set_y(double y);
		void set_z(double z);
	};

	class Figure {
		FigureTypes _type;
		Point _p1;
		Point _p2;
	public:
		Figure();
		Figure(FigureTypes type, const Point& p1, const Point& p2);
		FigureTypes get_figure_type()const;
		Point get_p1()const;
		Point get_p2()const;
		void set_p1(Point p1);
		void set_p2(Point p2);
		void set_figure_type(FigureTypes type);
		double figure_surface_area()const;
		double figure_volume()const;
	};

	class FigureList {
		static const int CAPACITY = 10;
		Figure _figures[CAPACITY];
		int _size;
	public:
		FigureList();
		FigureList(Figure figures[], int size);
		Figure get_figure_by_index(int i)const;
		int get_size()const;

		Figure operator[](int ind)const;
		Figure& operator[](int ind);
		void add_item(int ind, Figure fig);
		void del_item(int ind);
		void clear();
		int figure_max_volume()const;
	};
}