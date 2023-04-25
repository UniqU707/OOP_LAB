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

TEST(FiguresTests, FigureConstructorTest) {
    Figure fig = Figure(BALL, Point(7, 8, 9), Point(4, 5, 6));
    EXPECT_EQ(fig.get_figure_type(), BALL);
    EXPECT_EQ(fig.get_p1().get_x(), 7);
    EXPECT_EQ(fig.get_p1().get_y(), 8);
    EXPECT_EQ(fig.get_p1().get_z(), 9);
    EXPECT_EQ(fig.get_p2().get_x(), 4);
    EXPECT_EQ(fig.get_p2().get_y(), 5);
    EXPECT_EQ(fig.get_p2().get_z(), 6);
}

TEST(FiguresTests, FigureCopyTest) {
    Figure fig = Figure(CYLINDR, Point(1, 2, 3), Point(4, 5, 6));
    Figure fig1(fig);
    EXPECT_EQ(fig1.get_figure_type(), CYLINDR);
}

TEST(FiguresTests, FigureBallVolumeTest) {
    Figure fig = Figure(BALL, Point(-1, 8, 3), Point(-4, -2, 9));
    EXPECT_LT(fig.figure_volume(), 7313);
    EXPECT_GT(fig.figure_volume(), 7312);

    Figure fig1 = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_LT(fig1.figure_volume(), 14609);
    EXPECT_GT(fig1.figure_volume(), 14608);
}

TEST(FiguresTests, FigureBALLSurfaceAreaTest) {
    Figure fig = Figure(BALL, Point(-1, 8, 3), Point(-4, -2, 9));
    EXPECT_LT(fig.figure_surface_area(), 1822);
    EXPECT_GT(fig.figure_surface_area(), 1821);

    Figure fig1 = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_LT(fig1.figure_surface_area(), 2890);
    EXPECT_GT(fig1.figure_surface_area(), 2889);
}

TEST(FiguresTests, FigureCYLINDRVolumeTest) {
    Figure fig = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));
    EXPECT_LT(fig.figure_volume(), 227);
    EXPECT_GT(fig.figure_volume(), 226);

    Figure fig1 = Figure(CYLINDR, Point(-23, 1, 15), Point(4, 1, 4));
    EXPECT_LT(fig1.figure_volume(), 25189);
    EXPECT_GT(fig1.figure_volume(), 25188);
}

TEST(FiguresTests, FigureCYLINDRVSurfaceAreaTest) {
    Figure fig = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));
    EXPECT_LT(fig.figure_surface_area(), 208);
    EXPECT_GT(fig.figure_surface_area(), 207);


    Figure fig1 = Figure(CYLINDR, Point(-23, 1, 15), Point(4, 1, 4));
    EXPECT_LT(fig1.figure_surface_area(), 6446);
    EXPECT_GT(fig1.figure_surface_area(), 6445);
}

TEST(FiguresTests, FigurePARALLELEPIPEDVolumeTest) {
    Figure fig = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));
    EXPECT_EQ(fig.figure_volume(), 2352);

    Figure fig1 = Figure(PARALLELEPIPED, Point(7, 4, 0), Point(-24, -11, 9));
    EXPECT_EQ(fig1.figure_volume(), 4185);
}

TEST(FiguresTests, FigurePARALLELEPIPEDSurfaceAreaTest) {
    Figure fig = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));
    EXPECT_EQ(fig.figure_surface_area(), 1204);


    Figure fig1 = Figure(PARALLELEPIPED, Point(7, 4, 0), Point(-24, -11, 9));
    EXPECT_EQ(fig1.figure_surface_area(), 1758);
}

