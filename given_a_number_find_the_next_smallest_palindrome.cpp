#include <iostream>
#include <string>
#include <algorithm>

int PrintPalindromeLargestThanK(int k)
{
	std::string strNum = std::to_string(k);
	int iLen = strNum.size();
	bool bIncrement = false;

	std::string strLeft = strNum.substr(0, iLen / 2);
	std::string strMidd = (iLen % 2 == 0) ? "" : strNum.substr(iLen / 2, 1);
	std::string strRight = (iLen % 2 == 0) ? strNum.substr(iLen / 2) : strNum.substr(iLen / 2 + 1);

	std::string strLeftRev = strLeft;
	std::reverse(strLeftRev.begin(), strLeftRev.end());
	if (strLeftRev > strRight)
	{
		strNum = strLeft + strMidd + strLeftRev;
	}
	else
	{
		if (strMidd == "")
		{
			strLeft = std::to_string(std::stoi(strLeft) + 1);
		}
		else if (strMidd == "9")
		{
			strMidd = "0";
			strLeft = std::to_string(std::stoi(strLeft) + 1);
		}
		else
		{
			strMidd = std::to_string(std::stoi(strMidd) + 1);
		}

		strLeftRev = strLeft;
		std::reverse(strLeftRev.begin(), strLeftRev.end());

		strNum = strLeft + strMidd + strLeftRev;
	}

	return std::stoi(strNum);
}

int main()
{
	int k;
	std::cin >> k;

	std::cout << PrintPalindromeLargestThanK(k) << std::endl;
}