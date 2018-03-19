#include <iostream>
#include <vector>
#include <string>

// Roman: tousends, hundereds, tens, ones
// all possible store in array

// num / 1000 = num of thousends
// num = num / 1000
// num / 100 = num of hundereds
// ...

std::string ToRoman(int iNum)
{
	std::vector<std::string> vecHundereds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	std::vector<std::string> vecTens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	std::vector<std::string> vecOnes = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

	std::string strRoman;

	int iThousends = iNum / 1000;
	while (iThousends--)
	{
		strRoman.push_back('M');
	}
	iNum = iNum % 1000;

	strRoman += vecHundereds[iNum / 100];
	iNum = iNum % 100;

	strRoman += vecTens[iNum / 10];
	iNum = iNum % 10;

	strRoman += vecOnes[iNum];

	return strRoman;
}

int main()
{
	int iNum;
	std::cin >> iNum;
	std::cout << ToRoman(iNum) << std::endl;

	return 0;
} 