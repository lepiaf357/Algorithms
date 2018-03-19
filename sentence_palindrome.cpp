#include <iostream>
#include <string>

bool IsAlphaNum(const char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool CheckPalindrome(const std::string& strSentence)
{
	for (auto it = strSentence.begin(), itr = strSentence.end() - 1; it < itr; ++it, --itr)
	{
		while (!IsAlphaNum(*it) && it < itr)
		{
			++it;
		}
		while (!IsAlphaNum(*itr) && it < itr)
		{
			--itr;
		}

		if (std::toupper(*it) != std::toupper(*itr))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	std::string strSentence;
	std::getline(std::cin, strSentence);

	if (CheckPalindrome(strSentence))
	{
		std::cout << "Sentence is palindrome." << std::endl;
	}
	else
	{
		std::cout << "Sentence isn't palindrome." << std::endl;
	}

	return 0;
}