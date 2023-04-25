#include <gtest/gtest.h>
#include <figure/figure.h>

using namespace figure;

TEST(PointsTests, PointConstructorTest) {
    Point p1 = Point(7, 8, 9);
    EXPECT_EQ(p1.get_x(), 7);
    EXPECT_EQ(p1.get_y(), 8);
    EXPECT_EQ(p1.get_z(), 9);
}

TEST(PointsTests, PointCopyTest) {
    Point p1 = Point(1, 2, 3);
    Point p2(p1);
    EXPECT_EQ(p1.get_x(), 1);
    EXPECT_EQ(p1.get_y(), 2);
    EXPECT_EQ(p1.get_z(), 3);
}

TEST(PointsTests, PointSwapTest) {
    Point p1 = Point(1, 2, 3);
    Point p2 = Point(7, 8, 9);
    p1 = p2;
    EXPECT_EQ(p1.get_x(), 7);
    EXPECT_EQ(p1.get_y(), 8);
    EXPECT_EQ(p1.get_z(), 9);
    EXPECT_EQ(p2.get_x(), 1);
    EXPECT_EQ(p2.get_y(), 2);
    EXPECT_EQ(p2.get_z(), 3);
}

TEST(FiguresTests, FigureConstructorTest) {
    PointPtr p1 = Point(7, 8, 9).clone();
    PointPtr p2 = Point(4, 5, 6).clone();
    Figure fig = Figure(BALL, p1, p2);
    EXPECT_EQ(fig.get_figure_type(), BALL);
    EXPECT_EQ((*p1).get_x(), 7);
    EXPECT_EQ((*p1).get_y(), 8);
    EXPECT_EQ((*p1).get_z(), 9);
    EXPECT_EQ((*p2).get_x(), 4);
    EXPECT_EQ((*p2).get_y(), 5);
    EXPECT_EQ((*p2).get_z(), 6);
    /*почистить?*/
}

TEST(FiguresTests, FigureCopyTest) {
    PointPtr p1 = Point(1, 2, 3).clone();
    PointPtr p2 = Point(4, 5, 6).clone();
    Figure fig = Figure(CYLINDR, p1, p2);
    Figure fig1(fig);
    EXPECT_EQ(fig1.get_figure_type(), CYLINDR);
}

TEST(FiguresTests, FigureSwapTest) {
    PointPtr p1 = Point(1, 2, 3).clone();
    PointPtr p2 = Point(4, 5, 6).clone();
    Figure fig = Figure(CYLINDR, p1, p2);
    PointPtr p3 = Point(17, 18, 19).clone();
    PointPtr p4 = Point(23, 24, 25).clone();
    Figure fig1 = Figure(PARALLELEPIPED, p3, p4);
    fig = fig1;
    EXPECT_EQ(fig.get_figure_type(), PARALLELEPIPED);
    EXPECT_EQ(fig1.get_figure_type(), CYLINDR);
}

TEST(FiguresTests, FigureBallVolumeTest) {
    PointPtr p1 = Point(-1, 8, 3).clone();
    PointPtr p2 = Point(-4, -2, 9).clone();
    Figure fig = Figure(BALL, p1, p2);
    EXPECT_LT(fig.figure_volume(), 7313);
    EXPECT_GT(fig.figure_volume(), 7312);


    PointPtr p3 = Point(-5, -7, -9).clone();
    PointPtr p4 = Point(1, 6, -4).clone();
    Figure fig1 = Figure(BALL, p4, p3);
    EXPECT_LT(fig1.figure_volume(), 14609);
    EXPECT_GT(fig1.figure_volume(), 14608);
}

TEST(FiguresTests, FigureBALLSurfaceAreaTest) {
    PointPtr p1 = Point(-1, 8, 3).clone();
    PointPtr p2 = Point(-4, -2, 9).clone();
    Figure fig = Figure(BALL, p1, p2);
    EXPECT_LT(fig.figure_surface_area(), 1822);
    EXPECT_GT(fig.figure_surface_area(), 1821);

    PointPtr p3 = Point(-5, -7, -9).clone();
    PointPtr p4 = Point(1, 6, -4).clone();
    Figure fig1 = Figure(BALL, p4, p3);
    EXPECT_LT(fig1.figure_surface_area(), 2890);
    EXPECT_GT(fig1.figure_surface_area(), 2889);
}

TEST(FiguresTests, FigureCYLINDRVolumeTest) {
    PointPtr p1 = Point(-5, 7, 5).clone();
    PointPtr p2 = Point(-2, 7, -3).clone();
    Figure fig = Figure(CYLINDR, p1, p2);
    EXPECT_LT(fig.figure_volume(), 227);
    EXPECT_GT(fig.figure_volume(), 226);


    PointPtr p3 = Point(-23, 1, 15).clone();
    PointPtr p4 = Point(4, 1, 4).clone();
    Figure fig1 = Figure(CYLINDR, p4, p3);
    EXPECT_LT(fig1.figure_volume(), 25189);
    EXPECT_GT(fig1.figure_volume(), 25188);
}

TEST(FiguresTests, FigureCYLINDRVSurfaceAreaTest) {
    PointPtr p1 = Point(-5, 7, 5).clone();
    PointPtr p2 = Point(-2, 7, -3).clone();
    Figure fig = Figure(CYLINDR, p1, p2);
    EXPECT_LT(fig.figure_surface_area(), 208);
    EXPECT_GT(fig.figure_surface_area(), 207);


    PointPtr p3 = Point(-23, 1, 15).clone();
    PointPtr p4 = Point(4, 1, 4).clone();
    Figure fig1 = Figure(CYLINDR, p4, p3);
    EXPECT_LT(fig1.figure_surface_area(), 6446);
    EXPECT_GT(fig1.figure_surface_area(), 6445);
}

TEST(FiguresTests, FigurePARALLELEPIPEDVolumeTest) {
    PointPtr p1 = Point(10, -15, 3).clone();
    PointPtr p2 = Point(-4, 9, 10).clone();
    Figure fig = Figure(PARALLELEPIPED, p1, p2);
    EXPECT_EQ(fig.figure_volume(), 2352);


    PointPtr p3 = Point(7, 4, 0).clone();
    PointPtr p4 = Point(-24, -11, 9).clone();
    Figure fig1 = Figure(PARALLELEPIPED, p4, p3);
    EXPECT_EQ(fig1.figure_volume(), 4185);
}

TEST(FiguresTests, FigurePARALLELEPIPEDSurfaceAreaTest) {
    PointPtr p1 = Point(10, -15, 3).clone();
    PointPtr p2 = Point(-4, 9, 10).clone();
    Figure fig = Figure(PARALLELEPIPED, p1, p2);
    EXPECT_EQ(fig.figure_surface_area(), 1204);


    PointPtr p3 = Point(7, 4, 0).clone();
    PointPtr p4 = Point(-24, -11, 9).clone();
    Figure fig1 = Figure(PARALLELEPIPED, p4, p3);
    EXPECT_EQ(fig1.figure_surface_area(), 1758);
}

