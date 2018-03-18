#include <iostream>
#include <vector>
#include <cmath>

void PrintElementsThatAppearsTwice(const std::vector<int>& vecNums)
{
	int iElementX, iElementY;

	int S = 0, P = 1;
	int nS = 0, nP = 1;

	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		S += *it;
		P *= *it;
	}

	for (int i = 1; i <= vecNums.size() - 2; ++i)
	{
		nS += i;
		nP *= i;
	}

	int sumXY = S - nS;
	int prodXY = P / nP;
	// (x+y)^2 - (x-y)^2 = 4xy
	// x-y = sqrt((x+y)^2 - 4xy)
	int subXY = std::sqrt(sumXY * sumXY - 4 * prodXY);

	// x + y + x - y = 2x
	iElementX = (sumXY + subXY) / 2;
	iElementY = sumXY - iElementX;

	std::cout << iElementX << " " << iElementY << std::endl;
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

	PrintElementsThatAppearsTwice(vecNums);

	return 0;
}