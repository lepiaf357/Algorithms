#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
#include <unordered_map>

//sort
void FindAllTripletsWithSumZero(std::vector<int>& vecNums)
{
	std::sort(vecNums.begin(), vecNums.end());

	for (int i = 0; i <= vecNums.size() - 3; ++i)
	{
		int start = i + 1;
		int end = vecNums.size() - 1;

		while (start < end)
		{
			int sum = vecNums[i] + vecNums[start] + vecNums[end];
			if (sum == 0)
			{
				int count_start = 1;
				int count_end = 1;
				++start;
				--end;

				// if elements arn't distinct
				while (start < vecNums.size() && vecNums[start] == vecNums[start - 1] )
				{
					++count_start;	
					++start;

				}

				if (start == vecNums.size())
				{
					count_start = (count_start-1)*(count_start)/2;
				}
				else
				{
					while ( vecNums[end] == vecNums[end + 1])
					{
						++count_end;
						--end;
					}
				}


				int num = count_start * count_end;
				while (num--)
				{
					std::cout << vecNums[i] << " " << vecNums[start - 1] << " " << vecNums[end + 1] << std::endl;
				}
			}
			else if (sum > 0)
			{
				--end;
			}
			else
			{
				++start;
			}
		}
	}
}

//hashing
void FindAllTripletsWithSumZero2(std::vector<int>& vecNums)
{
	int iCount = 0;
	for (int i = 0; i <= vecNums.size() - 3; ++i)
	{
		std::unordered_map<int,int> umapCount;
		int sum = 0 - vecNums[i];

		for (int j = i + 1; j < vecNums.size(); ++j)
		{
			umapCount[vecNums[j]]++;
		}

		int count = 0;
		for (int j = i + 1; j < vecNums.size(); ++j)
		{
			if (umapCount.find(sum - vecNums[j]) != umapCount.end())
			{
				count += umapCount[sum - vecNums[j]];
			}
			if (sum - vecNums[j] == vecNums[j])
			{
				--count;
			}
		}
		iCount += count / 2;	
	}

	std::cout << iCount << std::endl;
}

int main()
{
	std::vector<int> vecNums;
	int iNum;

	while(std::cin >> iNum)
	{
		vecNums.push_back(iNum);
	}

	FindAllTripletsWithSumZero(vecNums);
	FindAllTripletsWithSumZero2(vecNums);


	return 0;
}