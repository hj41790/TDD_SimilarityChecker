#include <iostream>

using namespace std;

class SimilarityChecker
{
public:
	bool isSameLength(const string& input1, const string& input2)
	{
		return input1.length() == input2.length();
	}

	bool isDoubleLength(const string& input1, const string& input2)
	{
		return input1.length() == input2.length() * 2 ||
			input2.length() == input1.length() * 2;
	}

	int getPartialPointForLength(const string& input1, const string& input2)
	{
		int gap, min;

		if (input1.length() > input2.length())
		{
			gap = input1.length() - input2.length();
			min = input2.length();
		}
		else
		{
			gap = input2.length() - input1.length();
			min = input1.length();
		}

		return 60 - ((60 * gap) / min);
	}

	int getLengthPoint(const string& input1, const string& input2)
	{
		if (isSameLength(input1, input2)) return 60;

		if (isDoubleLength(input1, input2)) return 0;

		return getPartialPointForLength(input1, input2);
	}
};
