#include <iostream>
#include <vector>

struct BSTNode
{
	int iValue;
	int iIndex;
	BSTNode* bstNodeLeft;
	BSTNode* bstNodeRight;
};

using PTRBSTNode = BSTNode*;

PTRBSTNode CreateBSTNode(int iValue, int iIndex)
{
	PTRBSTNode bstNode = new BSTNode;
	bstNode->iValue = iValue;
	bstNode->iIndex = iIndex;
	bstNode->bstNodeLeft = nullptr;
	bstNode->bstNodeRight = nullptr;

	return bstNode;
}

void AddBSTNode(PTRBSTNode& bstNodeRoot, PTRBSTNode bstNode, int& iLargestSmallerInd)
{
	if (bstNodeRoot == nullptr)
	{
		bstNodeRoot = bstNode;
		return;
	}

	if (bstNode->iValue < bstNodeRoot->iValue)
	{
		if (bstNodeRoot->bstNodeLeft == nullptr)
		{
			bstNodeRoot->bstNodeLeft = bstNode;
			return;
		}
		AddBSTNode(bstNodeRoot->bstNodeLeft, bstNode, iLargestSmallerInd);
	}
	else
	{
		iLargestSmallerInd = bstNodeRoot->iIndex;
		if (bstNodeRoot->bstNodeRight == nullptr)
		{
			bstNodeRoot->bstNodeRight = bstNode;
			return;
		}
		AddBSTNode(bstNodeRoot->bstNodeRight, bstNode, iLargestSmallerInd);
	}
}

void FindAndPrintMaxProductSubseq(const std::vector<int>& vecNums)
{
	int n = vecNums.size();

	std::vector<int> vecRightLargestGreater(n);
	std::vector<int> vecLeftLargestSmaller(n);

	int iMax = n - 1;
	vecRightLargestGreater[n - 1] = -1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (vecNums[i] > vecNums[iMax])
		{
			vecRightLargestGreater[i] = -1;
			iMax = i;
		}
		else
		{
			vecRightLargestGreater[i] = iMax;
		}
	}

	int iMin;
	vecLeftLargestSmaller[0] = -1;
	PTRBSTNode bstNodeRoot = CreateBSTNode(vecNums[0], 0);
	for (int i = 0; i < n; ++i)
	{
		PTRBSTNode bstNode = CreateBSTNode(vecNums[i], i);
		iMin = -1;
		AddBSTNode(bstNodeRoot, bstNode, iMin);
		vecLeftLargestSmaller[i] = iMin;
	}

	int iMaxProduct = 0;
	int iMaxProductInd = -1;
	for (int i = 1; i < n - 1; ++i)
	{
		if (vecLeftLargestSmaller[i] != -1 && vecRightLargestGreater[i] != -1 &&
			vecNums[i] * vecNums[vecRightLargestGreater[i]] * vecNums[vecLeftLargestSmaller[i]] > iMaxProduct)
		{
			iMaxProduct = vecNums[i] * vecNums[vecRightLargestGreater[i]] * vecNums[vecLeftLargestSmaller[i]];
			iMaxProductInd = i;
		}
	}

	std::cout << "Max product is " << iMaxProduct << ". Subsequence of size three with this product is " << vecNums[vecLeftLargestSmaller[iMaxProductInd]] <<
	 ", " << vecNums[iMaxProductInd] << ", " << vecNums[vecRightLargestGreater[iMaxProductInd]] << "." << std::endl;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> vecNums(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> vecNums[i];
	}

	FindAndPrintMaxProductSubseq(vecNums);

	return 0;
}