#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, LengthPoint60) {
	string input1 = "ABC";
	string input2 = "DEF";

	SimilarityChecker cal;
	EXPECT_EQ(60, cal.getLengthPoint(input1, input2));
}