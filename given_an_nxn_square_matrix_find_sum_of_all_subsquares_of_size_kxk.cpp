#include <iostream>
#include <vector>

void PrintKxKSums(const std::vector<std::vector<int>>& matrixNums, int k)
{
    int iLength = matrixNums.size();

    if (k > iLength)
    {
        std::cout << "No such submatix of size " << k << "x" << k << std::endl;
        return;
    }

    int iSumStart = 0;
    int iSum = 0;

    for (int j = 0; j < k; ++j)
    {
        for (int i = 0; i < k; ++i)
        {
            iSumStart += matrixNums[i][j];
        }
    }

    int iStart = 0;
    int iEnd = k - 1;

    while(iEnd < iLength)
    {
        int jStart = 0;
        int jEnd = k;

        if (iStart > 0)
        {
            for (int j = jStart; j < jEnd; ++j)
            {
                iSumStart -= matrixNums[iStart - 1][j];
                iSumStart += matrixNums[iEnd][j];
            }
        }

        iSum = iSumStart;
        std::cout << iSumStart << " ";

        while(jEnd != iLength)
        {
            for (int i = iStart; i <= iEnd; ++i)
            {
                iSum -= matrixNums[i][jStart];
                iSum += matrixNums[i][jEnd];
            }
            std::cout << iSum << " ";
            ++jEnd;
            ++jStart;
        }
        std::cout << std::endl;

        ++iStart;
        ++iEnd;
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrixNums(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrixNums[i][j];
        }
    }

    int k;
    std::cin >> k;

    PrintKxKSums(matrixNums, k);

    return 0;
}