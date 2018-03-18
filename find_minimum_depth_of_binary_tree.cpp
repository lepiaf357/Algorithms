#include <iostream>
#include <queue>

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

struct item
{
	node* pnode;
	int depth;
};

int MinimumDepth(node* pnodeRoot)
{
	std::queue<item> qDepth;

	item i = {pnodeRoot, 1};
	qDepth.push(i);
	while (!qDepth.empty())
	{
		i = qDepth.front();
		qDepth.pop();

		if (i.pnode->pnodeLeft == nullptr && i.pnode->pnodeRight == nullptr)
		{
			return i.depth;
		}
		if (i.pnode->pnodeLeft)
		{
			qDepth.push({i.pnode->pnodeLeft, i.depth + 1});
		}
		if (i.pnode->pnodeRight)
		{
			qDepth.push({i.pnode->pnodeRight, i.depth + 1});
		}
	}
}

int main()
{
	node* pnodeRoot = CreateNode(5);
	pnodeRoot->pnodeRight = CreateNode(3);
	pnodeRoot->pnodeLeft = CreateNode(2);

	pnodeRoot->pnodeRight->pnodeRight = CreateNode(5);
	pnodeRoot->pnodeRight->pnodeRight->pnodeRight = CreateNode(1);

	pnodeRoot->pnodeLeft->pnodeRight = CreateNode(2);

	std::cout << MinimumDepth(pnodeRoot) << std::endl;

	return 0;
}