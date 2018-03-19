#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <utility>

void SortAndPrintNumbers(std::vector<std::list<int>>& vecMachines)
{
	int n = vecMachines.size();

	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pqMinHeap;

	for (int i = 0; i < n; ++i)
	{
		pqMinHeap.push(std::make_pair(vecMachines[i].front(), i));
		vecMachines[i].pop_front();
	}

	while (!pqMinHeap.empty())
	{
		auto pairMinHeapTop = pqMinHeap.top();
		pqMinHeap.pop();

		std::cout << pairMinHeapTop.first << " ";

		if (!vecMachines[pairMinHeapTop.second].empty())
		{
			pqMinHeap.push(std::make_pair(vecMachines[pairMinHeapTop.second].front(), pairMinHeapTop.second));
			vecMachines[pairMinHeapTop.second].pop_front();
		}
	}
	std::cout << std::endl;

}

int main()
{	
	int n;
	std::cin >> n;

	std::vector<std::list<int>> vecMachines(n);

	for (int i = 0; i < n; ++i)
	{
		std::cout << "Enter numbers from machine number " << i << " (enter -1 for end of input):" << std::endl;
		
		int iNum;
		std::cin >> iNum;
		while (iNum != -1)
		{
			vecMachines[i].push_back(iNum);
			std::cin >> iNum;
		}
	}

	SortAndPrintNumbers(vecMachines);

	return 0;
}