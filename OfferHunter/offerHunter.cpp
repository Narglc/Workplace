#include "offerHunter.h"

int Q3_FindRepetedNum(vector<int> &nums)
{
	int array[ARRAY_SIZE] = { -1 };
	for(auto iter:nums)
	{
		if(array[iter] == iter)
			return iter;
		else
			array[iter] = iter;
	}
	return -1;
}

int Q3_FindRepetedNum_V2(vector<int> &nums)
{
	int index = 0;
	while(index < nums.size())
	{
		if(nums[index] == index)
		{
			index++;
			cout << "++" << " ";
		}
		else
		{
			int cur_nums = nums[index];
			if(nums[cur_nums] == cur_nums)
			{
				cout << " return ";
				return cur_nums;
			}
			else
			{	
				if(nums[index] >= nums.size())
					return -1;
				cout << " swap ";
				nums[index] = nums[cur_nums];
				nums[cur_nums] = cur_nums;
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> inputNumbers = {2, 3, 1, 0, 4, 3, 8};
	int theNum = Q3_FindRepetedNum(inputNumbers);
	PRINTLINE
	cout << "Repeted Number: " << theNum << endl;
	cout << "V2 Repeated Number: " << Q3_FindRepetedNum_V2(inputNumbers)<< endl;
	PRINTLINE
	vector<int> inputNumbers2 = {2, 3, 1, 0, 6, 5, 7};
	cout << "V2 Repeated Number: " << Q3_FindRepetedNum_V2(inputNumbers2)<< endl;
	cout << "After: ";
	PrintVector(inputNumbers2);

	printf("abc\bv");

	return 0;
}

