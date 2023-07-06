#include <iostream>

using namespace std;

class SimilarityChecker
{
public:
	bool isDoubleLength(const string& input1, const string& input2)
	{
		return input1.length() == input2.length() * 2 ||
			input2.length() == input1.length() * 2;
	}

	int getLengthPoint(const string& input1, const string& input2)
	{
		if (input1.length() == input2.length()) return 60;

		if (isDoubleLength(input1, input2)) return 0;

		return 0;
	}
};
