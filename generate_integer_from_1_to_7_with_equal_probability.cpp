#include <cstdlib>
#include <iostream>
#include <ctime>
 
int Rand5()
{
	// use current time as seed for random generator
    // std::srand(std::time(nullptr));
    
    // rand from 1 to 5
    return std::rand() % 5 + 1;
}

int Rand7()
{
	// rand from 1 to 25
	int iRand = 5 * Rand5() + Rand5() - 5;
	if (iRand < 22)
	{
		return iRand % 7 + 1;
	}

	return Rand7();
}

int main() 
{
	for (int i = 0; i < 15; ++i)
	{
		std::cout << Rand7();
	}
	std::cout << std::endl;

	return 0;
}