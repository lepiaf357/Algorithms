#include <iostream>

int TrilingZeros(int n)
{
    int iTrilingZeros = 0;

    for (int i = 5; n / i >= 1; i *= 5)
    {
        iTrilingZeros += n / i;
    }

    return iTrilingZeros;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << TrilingZeros(n) << std::endl;

    return 0;
}
