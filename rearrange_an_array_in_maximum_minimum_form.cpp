#include <iostream>
#include <vector>

void RearrangeToMaxMinForm(const std::vector<int>& vecSortedNums, std::vector<int>& vecMaxMinForm)
{
	auto its = vecSortedNums.begin(), ite = vecSortedNums.end() - 1;
	for (; its < ite; ++its, -- ite)
	{
		vecMaxMinForm.push_back(*ite);
		vecMaxMinForm.push_back(*its);
	}
	if (its == ite)
	{
		vecMaxMinForm.push_back(*its);
	}
}

void RearrangeToMaxMinFormInplace(std::vector<int>& vecSortedNums)
{
	int iMax = vecSortedNums.size() - 1;
	int iMin = 0;

	int iLargest = vecSortedNums[iMax] + 1;

	// old num -> % iLargest
	// new num -> / iLargest
	for (int i = 0; i < vecSortedNums.size(); ++i)
	{
		// even index -> store max
		if (i % 2 == 0)
		{
			vecSortedNums[i] = vecSortedNums[i] + (vecSortedNums[iMax] % iLargest) * iLargest;
			--iMax;
		}
		// odd index -> store min
		else
		{
			vecSortedNums[i] = vecSortedNums[i] + (vecSortedNums[iMin] % iLargest) * iLargest;
			++iMin;
		}
	}

	// transform to all new nums -> / iLargest
	for (int i = 0; i < vecSortedNums.size(); ++i)
	{
		vecSortedNums[i] /= iLargest;
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> vecSortedNums(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> vecSortedNums[i];
	}

	std::vector<int> vecMaxMinForm;
	RearrangeToMaxMinForm(vecSortedNums, vecMaxMinForm);

	for (int i = 0; i < n; ++i)
	{
		std::cout << vecMaxMinForm[i] << " ";
	}
	std::cout << std::endl;

	RearrangeToMaxMinFormInplace(vecSortedNums);

	for (int i = 0; i < n; ++i)
	{
		std::cout << vecSortedNums[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}