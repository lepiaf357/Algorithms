#include <iostream>
#include <string>
#include <unordered_map>

void RearrangeCharacters(std::string& strIn)
{
	std::unordered_map<char,int> umapFreq;
	int iMaxFreq = 0;
	char cMaxFreq;

	for (int i = 0; i < strIn.size(); ++i)
	{
		umapFreq[strIn[i]]++;
		if (umapFreq[strIn[i]] > iMaxFreq)
		{
			iMaxFreq = umapFreq[strIn[i]];
			cMaxFreq = strIn[i];
		}
	}

	if (iMaxFreq > (strIn.size() + 1) / 2 )
	{
		strIn = "Not possible";
		return;
	}

	int i = 0;
	for (; umapFreq[cMaxFreq] != 0; --umapFreq[cMaxFreq], i += 2)
	{
		strIn[i] = cMaxFreq;
	}
	umapFreq.erase(cMaxFreq);

	if (i >= strIn.size())
	{
		i = 1;
	}

	for (auto it = umapFreq.begin(); it != umapFreq.end(); ++it)
	{
		while (it->second--)
		{
			strIn[i] = it->first;
			
			i += 2;
			if (i >= strIn.size())
			{
				i = 1;
			}
		}
	}
}

int main()
{
	std::string strIn;
	std::cin >> strIn;

	RearrangeCharacters(strIn);
	std::cout << strIn << std::endl;

	return 0;
}