#include <iostream>
#include <vector>

void FindPairWithGivenSum(const std::vector<int>& vecNums, int k)
{
    int iLength = vecNums.size();

    int iPivot;
    for (int i = 1; i < iLength - 1; ++i)
    {
        if (vecNums[i] < vecNums[i - 1] && vecNums[i] < vecNums[i + 1])
        {
            iPivot = i;
            break;
        }
    }

    int iStart = iPivot;
    int iEnd = iPivot - 1;
    bool bReverse = true;

    while(iStart != iEnd)
    {
        if (vecNums[iStart] + vecNums[iEnd] == k)
        {
            std::cout << iStart << " " << iEnd << std::endl;
            //return;
            iStart = (iStart + 1) % iLength;
            iEnd = (iEnd - 1 + iLength) % iLength;

        }
        else if (vecNums[iStart] + vecNums[iEnd] > k)
        {
            // if (iEnd == 0)
            // {
            //     bReverse = false;
            //     iEnd = iLength;
            // }
            // --iEnd;
            iEnd = (iEnd - 1 + iLength) % iLength;
        }
        else
        {
            // if (iStart == iLength - 1)
            // {
            //     bReverse = false;
            //     iStart = -1;
            // }
            // ++iStart;
            iStart = (iStart + 1) % iLength;
        }
    }
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

    FindPairWithGivenSum(vecNums, k);

    return 0;
}