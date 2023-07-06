#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker cal;
};

TEST_F(SimilarityCheckerFixture, CheckLowercaseLetters) {
	EXPECT_THROW(cal.getAlphaPoint("AAA", "aaa"), invalid_argument);
	EXPECT_THROW(cal.getAlphaPoint("aaa", "AAA"), invalid_argument);
}

TEST_F(SimilarityCheckerFixture, AlphabetPoint0) {
	EXPECT_EQ(0, cal.getAlphaPoint("ABC", "DEF"));
}

TEST_F(SimilarityCheckerFixture, AlphabetPoint40) {
	EXPECT_EQ(40, cal.getAlphaPoint("ABC", "CBA"));
}