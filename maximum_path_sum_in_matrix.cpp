#include <iostream>
#include <vector>
#include <algorithm>

// if i == n
// return 0
//// if j == 0
//// return a[i][j] + max(f(a[i+1][j]), f(a[i+1][j+1]))
//// if j == m-1
//// return a[i][j] + max(f(a[i+1][j]), f(a[i+1][j-1]))
//// or only:
//if (j < 0 || j > m - 1)
// return 0
// return a[i][j] + max(f(a[i+1][j]), f(a[i+1][j-1]), f(a[i+1][j+1]))
void FindAndPrintMaxPathSum(const std::vector<std::vector<int>>& matrixNums, int n, int m)
{
	std::vector<std::vector<int>> matrixMaxPathSum(n + 1, std::vector<int>(m + 2, 0));

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 1; j <= m; ++j)
		{
			matrixMaxPathSum[i][j] = matrixNums[i][j - 1] + std::max(matrixMaxPathSum[i + 1][j - 1], std::max(matrixMaxPathSum[i + 1][j], matrixMaxPathSum[i + 1][j + 1]));
		}
	}

	int iMaxSum = 0;
	int iMaxSumStartInd = -1;
	for (int j = 1; j <= m; ++j)
	{
		if (matrixMaxPathSum[0][j] > iMaxSum)
		{
			iMaxSum = matrixMaxPathSum[0][j];
			iMaxSumStartInd = j;
		}
	}

	std::cout << "Max sum: " << iMaxSum << std::endl;

	int j = iMaxSumStartInd;
	for (int i = 0; i < n; ++i)
	{
		std::cout << matrixNums[i][j - 1] << "-";

		if (matrixMaxPathSum[i + 1][j - 1] > matrixMaxPathSum[i + 1][j])
		{
			if (matrixMaxPathSum[i + 1][j - 1] > matrixMaxPathSum[i + 1][j + 1])
			{
				--j;
			}
			else
			{
				++j;
			}
		}
		else if (matrixMaxPathSum[i + 1][j + 1] > matrixMaxPathSum[i + 1][j])
		{
			++j;
		}
	}
	std::cout << std::endl;
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

	FindAndPrintMaxPathSum(matrixNums, n, m);

	return 0;
}