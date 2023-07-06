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

		bool usedAlphabet[26] = { false, };
		bool isAllDifferent = true;

		for (char c : input1)
		{
			usedAlphabet[c - 'A'] = true;
		}

		for (char c : input2)
		{
			if (usedAlphabet[c-'A'])
			{
				isAllDifferent = false;
			}
		}

		if (isAllDifferent) return 0;

		return 0;
	}
};