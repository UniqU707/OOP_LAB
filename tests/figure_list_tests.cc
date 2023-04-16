#include <gtest/gtest.h>
#include <figure/figure.h>
#define CAPACITY 10
using namespace figure;


TEST(FiguresListTests, FigureListConstructorTest)
{
    const int SIZE = 4;
    Figure fig[CAPACITY];

    Point p1 = Point(0, 0, 0);
    Point p2 = Point(3, 3, 3);
    fig[0] = Figure(BALL, p1, p2);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    fig[1] = Figure(CYLINDR, p3, p4);

    Point p5;
    Point p6;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    fig[2] = Figure(PARALLELEPIPED, p5, p6);


    Point p7;
    Point p8;
    p7 = Point(-5, -7, -9);
    p8 = Point(1, 6, -4);
    fig[3] = Figure(BALL, p7, p8);

    FigureList list = FigureList(fig, SIZE);
    EXPECT_EQ(list.get_size(), SIZE);
    EXPECT_EQ(list[0].get_figure_type(), BALL);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[2].get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(list[3].get_figure_type(), BALL);

}
TEST(FiguresListTests, FigureListGetItemTest)
{
    const int SIZE = 4;
    Figure fig[CAPACITY];

    Point p1;
    Point p2;
    p1 = Point(0, 0, 0);
    p2 = Point(3, 3, 3);
    fig[0] = Figure(BALL, p1, p2);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    fig[1] = Figure(CYLINDR, p3, p4);

    Point p5;
    Point p6;;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    fig[2] = Figure(PARALLELEPIPED, p5, p6);


    Point p7;
    Point p8;
    p7 = Point(-5, -7, -9);
    p8 = Point(1, 6, -4);
    fig[3] = Figure(BALL, p7, p8);

    FigureList list = FigureList(fig, SIZE);
    EXPECT_EQ(list[3].get_figure_type(), BALL);
}

TEST(FiguresListTests, FigureListAddItemTest)
{
    FigureList list = FigureList();
    Point p1;
    Point p2;
    p1 = Point(3, 3, 3);
    p2 = Point(5, 7, 1);

    Figure fig = Figure(CYLINDR, p1, p2);

    list.add_item(0, fig);
    EXPECT_EQ(list[0].get_figure_type(), CYLINDR);
    EXPECT_EQ(list[0].get_p1().get_x(), 3);
    EXPECT_EQ(list[0].get_p1().get_y(), 3);
    EXPECT_EQ(list[0].get_p1().get_z(), 3);
    EXPECT_EQ(list[0].get_p2().get_x(), 5);
    EXPECT_EQ(list[0].get_p2().get_y(), 7);
    EXPECT_EQ(list[0].get_p2().get_z(), 1);
}
TEST(FiguresListTests, FigureListDelItemTest)
{
    const int SIZE = 4;
    Figure fig[CAPACITY];

    Point p1;
    Point p2;
    p1 = Point(0, 0, 0);
    p2 = Point(3, 3, 3);
    fig[0] = Figure(BALL, p1, p2);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    fig[1] = Figure(CYLINDR, p3, p4);

    Point p5;
    Point p6;;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    fig[2] = Figure(PARALLELEPIPED, p5, p6);


    Point p7;
    Point p8;
    p7 = Point(-5, -7, -9);
    p8 = Point(1, 6, -4);
    fig[3] = Figure(BALL, p7, p8);

    FigureList list = FigureList(fig, SIZE);
    list.del_item(2);
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ(list[1].get_figure_type(), CYLINDR);
}
TEST(FiguresListTests, FigureListClearTest)
{
    FigureList list = FigureList();
    list.clear();
    EXPECT_EQ(list.get_size(), 0);
}
TEST(FiguresListTests, FigureListMaxVolumeTest)
{
    const int SIZE = 4;
    Figure fig[CAPACITY];

    Point p1;
    Point p2;
    p1 = Point(0, 0, 0);
    p2 = Point(3, 3, 3);
    fig[0] = Figure(BALL, p1, p2);

    Point p3;
    Point p4;
    p3 = Point(-5, 7, 5);
    p4 = Point(-2, 7, -3);
    fig[1] = Figure(CYLINDR, p3, p4);

    Point p5;
    Point p6;;
    p5 = Point(10, -15, 3);
    p6 = Point(-4, 9, 10);
    fig[2] = Figure(PARALLELEPIPED, p5, p6);

    Point p7;
    Point p8;
    p7 = Point(-23, 1, 15);
    p8 = Point(4, 1, 4);
    fig[3] = Figure(CYLINDR, p7, p8);

    FigureList list = FigureList(fig, SIZE);
    EXPECT_EQ(list.figure_max_volume(), 3);
}
TEST(FiguresListTests, FigureListMaxVolumeTestEmpty)
{
    FigureList list = FigureList();
    EXPECT_EQ(list.figure_max_volume(), -1);
}


TEST(ExceptionTests, ExeptionIndexOutTest)
{
    FigureList list = FigureList();
    EXPECT_THROW(list[-1].figure_volume(), std::runtime_error);
    EXPECT_THROW(list[10].figure_volume(), std::runtime_error);
}
TEST(ExceptionTests, ExeptionCapacityTest)
{
    FigureList list = FigureList();
    Figure fig = Figure();
    EXPECT_THROW(list.add_item(1, fig), std::runtime_error);
}
TEST(ExceptionTests, ExeptionEmptyTest)
{
    FigureList list = FigureList();
    list.clear();
    EXPECT_THROW(list.del_item(1), std::runtime_error);
}