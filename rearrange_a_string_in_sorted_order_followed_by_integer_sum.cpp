#include <iostream>
#include <string>
#include <vector>

const int MAX_CHAR = 26;

std::string SortString(const std::string& strUnsorted)
{
    std::vector<int> vecCount(MAX_CHAR, 0);
    int iSum = 0;
    int iNum = 0;
    std::string strSorted;

    for (auto it = strUnsorted.begin(); it != strUnsorted.end(); ++it)
    {
        if (*it >= 'A' && *it <= 'Z')
        {
            if (iNum != 0)
            {
                iSum += iNum;
                iNum = 0;
            }
            vecCount[*it - 'A']++;
        }
        else if (*it >= '0' && *it <= '9')
        {
            if (iNum != 0)
            {
                iNum = iNum * 10 + (*it - '0');
            }
            else
            {
                iNum += *it - '0';
            }
        }    
        else
        {
            std::cout << "String: " << strUnsorted << " is in bad format! Use A-Z and 0-9 characters only." << std::endl;
            return {};
        }
    }

    for (int i = 0; i < MAX_CHAR; ++i)
    {
        while (vecCount[i]--)
        {
            strSorted += static_cast<char>(i + 'A');
        }
    }

    iSum += iNum;
    if (iSum)
    {
        strSorted += std::to_string(iSum);
    }

    return strSorted;
}

int main()
{
    std::string strUnsorted;
    std::cin >> strUnsorted;

    std::cout << SortString(strUnsorted) << std::endl;

    return 0;
}

