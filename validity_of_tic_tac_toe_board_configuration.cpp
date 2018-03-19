#include <iostream>
#include <string>

const int BOARD_SIZE = 9;

// 0 1 2
// 3 4 5
// 6 7 8

bool IsWinner(const std::string& strBoard, char c)
{
	return (  ( strBoard[0] == c &&
			  ( (strBoard[1] == c && strBoard[2] == c) ||
			  	(strBoard[3] == c && strBoard[6] == c) ||
			  	(strBoard[4] == c && strBoard[8] == c) ) ) ||
			  ( strBoard[8] == c &&
			  ( (strBoard[7] == c && strBoard[6] == c) ||
			  	(strBoard[5] == c && strBoard[2] == c) ) ) ||
			  ( strBoard[2] == c && strBoard[4] == c && strBoard[6] == c )
		    );
}

bool IsValidBoard(const std::string& strBoard)
{
	int iCountX = 0;
	int iCountO = 0;

	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (strBoard[i] == 'x')
		{
			++iCountX;
		}
		else if (strBoard[i] == 'o')
		{
			++iCountO;
		}
	}

	bool bWinX = IsWinner(strBoard, 'x');
	bool bWinO = IsWinner(strBoard, 'o');

	if ((iCountX != iCountO && iCountX != iCountO + 1) ||
		(bWinX && bWinO) ||
		(bWinX && iCountX != iCountO) ||
		(bWinO && iCountX != iCountO + 1)
		)
	{
		return false;
	}

	return true;
}

int main()
{
	std::string strBoard;
	std::cin >> strBoard;

	if (strBoard.size() != 9)
	{
		std::cout << "Board size should be 9..." << std::endl;
		return 1;
	}

	std::cout << (IsValidBoard(strBoard) ? "Valid" : "Invalid") << std::endl;

	return 0;
}