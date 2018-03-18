#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int MaxAreaUnderHistogram(const std::vector<int>& vecHist)
{
	int iLength = vecHist.size();

	std::stack<int> sHistIndexes;
	int iMaxArea = 0;

	int i = 0;
	while (i < iLength)
	{
		if (sHistIndexes.empty() || vecHist[sHistIndexes.top()] <= vecHist[i])
		{
			sHistIndexes.push(i);
			++i;
		}
		else
		{
			int iStackTop = sHistIndexes.top();
			sHistIndexes.pop();

			iMaxArea = std::max(iMaxArea, vecHist[iStackTop] * (sHistIndexes.empty() ? i : (i - sHistIndexes.top() - 1)));
		}
	}

	while (!sHistIndexes.empty())
	{
		int iStackTop = sHistIndexes.top();
		sHistIndexes.pop();

		iMaxArea = std::max(iMaxArea, vecHist[iStackTop] * (sHistIndexes.empty() ? i : (i - sHistIndexes.top() - 1)));
	}

	return iMaxArea;
}

int MaxSizeRectangleOf1s(const std::vector<std::vector<int>>& matrixNums)
{
	int n = matrixNums.size();
	int m = matrixNums[0].size();

	int iMaxSize = 0;
	std::vector<int> vecRow(m, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vecRow[j] = (matrixNums[i][j] == 0) ? 0 : vecRow[j] + matrixNums[i][j];
		}
		iMaxSize = std::max(iMaxSize, MaxAreaUnderHistogram(vecRow));
	}

	return iMaxSize;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> matrixNums(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> matrixNums[i][j];
		}
	}

	std::cout << MaxSizeRectangleOf1s(matrixNums) << std::endl;

	return 0;
}