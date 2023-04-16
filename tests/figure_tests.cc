#include <gtest/gtest.h>
#include <figure/figure.h>

using namespace figure;

TEST(PointsTests, PointDefaultConstructorTest)
{
    Point p = Point();
    EXPECT_EQ(p.get_x(), 0);
    EXPECT_EQ(p.get_y(), 0);
    EXPECT_EQ(p.get_z(), 0);
}
TEST(PointsTests, PointConstructorTest)
{
    Point p1 = Point(7, 8, 9);
    EXPECT_EQ(p1.get_x(), 7);
    EXPECT_EQ(p1.get_y(), 8);
    EXPECT_EQ(p1.get_z(), 9);
}
TEST(PointsTests, PointSetterTest)
{
    const double NEW_VAL = 5;
    Point p = Point();
    p.set_x(NEW_VAL);
    p.set_y(NEW_VAL);
    p.set_z(NEW_VAL);
    EXPECT_EQ(p.get_x(), NEW_VAL);
    EXPECT_EQ(p.get_y(), NEW_VAL);
    EXPECT_EQ(p.get_z(), NEW_VAL);
}

TEST(FiguresTests, FigureDefaultConstructorPosTest) {
    Figure fig = Figure();
    EXPECT_EQ(fig.get_p1().get_x(), 0);
    EXPECT_EQ(fig.get_p1().get_y(), 0);
    EXPECT_EQ(fig.get_p1().get_z(), 0);
    EXPECT_EQ(fig.get_p2().get_x(), 1);
    EXPECT_EQ(fig.get_p2().get_y(), 1);
    EXPECT_EQ(fig.get_p2().get_z(), 1);
}
TEST(FiguresTests, FigureConstructorTypeTest) {
    Point p1;
    Point p2;
    p1 = Point(-2, 2, 9);
    p2 = Point(1, 2, 15);
    Figure fig = Figure(BALL, p1, p2);
    EXPECT_EQ(fig.get_figure_type(), BALL);
}
TEST(FiguresTests, FigureConstructorPosTest) {
    Point p1;
    Point p2;
    p1 = Point(-2, 2, 9);
    p2 = Point(1, 2, 15);
    Figure fig = Figure(BALL, p1,p2);
    EXPECT_EQ(fig.get_p1().get_x(), -2);
    EXPECT_EQ(fig.get_p1().get_y(), 2);
    EXPECT_EQ(fig.get_p1().get_z(), 9);
    EXPECT_EQ(fig.get_p2().get_x(), 1);
    EXPECT_EQ(fig.get_p2().get_y(), 2);
    EXPECT_EQ(fig.get_p2().get_z(), 15);
}

TEST(FiguresTests, FigureBallVolumeTest) {
    Point p1;
    Point p2;
    p1 = Point(0, 0, 0);
    p2 = Point(3, 3, 3);
    Figure fig = Figure(BALL, p1,p2);
    EXPECT_LT(fig.figure_volume(), 588);
    EXPECT_GT(fig.figure_volume(), 587);

    Point p3;
    Point p4;
    p3 = Point(5, 4, 3);
    p4 = Point(8, 1, 3);
    Figure fig1 = Figure(BALL,p3,p4);
    EXPECT_LT(fig1.figure_volume(), 320);
    EXPECT_GT(fig1.figure_volume(), 319);

    Point p5;
    Point p6;
    p5 = Point(-1, 8, 3);
    p6 = Point(-4, -2, 9);
    Figure fig2 = Figure(BALL,p5,p6);
    EXPECT_LT(fig2.figure_volume(), 7313);
    EXPECT_GT(fig2.figure_volume(), 7312);

    Point p7;
    Point p8;
    p7 = Point(-5, -7, -9);
    p8 = Point(1, 6, -4);
    Figure fig3 = Figure(BALL, p7,p8);
    EXPECT_LT(fig3.figure_volume(), 14609);
    EXPECT_GT(fig3.figure_volume(), 14608);
}
TEST(FiguresTests, FigureBALLSurfaceAreaTest) {
    Point p1;
    Point p2;
    p1 = Point(0, 0, 0);
    p2 = Point(3, 3, 3);
    Figure fig = Figure(BALL, p1,p2);
    EXPECT_LT(fig.figure_surface_area(), 340);
    EXPECT_GT(fig.figure_surface_area(), 339);

    Point p3;
    Point p4;
    p3 = Point(5, 4, 3);
    p4 = Point(8, 1, 3);
    Figure fig1 = Figure(BALL, p3,p4);
    EXPECT_LT(fig1.figure_surface_area(), 227);
    EXPECT_GT(fig1.figure_surface_area(), 226);

    Point p5;
    Point p6;
    p5 = Point(-1, 8, 3);
    p6 = Point(-4, -2, 9);
    Figure fig2 = Figure(BALL, p5,p6);
    EXPECT_LT(fig2.figure_surface_area(), 1822);
    EXPECT_GT(fig2.figure_surface_area(), 1821);

    Point p7;
    Point p8;
    p7 = Point(-5, -7, -9);
    p8 = Point(1, 6, -4);
    Figure fig3 = Figure(BALL, p7,p8);
    EXPECT_LT(fig3.figure_surface_area(), 2890);
    EXPECT_GT(fig3.figure_surface_area(), 2889);
}

TEST(FiguresTests, FigureCYLINDRVolumeTest) {
    Point p1;
    Point p2;
    p1 = Point(0, 3, 5);
    p2 = Point(0, 6, 7);
    Figure fig = Figure(CYLINDR, p1,p2);
    EXPECT_LT(fig.figure_volume(), 57);
    EXPECT_GT(fig.figure_volume(), 56);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    Figure fig1 = Figure(CYLINDR, p3,p4);
    EXPECT_LT(fig1.figure_volume(), 227);
    EXPECT_GT(fig1.figure_volume(), 226);

    Point p5;
    Point p6;
    p5 = Point(15, 3, 8);
    p6 = Point(15, -2, -7);
    Figure fig2 = Figure(CYLINDR, p5,p6);
    EXPECT_LT(fig2.figure_volume(), 1178);
    EXPECT_GT(fig2.figure_volume(), 1177);

    Point p7;
    Point p8;
    p7 = Point(-23, 1, 15);
    p8 = Point(4, 1, 4);
    Figure fig3 = Figure(CYLINDR, p7,p8);
    EXPECT_LT(fig3.figure_volume(), 25189);
    EXPECT_GT(fig3.figure_volume(), 25188);
}
TEST(FiguresTests, FigureCYLINDRVSurfaceAreaTest) {
    Point p1;
    Point p2;
    p1 = Point(0, 3, 5);
    p2 = Point(0, 6, 7);
    Figure fig = Figure(CYLINDR, p1, p2);
    EXPECT_LT(fig.figure_surface_area(), 95);
    EXPECT_GT(fig.figure_surface_area(), 94);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    Figure fig1 = Figure(CYLINDR, p3, p4);
    EXPECT_LT(fig1.figure_surface_area(), 208);
    EXPECT_GT(fig1.figure_surface_area(), 207);

    Point p5;
    Point p6;
    p5 = Point(15, 3, 8);
    p6 = Point(15, -2, -7);
    Figure fig2 = Figure(CYLINDR, p5, p6);
    EXPECT_LT(fig2.figure_surface_area(), 629);
    EXPECT_GT(fig2.figure_surface_area(), 628);

    Point p7;
    Point p8;
    p7 = Point(-23, 1, 15);
    p8 = Point(4, 1, 4);
    Figure fig3 = Figure(CYLINDR, p7, p8);
    EXPECT_LT(fig3.figure_surface_area(), 6446);
    EXPECT_GT(fig3.figure_surface_area(), 6445);
}

TEST(FiguresTests, FigurePARALLELEPIPEDVolumeTest) {
    Point p1;
    Point p2;
    p1 = Point(-5, -7, -9);
    p2 = Point(1, 6, -4);
    Figure fig = Figure(PARALLELEPIPED, p1,p2);
    EXPECT_EQ(fig.figure_volume(), 390);

    Point p3;
    Point p4;
    p3 = Point(0, 4, -3);
    p4 = Point(7, 12, -5);
    Figure fig1 = Figure(PARALLELEPIPED, p3,p4);
    EXPECT_EQ(fig1.figure_volume(), 112);

    Point p5;
    Point p6;;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    Figure fig2 = Figure(PARALLELEPIPED, p5,p6);
    EXPECT_EQ(fig2.figure_volume(), 2352);

    Point p7;
    Point p8;
    p7 = Point(7, 4, 0);
    p8 = Point(-24, -11, 9);
    Figure fig3 = Figure(PARALLELEPIPED, p7,p8);
    EXPECT_EQ(fig3.figure_volume(), 4185);

}
TEST(FiguresTests, FigurePARALLELEPIPEDSurfaceAreaTest) {
    Point p1;
    Point p2;
    p1 = Point(-5, -7, -9);
    p2 = Point(1, 6, -4);
    Figure fig = Figure(PARALLELEPIPED, p1, p2);
    EXPECT_EQ(fig.figure_surface_area(), 346);

    Point p3;
    Point p4;
    p3 = Point(0, 4, -3);
    p4 = Point(7, 12, -5);
    Figure fig1 = Figure(PARALLELEPIPED, p3, p4);
    EXPECT_EQ(fig1.figure_surface_area(), 172);

    Point p5;
    Point p6;;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    Figure fig2 = Figure(PARALLELEPIPED, p5, p6);
    EXPECT_EQ(fig2.figure_surface_area(), 1204);

    Point p7;
    Point p8;
    p7 = Point(7, 4, 0);
    p8 = Point(-24, -11, 9);
    Figure fig3 = Figure(PARALLELEPIPED, p7, p8);
    EXPECT_EQ(fig3.figure_surface_area(), 1758);

}

#include <figure/figure.h>
#include <cmath>
#include <stdexcept>

using namespace figure;
using namespace std;

FigureList::FigureList() :_size(0) {

}

FigureList::FigureList(Figure figures[], int size) {
	_size = size;
	for (int i = 0; i < size; ++i) {
		_figures[i] = figures[i];
	}
}

Figure FigureList::get_figure_by_index(int i)const {
	if (i < 0 || i>_size) {
		throw std::runtime_error("Index out of range.");
	}
	return _figures[i];
}

int FigureList::get_size()const { return _size; }

Figure FigureList::operator[](int ind) const {
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	return _figures[ind];
}

Figure& FigureList::operator[](int ind) {
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	return _figures[ind];
}

void FigureList::add_item(int ind, Figure fig) {
	++_size;
	if (_size == CAPACITY) {
		throw std::runtime_error("Full capacity reached.");
	}
	if (ind < 0 || ind >= _size) {
		throw std::runtime_error("Index out of range.");
	}
	for (int i = _size - 1; i >= ind; --i)
	{
		_figures[i] = _figures[i - 1];
	}
	_figures[ind] = fig;
}

void FigureList::clear() { _size = 0; }

void FigureList::del_item(int ind) {
	if (_size <= 0) {
		throw std::runtime_error("FigureList is empty.");
	}
	for (int i = ind; i < _size - 1; ++i)
	{
		_figures[i] = _figures[i + 1];
	}
	--_size;
}

int FigureList::figure_max_volume()const {
	if (_size == 0)
		return -1;
	int ind = 0;
	double max_volume = _figures[0].figure_volume();
	for (int i = 1; i < _size; ++i) {
		double cur_volume = _figures[i].figure_volume();
		if (cur_volume > max_volume) {
			ind = i;
			max_volume = cur_volume;
		}
	}
	return ind;
}
