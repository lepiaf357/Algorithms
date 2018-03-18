#include <iostream>
#include <vector>

void PrintSortedSubsequenceOfSize3(const std::vector<int>& vecNums)
{
	int iLength = vecNums.size();
	std::vector<int> vecSmaller(iLength, -1);

	int iMin = 0;
	for (int i = 1; i < iLength; ++i)
	{
		if (vecNums[iMin] < vecNums[i])
		{
			vecSmaller[i] = iMin;
		}
		else
		{
			iMin = i;
		}
	}

	int iMax = iLength - 1;
	for (int i = iLength - 2; i >= 0; --i)
	{
		if (vecNums[iMax] > vecNums[i])
		{
			if (vecSmaller[i] != -1)
			{
				std::cout << vecNums[vecSmaller[i]] << " " << vecNums[i] << " " << vecNums[iMax] << std::endl;
				return;
			}
		}
		else
		{
			iMax = i;
		}
	}

	std::cout << "Not possible." << std::endl;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> vecNums(n);
	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		std::cin >> *it;
	}

	PrintSortedSubsequenceOfSize3(vecNums);

	return 0;
}