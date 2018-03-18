#include <iostream>
#include <vector>

int MaximumNumOf1sRow(const std::vector<std::vector<int>>& matrix0s1s)
{
	int iMaxRow = -1;
	int iMaxNumOf1s = 0;
	int n = matrix0s1s.size();
	int m = matrix0s1s[0].size();

	int j = m - 1;
	for (int i = 0; i < n; ++i)
	{
		// int iNumOf1sInCurrentRow = iMaxNumOf1s;
		while (j >= 0 && matrix0s1s[i][j] == 1)
		{
			--j;
			iMaxRow = i; // update only row, do not count 1s
			//++iNumOf1sInCurrentRow;
		}

		// if (iNumOf1sInCurrentRow > iMaxNumOf1s)
		// {
		// 	iMaxNumOf1s = iNumOf1sInCurrentRow;
		// 	iMaxRow = i;
		// }

		// if (iMaxNumOf1s == m)
		// {
		// 	break;
		// }
	}
                         
	return iMaxRow;
}

int main()
{
	int n;
	std::cin >> n;

	int m;
	std::cin >> m;

	std::vector<std::vector<int>> matrix0s1s(n, std::vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> matrix0s1s[i][j];
		}
	}

	std::cout << MaximumNumOf1sRow(matrix0s1s) << std::endl;

	return 0;
}