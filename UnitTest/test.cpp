#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, CheckLowercaseLetters) {
	SimilarityChecker cal;
	EXPECT_THROW(cal.getAlphaPoint("AAA", "aaa"), invalid_argument);
	EXPECT_THROW(cal.getAlphaPoint("aaa", "AAA"), invalid_argument);
}