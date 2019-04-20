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

class Solution {
public:
    ListNode* FindKthToTail1(ListNode* pListHead, unsigned int k) {
    ListNode *first=pListHead;//bi pointer in this algorithm
    ListNode *second=pListHead;
    unsigned int count=0;
    if(pListHead==NULL||k==0)// dai ma lu bang xing
    {
        return NULL;
    }
    
    for(count=0;count<k-1;count++)
    {
        first=first->next;
        if(first==NULL)
        {
            return NULL;
        }
    }
    while(first->next!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    return second;
    }
	
	ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k)
	{
		ListNode *first=pListHead;//bi pointer in this algorithm
		ListNode *second=pListHead;
		unsigned int count=0;
		if(pListHead==NULL||k==0)// dai ma lu bang xing
		{
			return NULL;
		}
		
		for(count=0;count<k-1;count++)
		{
			first=first->next;
			if(first==NULL)
			{
				return NULL;
			}
		}
		while(first!=NULL)
		{
			first=first->next;
			if(first!=NULL)
			{
				second=second->next;
			}
		}
		return second;
	}
	
	ListNode* FindKthToTail3(ListNode* pListHead, unsigned int k)
	{
		if(pListHead==NULL||k==0)// dai ma lu bang xing
		{
			return NULL;
		}
		ListNode *ls=pListHead;//stack in this algorithm
		stack<ListNode *> nodes;
		unsigned int count=0;
		ListNode *xx=NULL;
		while(ls!=NULL)
		{
			nodes.push(ls);
			ls=ls->next;
		}
		unsigned int number=nodes.size();
		if(number<k)
		{
			return NULL;
		}
		for(count=0;count<k;count++)
		{
			if(count==k-1)
			{
				xx=nodes.top();
			}
			nodes.pop();
		}
		return xx;
	}
};

int main()
{
	return 0;
}