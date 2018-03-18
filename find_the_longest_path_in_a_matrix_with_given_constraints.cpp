#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int LongestPathIncreasingBy1(const std::vector<std::vector<int>>& matrixNums)
{
	int n = matrixNums.size();

	std::vector<std::vector<int>> matrixMaxPaths(n, std::vector<int>(n, -1));
	std::queue<std::pair<int,int>> qPath;

	int iMaxSum = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrixMaxPaths[i][j] != -1)
			{
				continue;
			}

			int iPath = i;
			int jPath = j;
			
			int iCurrPathLen = 1;
			
			while (true)
			{
				qPath.push(std::make_pair(iPath, jPath));

				if (iPath > 0 && matrixNums[iPath - 1][jPath] == matrixNums[iPath][jPath] + 1)
				{
					if (matrixMaxPaths[iPath - 1][jPath] != -1)
					{
						iCurrPathLen += matrixMaxPaths[iPath - 1][jPath];
						break;
					}
					else
					{
						++iCurrPathLen;
						iPath = iPath - 1;
					}
				}
				else if (iPath < n - 1 && matrixNums[iPath + 1][jPath] == matrixNums[iPath][jPath] + 1)
				{
					if (matrixMaxPaths[iPath + 1][jPath] != -1)
					{
						iCurrPathLen += matrixMaxPaths[iPath + 1][jPath];
						break;
					}
					else
					{
						++iCurrPathLen;
						iPath = iPath + 1;
					}
				}
				else if (jPath > 0 && matrixNums[iPath][jPath - 1] == matrixNums[iPath][jPath] + 1)
				{
					if (matrixMaxPaths[iPath][jPath - 1] != -1)
					{
						iCurrPathLen += matrixMaxPaths[iPath][jPath - 1];
						break;
					}
					else
					{
						++iCurrPathLen;
						jPath = jPath - 1;
					}
				}
				else if (jPath < n - 1 && matrixNums[iPath][jPath + 1] == matrixNums[iPath][jPath] + 1)
				{
					if (matrixMaxPaths[iPath][jPath + 1] != -1)
					{
						iCurrPathLen += matrixMaxPaths[iPath][jPath + 1];
						break;
					}
					else
					{
						++iCurrPathLen;
						jPath = jPath + 1;
					}
				}
				else
				{
					break;
				}
			}

			iMaxSum = std::max(iMaxSum, iCurrPathLen);

			while (!qPath.empty())
			{
				auto ijPos = qPath.front();
				qPath.pop();

				if (matrixMaxPaths[ijPos.first][ijPos.second] != -1)
				{
					break;
				}

				matrixMaxPaths[ijPos.first][ijPos.second] = iCurrPathLen;
				--iCurrPathLen;				
			}
		}
	}

	return iMaxSum;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> matrixNums(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> matrixNums[i][j];
		}
	}

	std::cout << LongestPathIncreasingBy1(matrixNums) << std::endl;

	return 0;
}