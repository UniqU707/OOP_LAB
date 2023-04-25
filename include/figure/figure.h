#pragma once
#include<iostream>
#define FigurePtr Figure*

namespace figure {

	const float PI = 3.1411592f;

	enum FigureTypes {
		BALL,
		CYLINDR,
		PARALLELEPIPED
	};



	class Point{
		float _x, _y, _z;
	public:
		Point();
		Point(float x, float y, float z);
		
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
		Point _p1;
		Point _p2;

	public:
		Figure();
		Figure(const FigureTypes type, Point p1, Point p2); 
		Figure(const Figure& fig);
		
		FigureTypes get_figure_type()const;
		std::string get_type() const;
		Point get_p1()const;
		Point get_p2()const;

		float figure_surface_area()const;
		float figure_volume()const;

	};

	std::ostream& operator<<(std::ostream& stream, const Figure& fig);


	class FigureList {
		FigurePtr* _figures;
		int _size;
	public:
		FigureList();
		FigureList(const FigureList& another);
		void swap(FigureList& another);
		FigureList& operator=(FigureList& another);
		~FigureList();

		const Figure& get_figure_by_index(int i)const;
		int get_size()const;

		const Figure& operator[](int ind)const;
		Figure& operator[](int ind);
		
		void add(const Figure& fig);
		void insert(int ind, Figure fig);
		void remove(int ind);
		void clear();

		int figure_max_volume()const;
	};

	std::ostream& operator<<(std::ostream& stream, const FigureList& fig);
}