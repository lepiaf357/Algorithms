#include <iostream>
#include <queue>
#include <vector>

std::priority_queue<int> pqMaxHeap;
std::priority_queue<int, std::vector<int>, std::greater<int>> pqMinHeap;

int Median(int iNum)
{
	if (pqMaxHeap.empty() || iNum < pqMaxHeap.top())
	{
		pqMaxHeap.push(iNum);
	}
	else
	{
		pqMinHeap.push(iNum);
	}

	int iMaxHeapSize = pqMaxHeap.size();
	int iMinHeapSize = pqMinHeap.size();

	if (iMaxHeapSize - iMinHeapSize > 1)
	{
		pqMinHeap.push(pqMaxHeap.top());
		pqMaxHeap.pop();
		--iMaxHeapSize;
		++iMinHeapSize;
	}
	else if (iMinHeapSize - iMaxHeapSize > 1)
	{
		pqMaxHeap.push(pqMinHeap.top());
		pqMinHeap.pop();
		--iMinHeapSize;
		++iMaxHeapSize;
	}

	if (iMaxHeapSize == iMinHeapSize)
	{
		return ((pqMaxHeap.top() + pqMinHeap.top()) / 2);
	}
	else if (iMaxHeapSize == iMinHeapSize + 1)
	{
		return pqMaxHeap.top();
	}
	else
	{
		return pqMinHeap.top();
	}
}

int main()
{	
	int iNum;
	
	while (std::cin >> iNum)
	{
		std::cout << Median(iNum) << std::endl;
	}

	return 0;
}