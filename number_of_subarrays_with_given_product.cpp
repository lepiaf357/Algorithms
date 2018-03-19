#include <iostream>
#include <vector>

int NumOfSubarrWithGivenProduct(const std::vector<int>& vecNums, int k)
{
    int iLength = vecNums.size();

    int iCount = 0;

    int iProd = vecNums[0];
    for (int iStart = 0, iEnd = 1; iEnd < iLength;)
    {
        if (iProd < k)
        {
            iProd *= vecNums[iEnd];
            ++iEnd;
        }
        else if (iProd >= k)
        {
            if (iProd == k)
            {
                int iOnes = 0;
                while (iEnd < iLength && vecNums[iEnd] == 1)
                {
                    ++iOnes;
                    ++iEnd;
                }
                    iCount = iCount + 1 + iOnes;
            }
            iProd /= vecNums[iStart];
            ++iStart;
        }
    }

    return iCount;
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

    std::cout << NumOfSubarrWithGivenProduct(vecNums, k) << std::endl;

    return 0;
}
