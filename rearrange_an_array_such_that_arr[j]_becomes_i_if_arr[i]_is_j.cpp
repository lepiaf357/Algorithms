#include <iostream>
#include <vector>

// ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
void Rearrange(std::vector<int>& vecNums)
{
    int iLength = vecNums.size();

    int i = 0;
    int iPrevVal = vecNums[i];
    for (int k = 0; k < iLength; ++k)
    {
        int i = k;
        int iPrevVal = vecNums[i];

        while (iPrevVal >= 0)
        {
            int j = iPrevVal;
            iPrevVal = vecNums[j];
            if (iPrevVal < 0)
            {
                break;
            }
            vecNums[j] = -i - 1;
            i = j;
        }
    }

    for (int k = 0; k < iLength; ++k)
    {
        vecNums[k] = - (vecNums[k] + 1);
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