#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// any length
int FindMaxSumSubarray(const std::vector<int>& vecNums)
{
    int iMaxSoFar = INT_MIN;
    int iCurrentMax = 0;

    for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
    {
        iCurrentMax = std::max(*it, iCurrentMax + *it);
        iMaxSoFar = std::max(iMaxSoFar, iCurrentMax);
    }

    return iMaxSoFar;
}

// length k
int FindMaxSumSubarrayLeastK(const std::vector<int>& vecNums, int iMinLength)
{
    int iCurrentMax = 0;
    std::vector<int> vecCurrentMax;

    for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
    {
        iCurrentMax = std::max(*it, iCurrentMax + *it);
        vecCurrentMax.push_back(iCurrentMax);
    }

    int iCurrentSum = 0;
    for (int i = 0; i < iMinLength; ++i)
    {
        iCurrentSum += vecNums[i];
    }

    int iMaxSoFar = iCurrentSum;

    for (int i = iMinLength; i < vecNums.size(); ++i)
    {
        // sliding window technique
        iCurrentSum = iCurrentSum - vecNums[i - iMinLength] + vecNums[i];

        // update result with current sum if current sum is bigger
        iMaxSoFar = std::max(iMaxSoFar, iCurrentSum);

        // update result with current sum + max of previous window if that sum is bigger
        iMaxSoFar = std::max(iMaxSoFar, iCurrentSum + vecCurrentMax[i - iMinLength]);
    }

    return iMaxSoFar;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> vecNums;
    int iNum;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> iNum;
        vecNums.push_back(iNum);
    }

    int iMinLength;
    std::cin >> iMinLength;

    std::cout << FindMaxSumSubarray(vecNums) << std::endl;
    std::cout << FindMaxSumSubarrayLeastK(vecNums, iMinLength) << std::endl;

    return 0;
}

