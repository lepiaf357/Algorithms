#include <iostream>
#include <vector>

void Rearrange(std::vector<int>& vecNums)
{
    int iLength = vecNums.size();

    for (int i = 0; i < iLength; ++i)
    {
        vecNums[i] = vecNums[i] + (vecNums[vecNums[i]] % iLength) * iLength;
    }
    for (int i = 0; i < iLength; ++i)
    {
        vecNums[i] /=  iLength;
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

    Rearrange(vecNums);

    for (int i = 0; i < n; ++i)
    {
        std::cout << vecNums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}