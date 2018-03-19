#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>


void PrintSmallestSubarray(const std::vector<int>& vecNums, int iGivenSum)
{
	int iLen = vecNums.size();
	int iMin = iLen + 1; // Not possible

	int iStrat = 0;
	int iEnd = 0;

	int iCurrentSum = vecNums[iEnd];
	while (iEnd < iLen)
	{
		while (iCurrentSum < iGivenSum && iEnd < iLen)
		{
			// handle neg numbers
			if (iCurrentSum <= 0 && iGivenSum > 0)
			{
				iStrat = iEnd;
				iCurrentSum = 0;
			}

			iCurrentSum += vecNums[iEnd];
			++iEnd;
		}

		// > if it is only greather, in first while <=
		while (iCurrentSum >= iGivenSum && iStrat <= iEnd)
		{
			if (iEnd - iStrat < iMin)
			{
				iMin = iEnd - iStrat;
			}

			iCurrentSum -= vecNums[iStrat];
			++iStrat;
		}
	}

	if (iMin == iLen + 1)
	{
		std::cout << "Not possible!" << std::endl;
	}
	else
	{
		std::cout << iMin << std::endl;
	}
}

int main()
{
	std::string strLine;
	std::getline(std::cin, strLine);

	std::istringstream iss(strLine);

	std::vector<int> vecNums;
	int iNum;
	while (iss >> iNum)
	{
		vecNums.push_back(iNum);
	}
	//std::vector<int> vecNums = {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};

	std::cin >> iNum;

	PrintSmallestSubarray(vecNums, iNum);

	return 0;
}