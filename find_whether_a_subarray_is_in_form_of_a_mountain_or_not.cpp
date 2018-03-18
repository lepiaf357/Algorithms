#include <iostream>
#include <vector>
#include <algorithm>

bool IsMountain(int iStart, int iEnd, const std::vector<bool>& vecLocalMinimums, const std::vector<int>& vecMountines) 
{

	if ((iStart == iEnd) ||
		(vecLocalMinimums[iStart] && vecMountines[iStart] >= iEnd) ||
		(vecMountines[vecMountines[iStart]] >= iEnd))
	{
		return true;
	}

	return false;
}

void FillMountinesAndMinimums(std::vector<bool>& vecLocalMinimums, std::vector<int>& vecMountines, const std::vector<int>& vecNums)
{
	int iLocallMin = 0;
	vecLocalMinimums[0] = true;
	for (int i = 1; i < vecNums.size() - 1; ++i)
	{
		if (vecNums[i - 1] > vecNums[i] && vecNums[i + 1] > vecNums[i])
		{
			vecMountines[iLocallMin] = i;
			iLocallMin = i;
			vecLocalMinimums[iLocallMin] = true;
		}
		else
		{
			vecMountines[i] = iLocallMin;
		}
	}
	vecMountines[iLocallMin] = vecNums.size() - 1;
	vecLocalMinimums[vecNums.size() - 1] = true;
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

	std::vector<bool> vecLocalMinimums(n, false);
	std::vector<int> vecMountines(n);

	FillMountinesAndMinimums(vecLocalMinimums, vecMountines, vecNums);

	std::cout << "Start entering ranges..." << std::endl;
	int iStart, iEnd;
	while (true)
	{
		std::cin >> iStart;
		std::cin >> iEnd;
		std::cout << (IsMountain(iStart, iEnd, vecLocalMinimums, vecMountines) ? "YES" : "NO") << std::endl;
	}

	return 0;
}