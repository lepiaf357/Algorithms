#include <iostream>
#include <string>

int GetNumFrom64EncodedChar(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 26;
	}
	else if (c >= '0' && c <= '9')
	{
		return c - '0' + 52;
	}
	else if (c == '+')
	{
		return 62;
	}
	else if (c == '/')
	{
		return 63;
	}
	else
	{
		return 0;
	}
}

std::string DecodetoASCII(const std::string& str64Encoded)
{
	std::string strASCIIDecoded;

	int i = 0;
	while (i < str64Encoded.size())
	{
		int iEncodeMask = 0;
		for (int j = 0; j < 4; ++j)
		{
			iEncodeMask = iEncodeMask << 6;
			int i64Encoded = GetNumFrom64EncodedChar(str64Encoded[i]);
			iEncodeMask = iEncodeMask | i64Encoded;
			++i;
		}

		std::string strTriple;

		int iDecodeMask = 255;
		for (int j = 0; j < 3; ++j)
		{
			char c = iEncodeMask & iDecodeMask;
			if (c != 0)
			{
				strTriple.push_back(c);
			}
			iEncodeMask = iEncodeMask >> 8;
		}

		char c = *(strTriple.end() - 1);
		*(strTriple.end() - 1) = *(strTriple.begin());
		*(strTriple.begin()) = c;

		strASCIIDecoded += strTriple;		
	}

	return strASCIIDecoded;
}

int main()
{
	std::string str64Encoded;
	std::cin >> str64Encoded;

	std::cout << DecodetoASCII(str64Encoded) << std::endl;

	return 0;
}