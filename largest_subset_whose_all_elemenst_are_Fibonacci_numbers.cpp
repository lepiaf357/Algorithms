#include <iostream>
#include <vector>
#include <unordered_set>



std::vector<int> FindFibonaccisubset(const std::vector<int>& vecNums)
{
	int iMaxNum = 0;

	// Find max number and print numbers
	std::cout << "Searching for Fibonacci subset within array:" << std::endl; 
	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		std::cout << *it << " ";

		if (iMaxNum < *it)
		{
			iMaxNum = *it;
		}
	}
	std::cout << std::endl; 

	// Create set of Fibonnacci numbers of size n where Fn <= iMaxNum
	std::unordered_set<int> usetFibonacci;
	int iFn_2 = 0, iFn_1 = 1;
	int iFn = iFn_2 + iFn_1;

	usetFibonacci.insert(iFn_2);
	usetFibonacci.insert(iFn_1);
	while (iFn <= iMaxNum)
	{
		usetFibonacci.insert(iFn);
		iFn_2 = iFn_1;
		iFn_1 = iFn;
		iFn = iFn_2 + iFn_1;
	}

	// Search for subset of Fibonacci numbers
	std::vector<int> vecFibonacciSubset;
	for (auto it = vecNums.begin(); it != vecNums.end(); ++it)
	{
		if (usetFibonacci.find(*it) != usetFibonacci.end())
		{
			vecFibonacciSubset.push_back(*it);
		}
	}

	return vecFibonacciSubset;
}

int main()
{
	std::vector<int> vecNums = {1, 4, 3, 9, 10, 13, 7};
	
	std::vector<int> vecFibonacciSubset = FindFibonaccisubset(vecNums);
	std::cout << "Find Fibonacci subset:" << std::endl; 
	for (auto it = vecFibonacciSubset.begin(); it != vecFibonacciSubset.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}