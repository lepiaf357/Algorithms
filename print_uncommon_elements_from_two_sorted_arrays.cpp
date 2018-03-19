#include <iostream>
#include <vector>

void FillUncommon(const std::vector<int>& vecNums1, const std::vector<int>& vecNums2, std::vector<int>& vecUncommon)
{
    int i1 = 0, i2 = 0;
    while (i1 < vecNums1.size() && i2 < vecNums2.size())
    {
        if (vecNums1[i1] == vecNums2[i2])
        {
            ++i1;
            ++i2;
        }
        else if (vecNums1[i1] < vecNums2[i2])
        {
            vecUncommon.push_back(vecNums1[i1]);
            ++i1;
        }
        else
        {
            vecUncommon.push_back(vecNums2[i2]);
            ++i2;
        }
    }

    while (i1 < vecNums1.size())
    {
        vecUncommon.push_back(vecNums1[i1]);
        ++i1;
    }
    while (i2 < vecNums2.size())
    {
        vecUncommon.push_back(vecNums2[i2]);
        ++i2;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vecNums1(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecNums1[i];
    }

    std::cin >> n;

    std::vector<int> vecNums2(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecNums2[i];
    }

    std::vector<int> vecUncommon;
    FillUncommon(vecNums1, vecNums2, vecUncommon);

    for (int i = 0; i < vecUncommon.size(); ++i)
    {
        std::cout << vecUncommon[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}