#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int CalculateAreaForTopElem(std::stack<int>& sHistIndexes, const std::vector<int>& vecHist, int i)
{
	int iStackTop = sHistIndexes.top();
	sHistIndexes.pop();

	int iWidth = (sHistIndexes.empty() ? i : (i - sHistIndexes.top() - 1));
	if (iWidth == vecHist[iStackTop])
	{
		return iWidth * iWidth;
	}

	return 0;
}

int MaxSquareAreaUnderHistogram(const std::vector<int>& vecHist)
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
			iMaxArea = std::max(iMaxArea, CalculateAreaForTopElem(sHistIndexes, vecHist, i));
		}
	}

	while (!sHistIndexes.empty())
	{
		iMaxArea = std::max(iMaxArea, CalculateAreaForTopElem(sHistIndexes, vecHist, i));
	}

	return iMaxArea;
}

int MaxSizeSquareOf1s(const std::vector<std::vector<int>>& matrixNums)
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
		iMaxSize = std::max(iMaxSize, MaxSquareAreaUnderHistogram(vecRow));
	}

	return iMaxSize;
}

// second method
int MaxSizeSquareOf1s2(const std::vector<std::vector<int>>& matrixNums)
{
	int n = matrixNums.size();
	int m = matrixNums[0].size();

	std::vector<std::vector<int>> matrixSize = matrixNums;
	int iMaxSize = 0;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			matrixSize[i][j] = matrixNums[i][j] == 0 ? 0 : std::min(matrixSize[i - 1][j - 1], std::min(matrixSize[i][j - 1], matrixSize[i - 1][j])) + 1;
			iMaxSize = std::max(iMaxSize, matrixSize[i][j]);
		}
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

	std::cout << MaxSizeSquareOf1s(matrixNums) << std::endl;
	std::cout << MaxSizeSquareOf1s2(matrixNums) << std::endl;

	return 0;
}