#include <iostream>

using namespace std;

class SimilarityChecker
{
public:
	int getLengthPoint(const string& input1, const string& input2)
	{
		if (input1.length() == input2.length()) return 60;

		return 0;
	}
};
