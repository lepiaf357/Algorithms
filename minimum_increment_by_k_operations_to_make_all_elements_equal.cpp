#include <iostream>
#include <vector>
#include <algorithm>

int MinOperations(const std::vector<int>& vecNums, int k)
{
    int iMaxElem = vecNums[0];
    for (int i = 1; i < vecNums.size(); ++i)
    {
        iMaxElem = std::max(iMaxElem, vecNums[i]);
    }

    int iMinOperations = 0;
    for (int i = 0; i < vecNums.size(); ++i)
    {
        if ((iMaxElem - vecNums[i]) % k != 0)
        {
            return -1;
        }
        iMinOperations += (iMaxElem - vecNums[i]) / k;
    }

    return iMinOperations;
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

    int k;
    std::cin >> k;

    std::cout << MinOperations(vecNums, k) << std::endl;

    return 0;
}