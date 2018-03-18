#include <iostream>
#include <string>

std::string EncodeString(const std::string& strDecoded, int iStart)
{
	std::string strOriginal;
	strOriginal.push_back('0' + iStart);
	char c = '0' + (strDecoded[1] - '0') - (strOriginal[0] - '0');
	if (c != '1' && c != '0')
	{
		return "NONE";
	}
	strOriginal.push_back(c);

	for (int i = 2; i < strDecoded.size(); ++i)
	{
		char c = '0' + (strDecoded[i] - '0') - (strOriginal[i - 1] - '0') - (strOriginal[i - 2] - '0');
		if (c != '1' && c != '0')
		{
			return "NONE";
		}
		strOriginal.push_back(c);	
	}
	
	return strOriginal;
}

int main()
{
	std::string strDecoded;
	std::cin >> strDecoded;

	std::cout << EncodeString(strDecoded, 0) << " " << EncodeString(strDecoded, 1) << std::endl;



	return 0;
}