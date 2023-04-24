#pragma once
#include <utility>
#define PointPtr Point*
#define FigurePtr Figure*

namespace figure {

	const float PI = 3.1411592f;

	enum FigureTypes {
		BALL,
		CYLINDR,
		PARALLELEPIPED
	};



	class Point{
		double _x, _y, _z;
	public:
		Point();
		Point(float x, float y, float z);
		Point(const Point& point);
		void swap(Point& another);
		Point& operator=(Point& another);

		float get_x()const;
		float get_y()const;
		float get_z()const;

		void set_x(float x);
		void set_y(float y);
		void set_z(float z);
	};



	class Figure {

	private:
		FigureTypes _type;
		PointPtr _p1;
		PointPtr _p2;

	public:
		Figure(const FigureTypes type, PointPtr& p1, PointPtr& p2);
		Figure(const Figure& fig);
		void swap(Figure& another);
		Figure& operator=(Figure& another);
		~Figure();

		FigureTypes get_figure_type()const;
		PointPtr get_p1()const;
		PointPtr get_p2()const;

		void set_p1(PointPtr p1);
		void set_p2(PointPtr p2);
		void set_figure_type(FigureTypes type);

		float figure_surface_area()const;
		float figure_volume()const;

		FigurePtr clone()const;
		
	};



	bool operator==(const Figure& fig, const Figure& another);

	bool operator!=(const Figure& fig, const Figure& another);



	class FigureList {
		FigurePtr* _figures;
		int _size;
	public:
		FigureList();
		FigureList(FigurePtr* figures, int size);
		FigureList(FigureList& figures);
		void swap(FigureList& another);
		FigureList operator=(FigureList another);
		~FigureList();

		FigurePtr get_figure_by_index(int i)const;
		int get_size()const;

		FigurePtr operator[](int ind)const;
		FigurePtr& operator[](int ind);
		

		void add_item(int ind, Figure fig);
		void del_item(int ind);
		void clear();
		int figure_max_volume()const;
	};
}