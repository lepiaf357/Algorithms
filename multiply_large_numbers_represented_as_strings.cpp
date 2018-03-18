#include <iostream>
#include <string>
#include <vector>

void Multiply(const std::string& strNum1, const std::string& strNum2)
{
    int iNum1Len = strNum1.size();
    int iNum2Len = strNum2.size();

    std::string strResult(iNum1Len + iNum2Len, '0');

    int iAdd = 0;
    int iStart = strResult.size();
    int m;

    for (int i = iNum1Len - 1; i >= 0; --i)
    {
        --iStart;
        m = iStart;
        for (int j = iNum2Len - 1; j >= 0; --j, --m)
        {
            int tmp = (strNum1[i] - '0') * (strNum2[j] - '0') + (strResult[m] - '0') + iAdd;
            iAdd = tmp / 10;
            tmp = tmp % 10;
            strResult[m] = tmp + '0';
        }
        strResult[m] = iAdd + '0';
        iAdd = 0;
    }
    
    auto it = strResult.begin();
    while (*it == '0')
    {
        it = strResult.erase(it);
    }
    if (strResult.empty())
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << strResult << std::endl;
    }
}

int main()
{
    std::string strNum1, strNum2;
    std::cin >> strNum1;
    std::cin >> strNum2;

    Multiply(strNum1, strNum2);

    return 0;
}