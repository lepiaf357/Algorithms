#include <iostream>
#include <string>

std::string Substring(const std::string& strIn, int i, int count)
{
    if (count == 0 || i >= strIn.size())
    {
        return {};
    }
    return strIn[i] + Substring(strIn, i + 1, count - 1);
}

int main()
{
    std::string strIn;
    std::cin >> strIn;

    std::cout << Substring(strIn, 3, 5);
    
    return 0;
}