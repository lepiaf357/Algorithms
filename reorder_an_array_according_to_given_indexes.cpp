#include <iostream>
#include <vector>

void RearrangeAccordingToIndex(std::vector<int>& vecNums, std::vector<int>& vecIndex)
{
    int iTempElem, iTempPos;
    int i = 0;

    while (i < vecIndex.size())
    {
        while (i != vecIndex[i])
        {
            iTempElem = vecNums[i];
            iTempPos = vecIndex[i];

            vecNums[i] = vecNums[iTempPos];
            vecIndex[i] = vecIndex[iTempPos];

            vecNums[iTempPos] = iTempElem;
            vecIndex[iTempPos] = iTempPos;
        }
        ++i;
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

    std::vector<int> vecIndex(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecIndex[i];
    }

    RearrangeAccordingToIndex(vecNums, vecIndex);

    for (int i = 0; i < n; ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

