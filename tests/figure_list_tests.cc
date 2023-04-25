#include <gtest/gtest.h>
#include <figure/figure.h>
using namespace figure;

FigureList construct() {
    FigureList list;
    PointPtr p1 = Point(0, 0, 0).clone();
    PointPtr p2 = Point(3, 3, 3).clone();
    Figure fig = Figure(BALL, p1,p2);

    PointPtr p3 = Point(-5, 7, 5).clone();
    PointPtr p4 = Point(-2, 7, -3).clone();
    Figure fig1 = Figure(CYLINDR, p3, p4);

    PointPtr p5 = Point(10, -15, 3).clone();
    PointPtr p6 = Point(-4, 9, 10).clone();
    Figure fig2 = Figure(PARALLELEPIPED, p5, p6);

    PointPtr p7 = Point(-5, -7, -9).clone();
    PointPtr p8 = Point(1, 6, -4).clone();
    Figure fig3 = Figure(BALL, p7, p8);

    list.add(fig);
    list.add(fig1);
    list.add(fig2);
    list.add(fig3);
    
    return list;
}

TEST(FiguresListTests, FigureListDefaultConstructorTest) {
    FigureList list = FigureList();
    EXPECT_EQ(list.get_size(), 0);

}

TEST(FiguresListTests, FigureListCopyTest) {
    FigureList list = construct();
    FigureList list1=list;
    
    EXPECT_EQ(list1.get_size(), 4);
    EXPECT_EQ((*list[0]).get_figure_type(), BALL);
    EXPECT_EQ((*list[1]).get_figure_type(), CYLINDR);
    EXPECT_EQ((*list[2]).get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ((*list[3]).get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListSwapTest) {
    FigureList list = construct();
    FigureList list1;
    PointPtr p1 = Point(3, 7, 4).clone();
    PointPtr p2 = Point(9, 11, 5).clone();
    Figure fig = Figure(CYLINDR, p1, p2);

    PointPtr p3 = Point(-16, 8, 4).clone();
    PointPtr p4 = Point(7, 15, -45).clone();
    Figure fig1 = Figure(PARALLELEPIPED, p3, p4);

    list1.add(fig);
    list1.add(fig1);

    list = list1;
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_EQ(list1.get_size(), 4);
    EXPECT_EQ((*list[0]).get_figure_type(), CYLINDR);
    EXPECT_EQ((*list[1]).get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ((*list1[0]).get_figure_type(), BALL);
    EXPECT_EQ((*list1[1]).get_figure_type(), CYLINDR);
    EXPECT_EQ((*list1[2]).get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ((*list1[3]).get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListAddTest) {
    FigureList list;
    PointPtr p1 = Point(3, 7, 4).clone();
    PointPtr p2 = Point(9, 11, 5).clone();
    Figure fig = Figure(CYLINDR, p1, p2);

    list.add(fig);

    EXPECT_EQ(list.get_size(), 1);
    EXPECT_EQ((*list[0]).get_figure_type(), CYLINDR);
}

TEST(FiguresListTests, FigureListInsertTest) {
    FigureList list=construct();
    PointPtr p1 = Point(3, 7, 4).clone();
    PointPtr p2 = Point(9, 11, 5).clone();
    Figure fig = Figure(BALL, p1, p2);

    list.insert(2,fig);

    EXPECT_EQ(list.get_size(), 5);
    EXPECT_EQ((*list[1]).get_figure_type(), CYLINDR);
    EXPECT_EQ((*list[2]).get_figure_type(), BALL);
    EXPECT_EQ((*list[3]).get_figure_type(), PARALLELEPIPED);

    EXPECT_THROW((*list[-1]).figure_volume(), std::runtime_error);
    EXPECT_THROW((*list[10]).figure_volume(), std::runtime_error);
    EXPECT_THROW(list.insert(-3,fig), std::runtime_error);
}

TEST(FiguresListTests, FigureListRemovetTest) {
    FigureList list = construct();
   
    list.remove(1);

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ((*list[0]).get_figure_type(), BALL);
    EXPECT_EQ((*list[1]).get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ((*list[2]).get_figure_type(), BALL);

    list.clear();
    EXPECT_THROW(list.remove(0), std::runtime_error);
}

TEST(FiguresListTests, FigureListClearTest)
{
    FigureList figures;
    FigureList list = FigureList();
    list.clear();
    EXPECT_EQ(list.get_size(), 0);
}
TEST(FiguresListTests, FigureListMaxVolumeTest)
{
    FigureList list = construct();
    EXPECT_EQ(list.figure_max_volume(), 3);
    list.clear();
    EXPECT_EQ(list.figure_max_volume(), -1);

}