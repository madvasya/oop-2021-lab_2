#include "pch.h"
#include "..\EvolventLibrary\Evolvent.h"

// тестирование конструкторов TEST(EvolventConstructor, DefaultConstructor)
TEST(EvolventConstructor, DefaultConstructor) {
	lab_2::Evolvent a1;
	ASSERT_EQ(0, a1.getP().x);
	ASSERT_EQ(0, a1.getP().y);
	ASSERT_EQ(1, a1.getR());
}

TEST(EvolventConstructor, InitConstructors) {
	lab_2::Evolvent a2(3);
	lab_2::Point p(2, 3);
	ASSERT_EQ(3, a2.getR());
	ASSERT_EQ(0, a2.getP().x);
	ASSERT_EQ(0, a2.getP().y);

	lab_2::Evolvent а3(p, 8);
	ASSERT_EQ(2, а3.getP().x);
	ASSERT_EQ(3, а3.getP().y);
	ASSERT_EQ(8, а3.getR());

	lab_2::Evolvent a4(-4, -5, 3);
	ASSERT_EQ(-4, a4.getP().x);
	ASSERT_EQ(-5, a4.getP().y);
	ASSERT_EQ(3, a4.getR());
}

TEST(EvolventConstructor, TestException) {
	lab_2::Point p;
	ASSERT_ANY_THROW(lab_2::Evolvent(2, 5, -5));
	ASSERT_ANY_THROW(lab_2::Evolvent(p, -1));
}

// Тестирование других методов 
TEST(EvolventMethods, Setters) {
	lab_2::Evolvent а;
	lab_2::Point p1(3, 2);
	а.setP(p1);
	ASSERT_EQ(3, а.getP().x);
	ASSERT_EQ(2, а.getP().y);
	lab_2::Point р2(-3, -2);
	а.setP(р2);
	ASSERT_EQ(-3, а.getP().x);
	ASSERT_EQ(-2, а.getP().y);
	а.setR(2);
	ASSERT_EQ(2, а.getR());
	ASSERT_ANY_THROW(а.setR(-1));
}

TEST(EvolventMethods, Parameters) {
	lab_2::Evolvent a1;
	const double err = 0.00001;
	double test_angle = M_PI / 2;
	lab_2::Point test_point = a1.cartesianFromAngle(test_angle);
	ASSERT_NEAR(M_PI/2, test_point.x, err);
	ASSERT_NEAR(1, test_point.y, err);

	lab_2::Point p2(10, -2);
	a1.setP(p2);
	test_point = a1.cartesianFromAngle(test_angle);
	ASSERT_NEAR(M_PI / 2 + p2.x, test_point.x, err);
	ASSERT_NEAR(1 + p2.y, test_point.y, err);

	int test_angle_deg = 360;
	test_point = a1.cartesianFromAngle(test_angle_deg);
	ASSERT_NEAR(1 + p2.x, test_point.x, err);
	ASSERT_NEAR(- 2 * M_PI + p2.y, test_point.y, err);

	p2.x = 0;
	p2.y = 1;
	a1.setP(p2);
	ASSERT_NEAR(sqrt(2), a1.distanceToCenter(0), err);
	/*ASSERT_EQ(0, a1.f(1).x);
	ASSERT_EQ(0, a1.f(1).y);
	ASSERT_EQ(1, a1.f(0).x);
	ASSERT_EQ(-1, a1.f(0).y);
	ASSERT_ANY_THROW(a1.f(2));*/
	ASSERT_STREQ("x ^ 2 + y ^ 2 = 1.00\n", a1.frm());

	/*lab_2::Evolvent a2(1, 3, 2);
	ASSERT_NEAR(PI * 4, a2.area(), err); 
	ASSERT_NEAR(2 * PI * 2, a2.perimeter(), err);
	ASSERT_EQ(sqrt(10), a2.distance());
	ASSERT_EQ(5, a2.f(1).x);
	ASSERT_EQ(1, a2.f(1).y);
	ASSERT_NEAR(3 + sqrt(3), a2.f(0).x, err);
	ASSERT_EQ(3 - sqrt(3), a2.f(0).y);
	ASSERT_ANY_THROW(a2.f(-2));
	ASSERT_STREQ("(x - 1.00) ^ 2 + (y - 3.00) ^ 2 = 4.00\n", a2.frm());*/
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}