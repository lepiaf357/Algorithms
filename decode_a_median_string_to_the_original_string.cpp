#include <iostream>
#include <string>

std::string OriginalString(const std::string& strMedian)
{
    std::string strOriginal;
    bool bAddToStartPosition = (strMedian.size() % 2) ? false : true;

    for(auto it = strMedian.begin(); it != strMedian.end(); ++it)
    {
        if (bAddToStartPosition)
        {
            strOriginal = *it + strOriginal;
        }
        else
        {
            strOriginal.push_back(*it);
        }

        bAddToStartPosition = !bAddToStartPosition;
    }

    return strOriginal;
}

int main()
{
    std::string strMedian;

    std::cin >> strMedian;
    std::cout << OriginalString(strMedian) << std::endl;

    return 0;
}
