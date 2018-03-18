#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<int> vecStoredElems;

int FindKthSmallest(int k)
{
	return (k > vecStoredElems.size() ? -1 : vecStoredElems[k - 1]);
}

void StoreElementsByOrder(std::vector<std::pair<int, int>> vecIntervals)
{
	std::sort(vecIntervals.begin(), vecIntervals.end());

	std::pair<int, int> pairInterval = vecIntervals[0];
	for (int i = 1; i < vecIntervals.size(); ++i)
	{
		if (vecIntervals[i].first <= pairInterval.second)
		{
			pairInterval.second = std::max(pairInterval.second, vecIntervals[i].second);
		}
		else
		{
			for(int iElem = pairInterval.first; iElem <= pairInterval.second; ++iElem)
			{
				vecStoredElems.push_back(iElem);
			}

			pairInterval = vecIntervals[i];
		}
	}

	for(int iElem = pairInterval.first; iElem <= pairInterval.second; ++iElem)
	{
		vecStoredElems.push_back(iElem);
	}
}

// second method, without extra memory
void SortAndMergeIntervals(std::vector<std::pair<int, int>>& vecMergedIntervals)
{
	std::sort(vecMergedIntervals.begin(), vecMergedIntervals.end());
	
	for (auto it = vecMergedIntervals.begin() + 1; it != vecMergedIntervals.end();)
	{
		if (it->first <= (it - 1)->second)
		{
			(it - 1)->second = std::max(it->second, (it - 1)->second);
			it = vecMergedIntervals.erase(it);
		}
		else
		{
			++it;
		}
	}
}

int FindKthSmallestElement(const std::vector<std::pair<int, int>>& vecMergedIntervals, int k)
{
	int iCurrentNumOfElems;
	for (auto it = vecMergedIntervals.begin(); it != vecMergedIntervals.end(); ++it)
	{
		iCurrentNumOfElems = it->second - it->first + 1;
		if (k <= iCurrentNumOfElems)
		{
			return it->first + k - 1;
		}
		else
		{
			k -= iCurrentNumOfElems;
		}
	}

	return -1;
}

int main()
{
	// Read from stdin
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> vecIntervals(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> vecIntervals[i].first >> vecIntervals[i].second;
	}

	int q;
	std::cin >> q;

	std::vector<int> vecQueries(q);
	for (int  i = 0; i < q; ++i)
	{
		std::cin >> vecQueries[i];
	}

	// Fill/store elems before start with queries
	StoreElementsByOrder(vecIntervals);

	// For each query find smallest
	for (int  i = 0; i < q; ++i)
	{
		std::cout << FindKthSmallest(vecQueries[i]) << std::endl;
	}

	// second method
	std::vector<std::pair<int,int>> vecMergedIntervals = vecIntervals;
	SortAndMergeIntervals(vecMergedIntervals);
	for (int i = 0; i < q; ++i)
	{
		std::cout << FindKthSmallestElement(vecMergedIntervals, vecQueries[i]) << std::endl;
	}

	return 0;
}