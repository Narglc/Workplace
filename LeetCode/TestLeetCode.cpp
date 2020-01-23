#include<iostream>

#include "SolutionLeetCode.h"
#include "TestHelp.h"
#include "DataStructLeetCode.h"

void test_decompressRLElist(Solution &solution)
{
	vector<int> nums = {1,2,3,4};
	vector<int> res = solution.decompressRLElist(nums);
	TestHelp::print_vector(res);
}


void test_matrixBlockSum(Solution &solution)
{
	vector<vector<int>> inputMatrix = {{1,2,3},{4,5,6},{7,8,9}};
	int K = 1;
	TestHelp::print_2dim_vector(inputMatrix);

	vector<vector<int>> res = solution.matrixBlockSum(inputMatrix,K);
	TestHelp::print_2dim_vector(res);

	K = 2;
	res = solution.matrixBlockSum(inputMatrix,K);
	TestHelp::print_2dim_vector(res);

	inputMatrix = {{67,64,78},{99,98,38},{82,46,46},{6,52,55},{55,99,45}};
	K = 3;
	TestHelp::print_2dim_vector(inputMatrix);
	res = solution.matrixBlockSum(inputMatrix,K);
	TestHelp::print_2dim_vector(res);
}

void test_twoSum(Solution &solution)
{
	vector<int> nums = {2,7,11,15};
	int target = 9;
	vector<int> res = solution.twoSum(nums,target);
	TestHelp::print_vector(res);
}

void test_addTwoNumbers(Solution &solution)
{
	int array[] = {2,4,3,9};	//{9,9};
	int brray[] = {5,6,6};		//{9};
	ListNode* l1 = TestHelp::CreateListLink(array,sizeof(array)/sizeof(int));
	ListNode* l2 = TestHelp::CreateListLink(brray,sizeof(brray)/sizeof(int));
	TestHelp::print_LinkList(l1);
	TestHelp::print_LinkList(l2);

	ListNode *res = solution.addTwoNumbers(l1,l2);
	TestHelp::print_LinkList(res);
}

int main()
{
	Solution solution;

	EXECUTE_TEST_DEMO(test_decompressRLElist,"1313. 解压缩编码列表")
	EXECUTE_TEST_DEMO(test_matrixBlockSum,"1314. 矩阵区域和")
	EXECUTE_TEST_DEMO(test_twoSum,"1. 两数之和 ")
	EXECUTE_TEST_DEMO(test_addTwoNumbers,"2. 两数相加 ")
}