#include <iostream>
#include <vector>

void RearrangeZigZag(std::vector<int>& vecNums)
{
    bool bLess = true;

    int iTemp;
    for (int i = 0; i < vecNums.size() - 1; ++i)
    {
        if ((bLess && vecNums[i] > vecNums[i + 1]) ||
            (!bLess && vecNums[i] < vecNums[i + 1]))
        {
            iTemp = vecNums[i];
            vecNums[i] = vecNums[i + 1];
            vecNums[i + 1] = iTemp;
        }
        bLess = !bLess;
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

    RearrangeZigZag(vecNums);

    for (int i = 0; i < n; ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

