#include <iostream>
#include <vector>
#include <algorithm>

int NumOfPossibleTriangles(std::vector<int> vecNums)
{
	int iLength = vecNums.size();
	int iCount = 0;

	std::sort(vecNums.begin(), vecNums.end());

	for (int i = 0; i <= iLength - 3; ++i)
	{
		for (int j = i + 1; j <= iLength - 2; ++j)
		{
			int k = iLength - 1;

			while (j < k)
			{
				if (vecNums[j] + vecNums[i] > vecNums[k])
				{
					iCount += k - j;
					break;
				}
				else
				{
					--k;
				}
			}
		}
	}

	return iCount;
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

	std::cout << NumOfPossibleTriangles(vecNums) << std::endl;

	return 0;
}