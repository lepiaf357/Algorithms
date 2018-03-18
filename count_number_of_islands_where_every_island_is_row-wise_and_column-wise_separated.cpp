#include <iostream>
#include <vector>

int CountIslands(std::vector<std::vector<char>>& matrixIslands, int n, int m)
{
	int iCount = 0;

	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrixIslands[i][j] == 'x')
			{
				// if ((i == 0 && j == 0) ||
				// 	(i == 0 && matrixIslands[i][j - 1] == 'o') ||
				// 	(j == 0 && matrixIslands[i - 1][j] == 'o') ||
				// 	(matrixIslands[i - 1][j] == 'o' && matrixIslands[i][j - 1] == 'o'))
				// {
				// 	++iCount;
				// }

				if ((i == 0 || matrixIslands[i - 1][j] == 'o') &&
					(j == 0 || matrixIslands[i][j - 1] == 'o'))
				{
					++iCount;
				}
			}
		}
	}

	return iCount;
}

int main()
{
	int n, m;

	std::cin >> n;
	std::cin >> m;

	std::vector<std::vector<char>> matrixIslands(n, std::vector<char>(m));

	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> matrixIslands[i][j];
		}
	}

	std::cout << CountIslands(matrixIslands, n, m) << std::endl;

	return 0;
}