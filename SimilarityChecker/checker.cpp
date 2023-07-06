#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphaPoint(const string& input1, const string& input2)
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

		return 0;
	}
};