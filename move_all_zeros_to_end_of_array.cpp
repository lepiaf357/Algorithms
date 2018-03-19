#include <iostream>
#include <vector>

void MoveZerosToEnd(std::vector<int>& vecNums)
{
    int iLength = vecNums.size();

    int iCount = 0;
    for (int i = 0; i < iLength; ++i)
    {
        if (vecNums[i] != 0)
        {
            vecNums[iCount++] = vecNums[i];
        }

    }

    while (iCount < iLength)
    {
        vecNums[iCount++] = 0;
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

    MoveZerosToEnd(vecNums);

    for (int i = 0; i < n; ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

