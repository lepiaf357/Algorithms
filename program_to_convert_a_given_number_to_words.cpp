#include <iostream>
#include <string>
#include <vector>

void PrintNumber(int iNum)
{
	std::string strDig[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string strFirstTens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	std::string strTens[] = {"", "", "twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};

	std::string strNum;
	int i;

	i = iNum / 1000;
	if (i != 0)
	{
		strNum += strDig[i] + " thousand";
	}
	iNum = iNum % 1000;

	i = iNum / 100;
	if (i != 0)
	{
		if (!strNum.empty())
		{
			strNum += " ";
		}

		strNum += strDig[i] + " hundered";
	}
	iNum = iNum % 100;

	i = iNum / 10;
	if (i > 0)
	{
		if (!strNum.empty())
		{
			strNum += " ";
		}

		if (i == 1)
		{
			strNum += strFirstTens[iNum%10];
		}
		else
		{
			strNum += strTens[i];
		}
	}
	iNum = iNum % 10;

	if (i != 1)
	{
		if (!strNum.empty())
		{
			strNum += " ";
		}

		strNum += strDig[iNum];
	}

	std::cout << strNum << std::endl;
}

void PrintNumber2(int iNum)
{
	const std::vector<std::string> strSingleDigits = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const std::vector<std::string> strTwoDigits = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	const std::vector<std::string> strTensMultiple = {"", "", "twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};
	const std::vector<std::string> strTensPower = {"", "", "hundered", "thousand"};

	std::string strNum = std::to_string(iNum);
	std::string strWords;

	if (strNum.size() > strTensPower.size())
	{
		std::cout << "Unsupported num! Support numbers up to 10^" << strTensPower.size() << std::endl;
		return;
	}

	std::string::const_iterator it = strNum.begin();
	for (int i = strNum.size() - 1; i >= 0; --i, ++it)
	{
		if (*it == '0')
		{
			continue;
		}

		if (!strWords.empty())
		{
			strWords += " ";
		}

		if (i == 0)
		{
			strWords += strSingleDigits[*it - '0'];
		}
		else if (i == 1)
		{
			if (*it - '0' != 1)
			{
				strWords += strTensMultiple[*it - '0'];
			}
			else
			{
				strWords += strTwoDigits[*(it + 1) - '0'];
				break;
			}
		}
		else
		{
			strWords += strSingleDigits[*it - '0'];
			strWords = strWords + " " +  strTensPower[i];
		}
	}

	std::cout << strWords << std::endl;
}

int main()
{
	int iNum;
	std::cin >> iNum;

	PrintNumber2(iNum);

	return 0;
}