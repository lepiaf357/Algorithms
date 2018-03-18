#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

// if i >= n
// return 0
// if vec[i] = 0
// return INT_MAX
// return 1 + min(f(i+   from 1 to vec[i])) 
int MinJumps(const std::vector<int>& vecNums)
{
	int iLength = vecNums.size();
	std::vector<int> vecJumps(iLength + 1, 0);

	for (int i = iLength - 1; i >= 0; --i)
	{
		if (vecNums[i] == 0)
		{
			vecJumps[i] = INT_MAX;
			continue;
		}

		int iMin = INT_MAX;
		for (int j = 1; j <= vecNums[i]; ++j)
		{
			if (i + j >= iLength)
			{
				iMin = 0;
				break;
			}
			iMin = std::min(iMin, vecJumps[i + j]);
		}

		if (iMin == INT_MAX)
		{
			vecJumps[i] = iMin;
		}
		else
		{
			vecJumps[i] = 1 + iMin;
		}
	}

	for (int i = 0; i <= iLength; ++i)
	{
		std::cout << vecJumps[i] << " ";
	}
	return vecJumps[0];
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

	std::cout << MinJumps(vecNums) << std::endl;

	return 0;
}