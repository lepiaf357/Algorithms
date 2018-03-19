#include <iostream>
#include <vector>
#include <unordered_map>


int CountPairs(const std::vector<int>& vecNums, const int& iSum)
{
    std::unordered_map<int,int> umapCountNumFreq;
    int iPairCount = 0;

    for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
    {
        umapCountNumFreq[*it]++;
    }

    for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
    {
        if (umapCountNumFreq.find(iSum - *it) != umapCountNumFreq.end())
        {
            iPairCount += umapCountNumFreq[iSum-*it];
        }

        if (*it == iSum - *it)
        {
            --iPairCount;
        }
    }

    iPairCount /= 2;

    return iPairCount;
}

int main()
{
    std::vector<int> vecNums = {1,1,2,2,3,0,1,2,5,9,1,2};
    int iSum = 3;

    int iPairCount = CountPairs(vecNums, iSum);
    std::cout << "Number of pairs with sum " << iSum << " is: " << iPairCount << std::endl;
}

