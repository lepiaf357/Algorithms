#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// if i == n || i == n-1
// return 1
// if ((str[i] == 1 || (str[i] == 2 && str[i+1] <= 6)))
// return f(i+2) + f(i+1)
// else 
// return f(i+1)


int main()
{
	std::string strNum;
	std::cin >> strNum;

	int iLen = strNum.size();

	int i2 = 1;
	int i1 = 1;
	int i;

	for (int j = iLen - 2; j >= 0; --j)
	{
		if (strNum[j] == '1' || (strNum[j] == '2' && strNum[j + 1] <= '6'))
		{
			i =  i2 + i1;
		}
		else
		{
			i = i1;
		}

		i2 = i1;
		i1 = i;
	}

	std::cout << i1 << std::endl;
	return 0;
}