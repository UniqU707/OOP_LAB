#include <gtest/gtest.h>
#include <figure/figure.h>
using namespace figure;

FigureList construct() {
    FigureList list;

    Figure fig = Figure(BALL, Point(0, 0, 0), Point(3, 3, 3));
    Figure fig1 = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));
    Figure fig2 = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));
    Figure fig3 = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));

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
    EXPECT_EQ(list[0].get_figure_type(), BALL);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[2].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list[3].get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListSwapTest) {
    FigureList list = construct();
    FigureList list1;
    Figure fig = Figure(CYLINDR, Point(3, 7, 4), Point(9, 11, 5));
    Figure fig1 = Figure(PARALLELEPIPED, Point(-16, 8, 4), Point(7, 15, -45));

    list1.add(fig);
    list1.add(fig1);

    list = list1;
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_EQ(list1.get_size(), 4);
    EXPECT_EQ(list[0].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[1].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list1[0].get_figure_type(), BALL);
    EXPECT_EQ(list1[1].get_figure_type(), CYLINDR);
    EXPECT_EQ(list1[2].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list1[3].get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListAddTest) {
    FigureList list;
    Figure fig = Figure(CYLINDR, Point(3, 7, 4), Point(9, 11, 5));

    list.add(fig);

    EXPECT_EQ(list.get_size(), 1);
    EXPECT_EQ(list[0].get_figure_type(), CYLINDR);
}

TEST(FiguresListTests, FigureListInsertTest) {
    FigureList list=construct();
    Figure fig = Figure(BALL, Point(3, 7, 4), Point(9, 11, 5));

    list.insert(2,fig);

    EXPECT_EQ(list.get_size(), 5);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[2].get_figure_type(), BALL);
    EXPECT_EQ(list[3].get_figure_type(), PARALLELEPIPED);

    EXPECT_THROW(list[-1].figure_volume(), std::runtime_error);
    EXPECT_THROW(list[10].figure_volume(), std::runtime_error);
    EXPECT_THROW(list.insert(-3,fig), std::runtime_error);
}

TEST(FiguresListTests, FigureListRemovetTest) {
    FigureList list = construct();
   
    list.remove(1);

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ(list[0].get_figure_type(), BALL);
    EXPECT_EQ(list[1].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list[2].get_figure_type(), BALL);

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