#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void FindAndPrintLargestSubArrWithEql01(const std::vector<int>& vecNums)
{
	int iLength = vecNums.size();
	std::unordered_map<int,int> umapSums;
	int iSum = 0;

	int iEnd = 0;
	for (int i = 0; i < iLength; ++i)
	{
		iSum += (vecNums[i] == 1 ? 1 : -1);
		if (iSum == 0)
		{
			iEnd = i;
		}
	}

	iSum = 0;
	int iMaxSum = 0;
	int iMaxIntervalLength = 0;
	for (int i = 0; i < iLength; ++i)
	{
		iSum += (vecNums[i] == 1 ? 1 : -1);
		if (umapSums.find(iSum) != umapSums.end())
		{
			if (i - umapSums[iSum] > iMaxIntervalLength)
			{
				iMaxSum = iSum;
				iMaxIntervalLength = i - umapSums[iSum];
			}
		}
		else
		{
			umapSums[iSum] = i;
		}
	}

	if (iMaxIntervalLength > iEnd + 1)
	{
		std::cout << umapSums[iMaxSum] + 1 << " " << iMaxIntervalLength - umapSums[iMaxSum] << std::endl;
	}
	else if (iEnd == 0)
	{
		std::cout << "NO SUCH SUBARRAY" << std::endl;
	}
	else
	{
		std::cout << "0 " << iEnd << std::endl;
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> vecNums(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> vecNums[i];
	}

	FindAndPrintLargestSubArrWithEql01(vecNums);

	return 0;
}