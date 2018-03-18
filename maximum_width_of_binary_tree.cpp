#include <iostream>
#include <queue>
#include <algorithm>

struct node
{
	int iData;
	node* pnodeLeft;
	node* pnodeRight;
};

node* CreateNode(int iData)
{
	node* nodeNew = new node;
	nodeNew->iData = iData;
	nodeNew->pnodeLeft = nullptr;
	nodeNew->pnodeRight = nullptr;

	return nodeNew;
}

int MaximumWidth(node* pnodeRoot)
{
	if (pnodeRoot == nullptr)
	{
		return 0;
	}

	std::queue<node*> qWidth;
	
	node* pnodeTmp;
	int iCount;
	int iMaxWidthSoFar = 0;
	
	qWidth.push(pnodeRoot);
	while (!qWidth.empty())
	{
		iCount = qWidth.size();
		iMaxWidthSoFar = std::max(iMaxWidthSoFar, iCount);

		while (iCount--)
		{
			pnodeTmp = qWidth.front();
			qWidth.pop();

			if (pnodeTmp->pnodeLeft)
			{
				qWidth.push(pnodeTmp->pnodeLeft);
			}
			if (pnodeTmp->pnodeRight)
			{
				qWidth.push(pnodeTmp->pnodeRight);
			}
		}

	}

	return iMaxWidthSoFar;
}

int main()
{
	node* pnodeRoot = CreateNode(5);
	pnodeRoot->pnodeRight = CreateNode(3);
	pnodeRoot->pnodeLeft = CreateNode(2);

	pnodeRoot->pnodeRight->pnodeRight = CreateNode(5);
	pnodeRoot->pnodeRight->pnodeRight->pnodeRight = CreateNode(1);

	pnodeRoot->pnodeLeft->pnodeRight = CreateNode(2);
	pnodeRoot->pnodeLeft->pnodeLeft = CreateNode(2);

	std::cout << MaximumWidth(pnodeRoot) << std::endl;

	return 0;
}