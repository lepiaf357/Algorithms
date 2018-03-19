#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

bool IsVowel(char c)
{
	c = std::tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void PrintSentencePigLatin(const std::string strSentence)
{
	std::string strPigLatin;

	std::istringstream iss(strSentence);
	std::vector<std::string> vecWords = {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};

	bool bPointFound = false;

	for (auto it = vecWords.begin(); it != vecWords.end(); ++it)
	{
		std::string strWord = *it;
		int iLen = strWord.size();

		if ((it == vecWords.end() - 1) && strWord[iLen - 1] == '.')
		{
			strWord.erase(iLen - 1);
			--iLen;
			bPointFound = true;
		}

		if (!strPigLatin.empty())
		{
			strPigLatin += " ";
		}

		int i;
		for (i = 0; i < iLen; ++i)
		{
			if (IsVowel(strWord[i]))
			{
				break;
			}
		}
		if (i == iLen)
		{
			strPigLatin += strWord;
		}
		else
		{
			strPigLatin += strWord.substr(i) + strWord.substr(0, i) + "ay";
		}
	}

	std::cout << (bPointFound ? strPigLatin + "." : strPigLatin) << std::endl;
}

int main()
{
	std::string strSentence;
	std::getline(std::cin, strSentence);

	PrintSentencePigLatin(strSentence);

	return 0;
}