#ifndef _TEST_HELP_H_
#define _TEST_HELP_H_

#include<iostream>

using namespace std;

#define PRINT_STAR_LINE cout << "****************************" << endl;
#define PRINT_SINGLE_END_LINE cout << "--------------     END.     ----------------" << endl;
#define PRINT_QUESTION_START_LINE(quizName)	cout << "-------------- [" << \
											quizName <<":] --------------" << endl;

#define EXECUTE_TEST_DEMO(test_func_name,quiz_title)	\
			PRINT_QUESTION_START_LINE(quiz_title)		\
			test_func_name(solution);					\
			PRINT_SINGLE_END_LINE


namespace TestHelp{

	template<typename T>
	void print_vector(vector<T> vec)
	{
		for(auto it:vec)
			cout << it << " ";
		cout << endl;
	}

	template<typename T>
	void print_2dim_vector(vector<vector<T>> vec)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			for(int j = 0; j < vec[0].size(); j++)
			{
				cout << vec[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	template<typename T>
	ListNode* CreateListLink(T* array, int size)
	{
		ListNode *root = new ListNode(array[0]);
		ListNode *curPtr = root;
		for(int i = 1; i < size; i++)
		{
			cout <<"listLink: " << i << "  " << array[i] << endl;
			curPtr->next = new ListNode(array[i]);
			curPtr = curPtr->next;
		}
		return root;
	}

	void print_LinkList(ListNode *root)
	{
		while(root != NULL)
		{
			cout << root->val;
			if((root = root->next) != NULL)
				cout << "->";
			else
				break;
		}
		cout << endl;
	}

}

#endif