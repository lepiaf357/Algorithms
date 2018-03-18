#include <iostream>
#include <vector>
#include <unordered_set>

bool IfDuplicatesExcistWithinKDistance(const std::vector<int>& vecNums, int k)
{
	int iLength = vecNums.size();

	if (iLength < k)
	{
		return false;
	}

	std::unordered_set<int> usetVisited;
	usetVisited.insert(vecNums.begin(), vecNums.begin() + k);

	if (usetVisited.size() < k)
	{
		return true;
	}

	for (int iStart = 0, iEnd = k; iEnd < iLength; ++iStart, ++iEnd)
	{
		if (usetVisited.find(vecNums[iEnd]) != usetVisited.end())
		{
			return true;
		}
		usetVisited.erase(vecNums[iStart]);
		usetVisited.insert(vecNums[iEnd]);
	}

	return false;
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

	int k;
	std::cin >> k;

	std::cout << (IfDuplicatesExcistWithinKDistance(vecNums, k) ? "true" : "false") << std::endl;

	return 0;
}