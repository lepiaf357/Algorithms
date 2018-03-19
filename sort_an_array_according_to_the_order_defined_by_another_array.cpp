#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

void SortByOrder(std::vector<int>& vecNums, const std::vector<int>& vecOrder)
{
    std::unordered_map<int,int> umapNumsCount;
    
    for (int i = 0; i < vecNums.size(); ++i)
    {
        umapNumsCount[vecNums[i]]++;
    }

    int iPos = 0;

    for (int i = 0; i < vecOrder.size(); ++i)
    {
        if (umapNumsCount.find(vecOrder[i]) != umapNumsCount.end())
        {
            while (umapNumsCount[vecOrder[i]] != 0)
            {
                vecNums[iPos] = vecOrder[i];
                --umapNumsCount[vecOrder[i]];
                ++iPos;
            }
            umapNumsCount.erase(vecOrder[i]);
        }
    }

    int iSortPos = iPos;

    for (auto it = umapNumsCount.begin(); it != umapNumsCount.end(); ++it)
    {
        while (it->second != 0)
        {
            vecNums[iPos] = it->first;
            --it->second;
            ++iPos;
        }
    }

    std::sort(vecNums.begin() + iSortPos, vecNums.end());
}

// second method, custom compare function
std::vector<int> vecOrder;

int Find(int x)
{
    for (int i = 0; i < vecOrder.size(); ++i)
    {
        if (vecOrder[i] == x)
        {
            return i;
        }
    }

    return -1;
}

// use hashing instead of linear search
std::unordered_map<int,int> umapOrder;

int Find2(int x)
{
    auto it = umapOrder.find(x);
    
    if (it != umapOrder.end())
    {
        return umapOrder[x];
    }

    return -1;
}

int Compare(const int& a, const int& b)
{
    int inda = Find(a);
    int indb = Find(b);

    if (inda == -1 && indb == -1)
    {
        return (a < b);
    }

    if (inda == -1)
    {
        return 0;
    }

    if (indb == -1)
    {
        return 1;
    }

    if (inda < indb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Compare2(const int& a, const int& b)
{
    int inda = Find2(a);
    int indb = Find2(b);

    if (inda == -1 && indb == -1)
    {
        return (a < b);
    }

    if (inda == -1)
    {
        return 0;
    }

    if (indb == -1)
    {
        return 1;
    }

    if (inda < indb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void SortByOrder2(std::vector<int>& vecNums, const std::vector<int>& vecOrder)
{
    ::vecOrder = vecOrder;
    std::sort(vecNums.begin(), vecNums.end(), Compare);
}

void SortByOrder3(std::vector<int>& vecNums, const std::vector<int>& vecOrder)
{
    for (int i = 0; i < vecOrder.size(); ++i)
    {
        umapOrder[vecOrder[i]] = i;
    }
    std::sort(vecNums.begin(), vecNums.end(), Compare2);
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

    std::cin >> n;

    std::vector<int> vecOrder(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecOrder[i];
    }

    SortByOrder3(vecNums, vecOrder);

    for (int i = 0; i < vecNums.size(); ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}