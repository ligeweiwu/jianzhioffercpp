
#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
// dai ma lu bang xing
struct ListNode{  //struct in C++ like class, see blog
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL)// gou zao han shu, chu shi hua lie biao jin xing chu shi hua， like gou zao han shu in class
	{
		
	}
};

class Solution{
	public:
		vector<int> printListFromTailToHead(ListNode* head)//using the characetristic of stack
		{    //head is the fixed address of the first element of the list
			vector<int> result;//like a list in python
			stack<int> nodes;//stack,first in last out
			ListNode *p=head;  //pointer store the address of ListNode head->head->next->head->next->next->........,using for stack
			while(p!=NULL)
			{
				nodes.push(p->val);
				p=p->next;//go to next list node
			}
			while(nodes.empty()!=true)
			{
				result.push_back(nodes.top());//add the last element from stack into vector
				nodes.pop();//delete the last element from stack
			}
			return result;
		}
		
		vector<int> printListFromTailToHead1(ListNode* head)//using the di gui suan fa
		{
			//head is the fixed address of the first element of the list
			vector<int> result;//like a list in python
			ListNode *p=head;  //pointer store the address of ListNode
		    
			// 1st think, in this case while is equal to if, because return in while, but if is better
			while(p!=NULL)  
			{
				result=rintListFromTailToHead1(p->next);
				result.push_back(p->val);
				return result;
			}
			return result;
		}
		
		vector<int> printListFromTailToHead2(ListNode* head)//using the di gui suan fa
		{
			//head is the fixed address of the first element of the list
			vector<int> result;//like a list in python
			ListNode *p=head;  //pointer store the address of ListNode
		    
			// 2nd think, in this case if is equal to while, because return in if, but if is better
			if(p!=NULL)  
			{
				result=rintListFromTailToHead1(p->next);
				result.push_back(p->val);
				return result;
			}
			return result;
		}
		
		vector<int> printListFromTailToHead3(ListNode* head)//using the di gui suan fa
		{
			vector<int> result;//like a list in python
			if(p!=NULL)  //only if, when you use while, it will in unlimit recursive
			{
				result=rintListFromTailToHead1(p->next);
				result.push_back(p->val);
			}
			return result;
		}
};



int main()
{
	return 0;
}