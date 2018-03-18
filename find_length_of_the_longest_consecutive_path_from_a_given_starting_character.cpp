#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct item
{
	int i;
	int j;
	int* parent;
};

int CalculateLongestPath(const std::vector<std::vector<char>>& matrixCharacters, std::vector<std::vector<int>>& matrixPaths, int i, int j)
{
	int n = matrixCharacters.size();
	int m = matrixCharacters[0].size();
	
	matrixPaths[i][j] = 1;

	std::stack<item> sItems;
	std::stack<std::pair<int,int>> sDFS;

	sItems.push({i, j, nullptr});
	sDFS.push(std::make_pair(i,j));

	while (!sDFS.empty())
	{
		auto DFSelem = sDFS.top();
		int i = DFSelem.first;
		int j = DFSelem.second;

		sDFS.pop();

		if (i > 0 && j > 0 && matrixCharacters[i - 1][j - 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i - 1][j - 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i - 1][j - 1] + 1);
			}
			else
			{
				matrixPaths[i - 1][j - 1] = 1;
				sDFS.push(std::make_pair(i - 1, j - 1));
				sItems.push({i - 1, j - 1, &matrixPaths[i][j]});
			}
		}

		if (i > 0 && matrixCharacters[i - 1][j] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i - 1][j] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i - 1][j] + 1);
			}
			else
			{
				matrixPaths[i - 1][j] = 1;
				sDFS.push(std::make_pair(i - 1, j));
				sItems.push({i - 1, j, &matrixPaths[i][j]});
			}
		}

		if (i > 0 && j < m - 1 && matrixCharacters[i - 1][j + 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i - 1][j + 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i - 1][j + 1] + 1);
			}
			else
			{
				matrixPaths[i - 1][j + 1] = 1;
				sDFS.push(std::make_pair(i - 1, j + 1));
				sItems.push({i - 1, j + 1, &matrixPaths[i][j]});
			}
		}

		if (j < m - 1 && matrixCharacters[i][j + 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i][j + 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i][j + 1] + 1);
			}
			else
			{
				matrixPaths[i][j + 1] = 1;
				sDFS.push(std::make_pair(i, j + 1));
				sItems.push({i, j + 1, &matrixPaths[i][j]});
			}
		}

		if (i < n - 1 && j < m - 1 && matrixCharacters[i + 1][j + 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i + 1][j + 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i + 1][j + 1] + 1);
			}
			else
			{
				matrixPaths[i + 1][j + 1] = 1;
				sDFS.push(std::make_pair(i + 1, j + 1));
				sItems.push({i + 1, j + 1, &matrixPaths[i][j]});
			}
		}

		if (i < n - 1 && matrixCharacters[i + 1][j] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i + 1][j] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i + 1][j] + 1);
			}
			else
			{
				matrixPaths[i + 1][j] = 1;
				sDFS.push(std::make_pair(i + 1, j));
				sItems.push({i + 1, j, &matrixPaths[i][j]});
			}
		}

		if (i < n - 1 && j > 0 && matrixCharacters[i + 1][j - 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i + 1][j - 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i + 1][j - 1] + 1);
			}
			else
			{
				matrixPaths[i + 1][j - 1] = 1;
				sDFS.push(std::make_pair(i + 1, j - 1));
				sItems.push({i + 1, j - 1, &matrixPaths[i][j]});
			}
		}

		if (j > 0 && matrixCharacters[i][j - 1] == matrixCharacters[i][j] + 1)
		{
			if (matrixPaths[i][j - 1] != -1)
			{
				matrixPaths[i][j] = std::max(matrixPaths[i][j], matrixPaths[i][j - 1] + 1);
			}
			else
			{
				matrixPaths[i][j - 1] = 1;
				sDFS.push(std::make_pair(i, j - 1));
				sItems.push({i, j - 1, &matrixPaths[i][j]});
			}
		}
	}

	while (!sItems.empty())
	{
		auto it = sItems.top();
		int i = it.i;
		int j = it.j;
		
		sItems.pop();

		if (it.parent != nullptr)
		{
			*it.parent = std::max(*it.parent, matrixPaths[i][j] + 1);
		}
	}

	return matrixPaths[i][j];

}

int LongestConsecutivePath(const std::vector<std::vector<char>>& matrixCharacters, char cStart)
{
	int n = matrixCharacters.size();
	int m = matrixCharacters[0].size();

	int iLongestPath = 0;
	std::vector<std::vector<int>> matrixPaths(n, std::vector<int>(m, -1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrixCharacters[i][j] == cStart)
			{
				iLongestPath = std::max(iLongestPath, CalculateLongestPath(matrixCharacters, matrixPaths, i, j));
			}
		}
	}

	return iLongestPath;
}


// second method
// recursion + DP matrix + cool methods :)

std::vector<int> vecI = {-1, -1, -1, 0, 1, 1, 1, 0};
std::vector<int> vecJ = {-1, 0, 1, 1, 1, 0, -1, -1};

bool IsValid(int i, int j, int n, int m)
{
	return (i >= 0 && j >= 0 && i < n && j < m);
}

bool IsAdjacent(char cPrev, char cCurr)
{
	return (cCurr - cPrev == 1);
}

int CalculateLongestPath2(const std::vector<std::vector<char>>& matrixCharacters, std::vector<std::vector<int>>& matrixPaths, char cStart, int i, int j)
{
	if (!IsValid(i, j, matrixCharacters.size(), matrixCharacters[0].size()) || !IsAdjacent(cStart, matrixCharacters[i][j]))
	{
		return 0;
	}

	if (matrixPaths[i][j] != -1)
	{
		return matrixPaths[i][j];
	}

	int iMax = 0;
	for (int k = 0; k < 8; ++k)
	{
		iMax = std::max(iMax, 1 + CalculateLongestPath2(matrixCharacters, matrixPaths, matrixCharacters[i][j], i + vecI[k], j + vecJ[k]));
	}
	matrixPaths[i][j] = iMax;
	return iMax;
}

int LongestConsecutivePath2(const std::vector<std::vector<char>>& matrixCharacters, char cStart)
{
	int n = matrixCharacters.size();
	int m = matrixCharacters[0].size();

	int iLongestPath = 0;
	std::vector<std::vector<int>> matrixPaths(n, std::vector<int>(m, -1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrixCharacters[i][j] == cStart)
			{
				iLongestPath = std::max(iLongestPath, CalculateLongestPath2(matrixCharacters, matrixPaths, cStart - 1, i, j));
			}
		}
	}

	return iLongestPath;
}



int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<char>> matrixCharacters(n, std::vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			std::cin >> matrixCharacters[i][j];
		}
	}

	char cStart;
	std::cin >> cStart;

	std::cout << LongestConsecutivePath(matrixCharacters, cStart) << std::endl;
	std::cout << LongestConsecutivePath2(matrixCharacters, cStart) << std::endl;

	return 0;
}