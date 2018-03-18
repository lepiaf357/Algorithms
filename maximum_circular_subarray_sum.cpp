#include <iostream>
#include <vector>
#include <algorithm>

int MaxSumCircularArray(const std::vector<int>& vecNums)
{
    int iCurrentMax = vecNums[0];
    int iMaxSoFar = iCurrentMax;

    int iCurrentMin = vecNums[0];
    int iMinSoFar = iCurrentMin;

    int iSum = vecNums[0];

    bool bAllPoz = true;
    bool bAllNeg = true;

    for (int i = 1; i < vecNums.size(); ++i)
    {
        if (bAllPoz && vecNums[i] < 0)
        {
                bAllPoz = false;
        }
        if (bAllNeg && vecNums[i] > 0)
        {
                bAllNeg = false;
        }

        iCurrentMax = std::max(iCurrentMax + vecNums[i], vecNums[i]);
        iMaxSoFar = std::max(iMaxSoFar, iCurrentMax);

        iCurrentMin = std::min(iCurrentMin + vecNums[i], vecNums[i]);
        iMinSoFar = std::min(iMinSoFar, iCurrentMin);

        iSum += vecNums[i];
    }

    if (bAllNeg || bAllPoz)
    {
        return iMaxSoFar;
    }

    iMaxSoFar = std::max(iMaxSoFar, iSum - iMinSoFar);

    return iMaxSoFar;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vecNums(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecNums[i];
    }

    std::cout << MaxSumCircularArray(vecNums) << std::endl;

    return 0;
}