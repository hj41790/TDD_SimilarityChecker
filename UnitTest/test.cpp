#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker cal;
};

TEST_F(SimilarityCheckerFixture, LengthPoint60) {
	EXPECT_EQ(60, cal.getLengthPoint("ABC", "DEF"));
}

TEST_F(SimilarityCheckerFixture, LengthPoint0) {
	EXPECT_EQ(0, cal.getLengthPoint("ABC", "DEFGHI"));
	EXPECT_EQ(0, cal.getLengthPoint("DEFGHI", "ABC"));
}

TEST_F(SimilarityCheckerFixture, LengthPointLongShort) {
	EXPECT_EQ(20, cal.getLengthPoint("ABCDE", "ABC"));
}

TEST_F(SimilarityCheckerFixture, LengthPointShortLong) {
	EXPECT_EQ(20, cal.getLengthPoint("ABC", "ABCDE"));
}