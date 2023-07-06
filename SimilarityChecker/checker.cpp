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

	int getAlphaPoint(const string& input1, const string& input2)
	{
		invalidArgumentCheckForAlpha(input1, input2);
		
		bool usedAlphabet1[26] = { false, };
		bool usedAlphabet2[26] = { false, };
		bool isAllDifferent = true;
		bool isAllSame = true;

		for (char c : input1) usedAlphabet1[c - 'A'] = true;
		for (char c : input2) usedAlphabet2[c - 'A'] = true;

		for (int i = 0; i < 26; i++)
		{
			if (usedAlphabet1[i] && usedAlphabet2[i]) isAllDifferent = false;
			if ((usedAlphabet1[i] && !usedAlphabet2[i]) ||
				(!usedAlphabet1[i] && usedAlphabet2[i]))
				isAllSame = false;
		}

		if (isAllDifferent) return 0;
		if (isAllSame) return 40;

		return 0;
	}
};