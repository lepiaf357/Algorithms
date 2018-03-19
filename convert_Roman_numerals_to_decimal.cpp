#include <iostream>
#include <string>

// IV, IX
// XL, XC
// CD, CM

int GetRomanCharValue(const char c)
{
	switch(c)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;		
	}
}

int ToDecimal(const std::string& strRoman)
{
	int iDecimal = 0;

	for (auto it = strRoman.begin(); it != strRoman.end(); ++it)
	{
		int iRomanCharValue = GetRomanCharValue(*it);
		if ((iRomanCharValue == 1 || iRomanCharValue == 10 || iRomanCharValue == 100) &&
			(it + 1 != strRoman.end()) && 
			GetRomanCharValue(*(it + 1)) > iRomanCharValue) 
		{
			iRomanCharValue = GetRomanCharValue(*(it + 1)) - iRomanCharValue;
			++it;
		}

		iDecimal += iRomanCharValue;
	}

	return iDecimal;
}

int main()
{
	std::string strRoman;
	std::cin >> strRoman;

	std::cout << ToDecimal(strRoman) << std::endl;

	return 0;
}