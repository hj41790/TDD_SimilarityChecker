#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, CheckLowercaseLetters) {
	SimilarityChecker cal;
	EXPECT_THROW(cal.getAlphaPoint("AAA", "aaa"), invalid_argument);
	EXPECT_THROW(cal.getAlphaPoint("aaa", "AAA"), invalid_argument);
}

TEST(SimilarityCheckerTest, AlphabetPoint0) {
	SimilarityChecker cal;
	EXPECT_EQ(0, cal.getAlphaPoint("ABC", "DEF"));
}