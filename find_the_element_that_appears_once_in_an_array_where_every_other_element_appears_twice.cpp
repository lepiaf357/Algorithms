#include <iostream>
#include <vector>

int ElementThatAppearsOnce(const std::vector<int>& vecNums)
{
	int iElement= *(vecNums.begin());

	for (auto it = vecNums.begin() + 1; it != vecNums.end(); ++it)
	{
		iElement ^= *it;
	}

	return iElement;
}
 
int main()
{
	int n;
	std::cin >> n;

	std::vector<int> vecNums(n);

	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		std::cin >> *it;
	}

	std::cout << ElementThatAppearsOnce(vecNums) << std::endl;

	return 0;
}