#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// largest common subsequence 
// if i == n || j == m return 0
// if F[i] == S[j] : 1 + fun(F,S,i+1,j+1)
// else : max(fun(F,S,i+1,j),fun(F,S,i,j+1))
std::pair<int, std::string> LCS(const std::string& strFirst, const std::string strSecond)
{
	int iLenFirst = strFirst.size();
	int iLenSecond = strSecond.size();

	// find LCS length
	// will be stored in vecLCS[0][0]
	std::vector<std::vector<int>> vecLCS(iLenFirst + 1, std::vector<int>(iLenSecond + 1, 0));

	for (int j = iLenSecond - 1; j >= 0; --j)
	{
		for (int i = iLenFirst - 1; i >= 0; --i)
		{
			if (strFirst[i] == strSecond[j])
			{
				vecLCS[i][j] = 1 + vecLCS[i + 1][j + 1];
			}
			else
			{
				vecLCS[i][j] = std::max(vecLCS[i][j + 1], vecLCS[i + 1][j]);
			}
		}
	}

	// find LCS string
	std::string strLCS;

	int i = 0, j = 0;
	while (i < iLenFirst && j < iLenSecond)
	{
		if (strFirst[i] == strSecond[j])
		{
			strLCS.push_back(strFirst[i]);
			++i;
			++j;
		}
		else if (vecLCS[i][j + 1] > vecLCS[i + 1][j])
		{
			++j;
		}
		else
		{
			++i;
		}
	}

	return std::make_pair(vecLCS[0][0], strLCS);
}

// using LCS
bool IsKPalindrome(const std::string& strKPalindrome, int k)
{
	std::string strReverseKPalindrome = strKPalindrome; 
	std::reverse(strReverseKPalindrome.begin(), strReverseKPalindrome.end());
	return strKPalindrome.size() - LCS(strKPalindrome, strReverseKPalindrome).first <= k;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// using minimum of delete operations of Edit Distance problem
// change it not to use 2 strings (original and reverse), use original from start and end position moving to middle
// if left >= right : return 0
// if s[left] == s[right] : return fun(left+1,right-1)
// else: return 1 + min(fun(left+1,right),fun(left,right-1))
int MinimumDeleteOperationsRequired(const std::string& strKPalindrome)
{
	int iLen = strKPalindrome.size();
	std::vector<std::vector<int>> vecMinDelete(iLen, std::vector<int>(iLen, 0));

	for (int k = 1; k < iLen; ++k)
	{
		for (int i = 0, j = k; j < iLen; ++j, ++i)
		{
			if (strKPalindrome[i] == strKPalindrome[j])
			{
				vecMinDelete[i][j] = vecMinDelete[i + 1][j - 1];
			}
			else
			{
				vecMinDelete[i][j] = 1 + std::min(vecMinDelete[i + 1][j], vecMinDelete[i][j - 1]);
			}
		}
	}

	// space optimisation
	std::vector<int> vecMinDeleteOptD(iLen, 0);
	std::vector<int> vecMinDeleteOptU(iLen, 0);

	for (int k = 1; k < iLen; ++k)
	{
		int i = 0;
		for (int j = k; i < iLen - k; ++i, ++j)
		{
			if (strKPalindrome[i] == strKPalindrome[j])
			{
				int tmp = vecMinDeleteOptD[i + 1];
				vecMinDeleteOptD[i] = vecMinDeleteOptU[i];
				vecMinDeleteOptU[i] = tmp;
			}
			else
			{
				vecMinDeleteOptD[i] = vecMinDeleteOptU[i];
				vecMinDeleteOptU[i] = 1 + std::min(vecMinDeleteOptU[i], vecMinDeleteOptU[i + 1]);
			}
		}
		vecMinDeleteOptD[i] = vecMinDeleteOptU[i];

	 	for (int j = 0; j < iLen; ++j)
	 	{
	 		std::cout << vecMinDeleteOptU[j] << " ";
	 	}
	 	std::cout << std::endl;

	 	for (int j = 0; j < iLen; ++j)
	 	{
	 		std::cout << vecMinDeleteOptD[j] << " ";
	 	}
	 	std::cout << std::endl;

	}

	for (int i = 0; i < iLen; ++i)
	{
		for (int j = 0; j < iLen; ++j)
		{
			std::cout << vecMinDelete[i][j] << " ";
		}
		std::cout << std::endl;
	}

	
	//return vecMinDelete[0][iLen - 1];
	return vecMinDeleteOptU[0];
}

// using delete operations
bool IsKPalindrome2(const std::string& strKPalindrome, int k)
{
	return MinimumDeleteOperationsRequired(strKPalindrome) <= k;
}

int main()
{
	std::string strKPalindrome;
	std::cin >> strKPalindrome;
	int k;
	std::cin >> k;

	std::cout << (IsKPalindrome(strKPalindrome, k) ? "YES" : "NO") << std::endl;
	std::cout << (IsKPalindrome2(strKPalindrome, k) ? "YES" : "NO") << std::endl;

	return 0;
}

