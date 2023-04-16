#include <gtest/gtest.h>
#include <figure/figure.h>
#define CAPACITY 10
using namespace figure;

FigureList construct() {
    const int SIZE = 4;
    Figure fig[CAPACITY];

    fig[0] = Figure(BALL, Point(0, 0, 0), Point(3, 3, 3));

    fig[1] = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));

    fig[2] = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));

    fig[3] = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));

    FigureList list = FigureList(fig, SIZE);
    
    return list;
}

TEST(FiguresListTests, FigureListConstructorTest)
{
    FigureList list = construct();
    EXPECT_EQ(list.get_size(), 4);
    EXPECT_EQ(list[0].get_figure_type(), BALL);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[2].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list[3].get_figure_type(), BALL);

}
TEST(FiguresListTests, FigureListGetItemTest)
{
    FigureList list = construct();
    EXPECT_EQ(list[3].get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListAddItemTest)
{
    FigureList list = FigureList();
    Figure fig = Figure(CYLINDR, Point(3, 3, 3), Point(5, 7, 1));

    list.add_item(0, fig);
    EXPECT_EQ(list[0].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[0].get_p1().get_x(), 3);
    EXPECT_EQ(list[0].get_p1().get_y(), 3);
    EXPECT_EQ(list[0].get_p1().get_z(), 3);
    EXPECT_EQ(list[0].get_p2().get_x(), 5);
    EXPECT_EQ(list[0].get_p2().get_y(), 7);
    EXPECT_EQ(list[0].get_p2().get_z(), 1);
    EXPECT_THROW(list[-1].figure_volume(), std::runtime_error);
    EXPECT_THROW(list[10].figure_volume(), std::runtime_error);

    FigureList list1 = FigureList();
    Figure fig1 = Figure();
    EXPECT_THROW(list1.add_item(1, fig1), std::runtime_error);
}
TEST(FiguresListTests, FigureListDelItemTest)
{
    FigureList list = construct();
    list.del_item(2);
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
    list.clear();
    EXPECT_THROW(list.del_item(1), std::runtime_error);
}
TEST(FiguresListTests, FigureListClearTest)
{
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