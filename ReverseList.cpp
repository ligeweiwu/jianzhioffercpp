#include<stdio.h>
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode  //struct in C++ is like class
{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL)// gou zao han shu, chu shi hua lie biao jin xing chu shi hua， like gou zao han shu in class
	{
		
	}
};

class Solution{
	public:
		ListNode* ReverseList1(ListNode* pHead)
		{
			if(pHead==NULL)// dai ma lu bang xing
			{
				return NULL;
			}
			ListNode *pre=NULL;   //three pointer, interesting
			ListNode *cur=pHead;
			ListNode *aft=NULL;
			while(cur!=NULL)
			{
				aft=cur->next;
				cur->next=pre;
				pre=cur;
				cur=aft;
			}
			return pre;
		}
		
		ListNode* ReverseList2(ListNode* pHead)
		{
			ListNode *pre=NULL;   //three pointer, interesting
			ListNode *cur=pHead;
			ListNode *aft=NULL;
			while(cur!=NULL)
			{
				aft=cur->next;
				cur->next=pre;
				pre=cur;
				cur=aft;
			}
			return pre;
		}
		
		ListNode* ReverseList3(ListNode* pHead)
		{
			if(pHead==NULL)// dai ma lu bang xing
			{
				return NULL;
			}
			ListNode *pre=NULL;   //three pointer, interesting
			ListNode *cur=pHead;
			ListNode *aft=NULL;
			while(cur!=NULL)
			{
				if(cur->next==NULL)
				{
					cur->next=pre;
					break;
				}
				aft=cur->next;
				cur->next=pre;
				pre=cur;
				cur=aft;
			}
			return cur;
		}
		
		ListNode* ReverseList4(ListNode* pHead)  //di gui suan fa, interesting
		{
			if(pHead->next==NULL||pHead==NULL)//list is leer or only have one element
			{
				return pHead;
			}
			ListNode *head=ReverseList(pHead->next);//reverse the list, go to the last element of the list
			pHead->next->next=pHead;//set the previous element as the behind element for the current element
			pHead->next=NULL;//avoid the loop for the first element of the original list, let the first element of the original list as the last element of the reversed list,
							//which point to NULL
			return head;
		}
};


int main()
{
	return 0;
}