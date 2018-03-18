#include <iostream>
#include <vector>

void Sort012(std::vector<int>& vecNums)
{
	int iSort0End = -1;
	int iSort2Begin = vecNums.size();

	int iCurr = 0;
	while (iCurr != iSort2Begin)
	{
		if (vecNums[iCurr] == 0)
		{
			++iSort0End;
			vecNums[iCurr] = vecNums[iSort0End];
			vecNums[iSort0End] = 0;
		}
		else if (vecNums[iCurr] == 2)
		{
			--iSort2Begin;
			vecNums[iCurr] = vecNums[iSort2Begin];
			vecNums[iSort2Begin] = 2;
		}

		if (vecNums[iCurr] == 1 ||
			iCurr == iSort2Begin ||
			iCurr == iSort0End)
		{
			++iCurr;
		}
	}
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

	Sort012(vecNums);

	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}