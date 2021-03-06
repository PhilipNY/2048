#include "triangle.h"
#include "gtest/gtest.h"


// Robust Boundary Value Testing
TEST(TriangleTest, BoundaryValue_Robust) {
	TriangleType EXPECT_TYPE;
	if (UPPER_BOUND & 1)
		EXPECT_TYPE = NOT_A_TRIANGLE;
	else
		EXPECT_TYPE = ISOSCELES;

	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND+1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(EXPECT_TYPE, Triangle(UPPER_BOUND-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, VALID_VALUE, VALID_VALUE));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, LOWER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND+1, VALID_VALUE));
	EXPECT_EQ(EXPECT_TYPE, Triangle(VALID_VALUE, UPPER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, UPPER_BOUND, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, UPPER_BOUND+1, VALID_VALUE));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND-1));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND+1));
	EXPECT_EQ(EXPECT_TYPE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND-1));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND+1));

	EXPECT_EQ(EQUILATERAL, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE));
}

// Equivalence Class Testing
TEST(TriangleTest, EquivalenceClass_WeakNormal) {
	EXPECT_EQ(EQUILATERAL, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE-1, VALID_VALUE, VALID_VALUE+1));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, VALID_VALUE, VALID_VALUE));
}
TEST(TriangleTest, EquivalenceClass_WeakRobust) {
	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, LOWER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND-1));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, UPPER_BOUND+1, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND+1));
}
TEST(TriangleTest, EquivalenceClass_StrongNormal) {
	EXPECT_EQ(EQUILATERAL, Triangle(LOWER_BOUND, LOWER_BOUND, LOWER_BOUND));
	EXPECT_EQ(EQUILATERAL, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(EQUILATERAL, Triangle(UPPER_BOUND, UPPER_BOUND, UPPER_BOUND));

	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE-1, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE-1, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE-1));

	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE, VALID_VALUE-1, VALID_VALUE+1));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE-1, VALID_VALUE, VALID_VALUE+1));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE-1, VALID_VALUE+1, VALID_VALUE));

	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, UPPER_BOUND, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND));
}
TEST(TriangleTest, EquivalenceClass_StrongRobust) {
	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, LOWER_BOUND-1, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, VALID_VALUE, LOWER_BOUND-1));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, LOWER_BOUND-1, LOWER_BOUND-1));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(LOWER_BOUND-1, LOWER_BOUND-1, LOWER_BOUND-1));

	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, UPPER_BOUND+1, VALID_VALUE));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, VALID_VALUE, UPPER_BOUND+1));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(VALID_VALUE, UPPER_BOUND+1, UPPER_BOUND+1));
	EXPECT_EQ(OUT_OF_RANGE, Triangle(UPPER_BOUND+1, UPPER_BOUND+1, UPPER_BOUND+1));
}

// Edge Testing
TEST(TriangleTest, Edge_WeakNormal) {
	// Class Equilateral
	EXPECT_EQ(EQUILATERAL, Triangle(LOWER_BOUND, LOWER_BOUND, LOWER_BOUND));
	EXPECT_EQ(EQUILATERAL, Triangle(UPPER_BOUND, UPPER_BOUND, UPPER_BOUND));
	// Class Isosceles
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND, VALID_VALUE, VALID_VALUE));	// LVV
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, UPPER_BOUND, UPPER_BOUND));	// VUU
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND, UPPER_BOUND, UPPER_BOUND));	// LUU

	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(UPPER_BOUND, VALID_VALUE, UPPER_BOUND));
	EXPECT_EQ(ISOSCELES, Triangle(UPPER_BOUND, LOWER_BOUND, UPPER_BOUND));

	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND));
	EXPECT_EQ(ISOSCELES, Triangle(UPPER_BOUND, UPPER_BOUND, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(UPPER_BOUND, UPPER_BOUND, LOWER_BOUND));
	// Class Scalene
	EXPECT_EQ(SCALENE, Triangle(LOWER_BOUND+1, LOWER_BOUND+2, LOWER_BOUND+3));	// LVV
	EXPECT_EQ(SCALENE, Triangle(LOWER_BOUND+1, UPPER_BOUND-1, UPPER_BOUND));	// LUU
	EXPECT_EQ(SCALENE, Triangle(UPPER_BOUND, VALID_VALUE+1, VALID_VALUE+2));	// UVV
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE, UPPER_BOUND-1, UPPER_BOUND));		// VUU

	EXPECT_EQ(SCALENE, Triangle(LOWER_BOUND+2, LOWER_BOUND+1, LOWER_BOUND+3));
	EXPECT_EQ(SCALENE, Triangle(UPPER_BOUND-1, LOWER_BOUND+1, UPPER_BOUND));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE+1, UPPER_BOUND, VALID_VALUE+2));
	EXPECT_EQ(SCALENE, Triangle(UPPER_BOUND-1, VALID_VALUE, UPPER_BOUND));

	EXPECT_EQ(SCALENE, Triangle(LOWER_BOUND+2, LOWER_BOUND+3, LOWER_BOUND+1));
	EXPECT_EQ(SCALENE, Triangle(UPPER_BOUND-1, UPPER_BOUND, LOWER_BOUND+1));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE+1, VALID_VALUE+2, UPPER_BOUND));
	EXPECT_EQ(SCALENE, Triangle(UPPER_BOUND-1, UPPER_BOUND, VALID_VALUE));
	// Class Not a triangle
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, LOWER_BOUND, LOWER_BOUND+1));	// LLL

	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, LOWER_BOUND, LOWER_BOUND));		// VLL
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, LOWER_BOUND, LOWER_BOUND));		// ULL
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, UPPER_BOUND-1, UPPER_BOUND));	// LUU

	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, VALID_VALUE, LOWER_BOUND));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, UPPER_BOUND, LOWER_BOUND));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND-1, LOWER_BOUND, UPPER_BOUND));

	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, LOWER_BOUND, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(LOWER_BOUND, LOWER_BOUND, UPPER_BOUND));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND-1, UPPER_BOUND, LOWER_BOUND));
}

// Decision Table-Based Testing
TEST(TriangleTest, DecisionTable) {
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(UPPER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, UPPER_BOUND, VALID_VALUE));
	EXPECT_EQ(NOT_A_TRIANGLE, Triangle(VALID_VALUE, VALID_VALUE, UPPER_BOUND));
	EXPECT_EQ(EQUILATERAL, Triangle(VALID_VALUE, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, VALID_VALUE, LOWER_BOUND));
	EXPECT_EQ(ISOSCELES, Triangle(VALID_VALUE, LOWER_BOUND, VALID_VALUE));
	EXPECT_EQ(ISOSCELES, Triangle(LOWER_BOUND, VALID_VALUE, VALID_VALUE));
	EXPECT_EQ(SCALENE, Triangle(VALID_VALUE-1, VALID_VALUE, VALID_VALUE+1));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}