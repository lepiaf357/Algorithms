#include <iostream>
#include <vector>

void Segregate0sL1sR(std::vector<int>& vecNums)
{
    int iLength = vecNums.size();

    int iZeroPos = 0;
    int iOnePos = iLength - 1;

    while (iOnePos > iZeroPos)
    {
        while (iZeroPos < iLength && vecNums[iZeroPos] == 0)
        {
            ++iZeroPos;
        }
        while (iOnePos >= 0 && vecNums[iOnePos] == 1)
        {
            --iOnePos;
        }

        if (iOnePos > iZeroPos)
        {
            //int iTmp = vecNums[iZeroPos];
            vecNums[iZeroPos] = 0; //vecNums[iOnePos];
            vecNums[iOnePos] = 1; //iTmp;
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

    Segregate0sL1sR(vecNums);

    for (int i = 0; i < n; ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}