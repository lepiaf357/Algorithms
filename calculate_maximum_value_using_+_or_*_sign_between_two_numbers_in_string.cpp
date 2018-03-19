#include <iostream>
#include <string>
#include <algorithm>

void PrintMaxValueSeq(const std::string& strNum)
{
	int iMax = *(strNum.begin()) - '0';

	for (auto it = strNum.begin() + 1; it != strNum.end(); ++it)
	{
		if (*it == '1' || *it == '0' || iMax <= 1)
		{
			iMax += *it - '0';
		}
		else
		{
			iMax *= *it - '0';
		}
	}

	std::cout << iMax << std::endl;
}

int main()
{
	std::string strNum;
	std::cin >> strNum;
	PrintMaxValueSeq(strNum);

	return 0;
}