#include <iostream>
#include <vector>

void MergeSorted(std::vector<int>& vecNums1, const std::vector<int>& vecNums2)
{
    int m_n = vecNums1.size();
    int n = vecNums2.size();

    int iPos = m_n - 1;
    for (int i = m_n - 1; i >= 0; --i)
    {
        if (vecNums1[i] != -1 /*&& vecNums1[i] != vecNums1[iPos]*/)
        {
            vecNums1[iPos] = vecNums1[i];
            --iPos;
        }
    }

    iPos = 0;
    for (int i1 = n, i2 = 0; i2 < n; ++iPos)
    {
        if (i1 == m_n || vecNums2[i2] <= vecNums1[i1])
        {
            vecNums1[iPos] = vecNums2[i2];
            ++i2;
        }
        else
        {
            vecNums1[iPos] = vecNums1[i1];
            ++i1;
        }
    }
}

int main()
{
    int m_n;
    std::cin >> m_n;

    std::vector<int> vecNums1(m_n);
    for (int i = 0; i < m_n; ++i)
    {
        std::cin >> vecNums1[i];
    }

    int n;
    std::cin >> n;

    std::vector<int> vecNums2(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vecNums2[i];
    }

    MergeSorted(vecNums1, vecNums2);

    for (int i = 0; i < vecNums1.size(); ++i)
    {
        std::cout << vecNums1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}