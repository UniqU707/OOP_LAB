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
    Figure fig = Figure(BALL, Point(-2, 2, 9), Point(1, 2, 15));
    EXPECT_EQ(fig.get_figure_type(), BALL);
}
TEST(FiguresTests, FigureConstructorPosTest) {
    Figure fig = Figure(BALL, Point(-2, 2, 9), Point(1, 2, 15));
    EXPECT_EQ(fig.get_p1().get_x(), -2);
    EXPECT_EQ(fig.get_p1().get_y(), 2);
    EXPECT_EQ(fig.get_p1().get_z(), 9);
    EXPECT_EQ(fig.get_p2().get_x(), 1);
    EXPECT_EQ(fig.get_p2().get_y(), 2);
    EXPECT_EQ(fig.get_p2().get_z(), 15);
}

TEST(FiguresTests, FigureBallVolumeTest) {
    Figure fig = Figure(BALL, Point(0, 0, 0), Point(3, 3, 3));
    EXPECT_LT(fig.figure_volume(), 588);
    EXPECT_GT(fig.figure_volume(), 587);

    Figure fig1 = Figure(BALL, Point(5, 4, 3), Point(8, 1, 3));
    EXPECT_LT(fig1.figure_volume(), 320);
    EXPECT_GT(fig1.figure_volume(), 319);

    Figure fig2 = Figure(BALL, Point(-1, 8, 3), Point(-4, -2, 9));
    EXPECT_LT(fig2.figure_volume(), 7313);
    EXPECT_GT(fig2.figure_volume(), 7312);

    Figure fig3 = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_LT(fig3.figure_volume(), 14609);
    EXPECT_GT(fig3.figure_volume(), 14608);
}
TEST(FiguresTests, FigureBALLSurfaceAreaTest) {
    Figure fig = Figure(BALL, Point(0, 0, 0), Point(3, 3, 3));
    EXPECT_LT(fig.figure_surface_area(), 340);
    EXPECT_GT(fig.figure_surface_area(), 339);

    Figure fig1 = Figure(BALL, Point(5, 4, 3), Point(8, 1, 3));
    EXPECT_LT(fig1.figure_surface_area(), 227);
    EXPECT_GT(fig1.figure_surface_area(), 226);

    Figure fig2 = Figure(BALL, Point(-1, 8, 3), Point(-4, -2, 9));
    EXPECT_LT(fig2.figure_surface_area(), 1822);
    EXPECT_GT(fig2.figure_surface_area(), 1821);

    Figure fig3 = Figure(BALL, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_LT(fig3.figure_surface_area(), 2890);
    EXPECT_GT(fig3.figure_surface_area(), 2889);
}

TEST(FiguresTests, FigureCYLINDRVolumeTest) {
    Figure fig = Figure(CYLINDR, Point(0, 3, 5), Point(0, 6, 7));
    EXPECT_LT(fig.figure_volume(), 57);
    EXPECT_GT(fig.figure_volume(), 56);

    Figure fig1 = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));
    EXPECT_LT(fig1.figure_volume(), 227);
    EXPECT_GT(fig1.figure_volume(), 226);

    Figure fig2 = Figure(CYLINDR, Point(15, 3, 8), Point(15, -2, -7));
    EXPECT_LT(fig2.figure_volume(), 1178);
    EXPECT_GT(fig2.figure_volume(), 1177);

    Figure fig3 = Figure(CYLINDR, Point(-23, 1, 15), Point(4, 1, 4));
    EXPECT_LT(fig3.figure_volume(), 25189);
    EXPECT_GT(fig3.figure_volume(), 25188);
}
TEST(FiguresTests, FigureCYLINDRVSurfaceAreaTest) {
    Figure fig = Figure(CYLINDR, Point(0, 3, 5), Point(0, 6, 7));
    EXPECT_LT(fig.figure_surface_area(), 95);
    EXPECT_GT(fig.figure_surface_area(), 94);

    Figure fig1 = Figure(CYLINDR, Point(-5, 7, 5), Point(-2, 7, -3));
    EXPECT_LT(fig1.figure_surface_area(), 208);
    EXPECT_GT(fig1.figure_surface_area(), 207);

    Figure fig2 = Figure(CYLINDR, Point(15, 3, 8), Point(15, -2, -7));
    EXPECT_LT(fig2.figure_surface_area(), 629);
    EXPECT_GT(fig2.figure_surface_area(), 628);

    Figure fig3 = Figure(CYLINDR, Point(-23, 1, 15), Point(4, 1, 4));
    EXPECT_LT(fig3.figure_surface_area(), 6446);
    EXPECT_GT(fig3.figure_surface_area(), 6445);
}

TEST(FiguresTests, FigurePARALLELEPIPEDVolumeTest) {
    Figure fig = Figure(PARALLELEPIPED, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_EQ(fig.figure_volume(), 390);

    Figure fig1 = Figure(PARALLELEPIPED, Point(0, 4, -3), Point(7, 12, -5));
    EXPECT_EQ(fig1.figure_volume(), 112);

    Figure fig2 = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));
    EXPECT_EQ(fig2.figure_volume(), 2352);

    Figure fig3 = Figure(PARALLELEPIPED, Point(7, 4, 0), Point(-24, -11, 9));
    EXPECT_EQ(fig3.figure_volume(), 4185);

}
TEST(FiguresTests, FigurePARALLELEPIPEDSurfaceAreaTest) {
    Figure fig = Figure(PARALLELEPIPED, Point(-5, -7, -9), Point(1, 6, -4));
    EXPECT_EQ(fig.figure_surface_area(), 346);

    Figure fig1 = Figure(PARALLELEPIPED, Point(0, 4, -3), Point(7, 12, -5));
    EXPECT_EQ(fig1.figure_surface_area(), 172);

    Figure fig2 = Figure(PARALLELEPIPED, Point(10, -15, 3), Point(-4, 9, 10));
    EXPECT_EQ(fig2.figure_surface_area(), 1204);

    Figure fig3 = Figure(PARALLELEPIPED, Point(7, 4, 0), Point(-24, -11, 9));
    EXPECT_EQ(fig3.figure_surface_area(), 1758);

}