#include <iostream>
#include <string>

int SmallestNumDigitsMultiplayToN(int n)
{
    if (n < 10)
    {
        return 10 + n;
    }

    int iSmallestNumReverse = 0;
    for (int i = 9; i > 1; --i)
    {
        while (n % i == 0)
        {
            iSmallestNumReverse = iSmallestNumReverse * 10 + i;
            n /= i;
        }
    }

    if (n > 10)
    {
        return -1;
    }

    int iSmallestNum = 0;
    while (iSmallestNumReverse != 0)
    {
        iSmallestNum = iSmallestNum * 10 + iSmallestNumReverse % 10;
        iSmallestNumReverse /= 10;
    }

    return iSmallestNum;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << SmallestNumDigitsMultiplayToN(n) << std::endl;

    return 0;
}

