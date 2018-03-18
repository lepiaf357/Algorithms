#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<std::pair<int,int>> MergeIntervals(const std::vector<std::pair<int,int>>& vecIntervals)
{
	std::vector<std::pair<int,int>> vecMergedIntervals = vecIntervals;

	// O(nlogn)
	std::sort(vecMergedIntervals.begin(), vecMergedIntervals.end());

	// O(n)
	auto it = vecMergedIntervals.begin(); 
	while (it <= vecMergedIntervals.end() - 1)
	{
		// 1 4 & 3 5
		// 1 4 & 2 3
		while (it != vecMergedIntervals.end() - 1 && (it + 1)->first <= it->second)
		{
			it->second = std::max(it->second, (it + 1)->second);
			it = vecMergedIntervals.erase(it + 1);
			--it;
		}
		++it;
	}

	return vecMergedIntervals;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::pair<int,int>> vecIntervals(n);
	for (int i = 0; i < n; ++i)
	{
			std::cin >> vecIntervals[i].first >> vecIntervals[i].second;
	}

	const std::vector<std::pair<int,int>>& vecMergedIntervals = MergeIntervals(vecIntervals);
	
	for (auto it = vecMergedIntervals.begin(); it != vecMergedIntervals.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	return 0;
}