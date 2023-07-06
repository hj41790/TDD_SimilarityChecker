#include <iostream>
#include <string>

using namespace std;

class SimilarityChecker
{
public:
	void invalidArgumentCheckForAlpha(const string& input1, const string& input2)
	{
		for (char c : input1)
		{
			if (c >= 'a' && c <= 'z')
				throw invalid_argument("Lowercase is included");
		}
		for (char c : input2)
		{
			if (c >= 'a' && c <= 'z')
				throw invalid_argument("Lowercase is included");
		}
	}

	bool isUsedBothSide(bool usedAlphabet1[26], bool usedAlphabet2[26], int i)
	{
		return usedAlphabet1[i] && usedAlphabet2[i];
	}

	bool isUsedOneSide(bool usedAlphabet1[26], bool usedAlphabet2[26], int i)
	{
		return (usedAlphabet1[i] && !usedAlphabet2[i]) ||
			(!usedAlphabet1[i] && usedAlphabet2[i]);
	}

	int getAlphaPoint(const string& input1, const string& input2)
	{
		invalidArgumentCheckForAlpha(input1, input2);

		bool usedAlphabet1[26] = { false, };
		bool usedAlphabet2[26] = { false, };
		bool isAllDifferent = true;
		bool isAllSame = true;
		int totalCnt = 0, sameCnt = 0;

		for (char c : input1) usedAlphabet1[c - 'A'] = true;
		for (char c : input2) usedAlphabet2[c - 'A'] = true;

		for (int i = 0; i < 26; i++)
		{
			if (isUsedBothSide(usedAlphabet1, usedAlphabet2, i)) isAllDifferent = false;
			if (isUsedOneSide(usedAlphabet1, usedAlphabet2, i)) isAllSame = false;

			if (usedAlphabet1[i] || usedAlphabet2[i]) totalCnt++;
			if (isUsedBothSide(usedAlphabet1, usedAlphabet2, i)) sameCnt++;
		}

		cout << totalCnt << endl;
		cout << sameCnt << endl;

		if (isAllDifferent) return 0;
		if (isAllSame) return ALPHA_MAX_POINT;

		return (sameCnt * ALPHA_MAX_POINT) / totalCnt;
	}

private:
	const int ALPHA_MAX_POINT = 40;
};