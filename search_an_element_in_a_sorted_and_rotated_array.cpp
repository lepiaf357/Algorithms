#include <iostream>
#include <vector>

// 4 5 1 2 3
int FindXInSortedAndRotated(const std::vector<int>& vecNums, int x)
{
	int iLeft = 0;
	int iRight = vecNums.size() - 1;
	int iMidd;

	while (iLeft <= iRight)
	{
		iMidd = (iLeft + iRight + 1) / 2;

		if (x == vecNums[iMidd])
		{
			return iMidd;
		}

		if (vecNums[iLeft] <= vecNums[iMidd])
		{
			if (x >= vecNums[iLeft])
			{
				iRight = iMidd - 1;
			}
			else
			{
				iLeft = iMidd + 1;
			}
		}
		else (vecNums[iRight] >= vecNums[iMidd])
		{
			if (x <= vecNums[iRight])
			{
				iLeft = iMidd + 1;
			}
			else
			{
				iRight = iMidd - 1;
			}
		}
	}

	return -1;
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

	int x;
	std::cin >> x;

	std::cout << FindXInSortedAndRotated(vecNums, x) << std::endl;

	return 0;
}