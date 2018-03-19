#include <cstdlib>
#include <iostream>
#include <ctime>
 
int Rand50()
{
	// use current time as seed for random generator
    // std::srand(std::time(nullptr));
    
    // odd or even is with equal probability
    return std::rand() & 1;
}

int Rand75()
{
	// 0 0 -> 0
	// 0 1 -> 1
	// 1 0 -> 1
	// 1 1 -> 1
	return Rand50() | Rand50();
}

int main() 
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << Rand75();
	}
	std::cout << std::endl;

	return 0;
}