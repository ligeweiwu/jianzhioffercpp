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
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)  //like gui bing pai xu de zui hou yi bu, dan shi lian biao de lue wei fu za
    {
        ListNode *result=NULL;
        ListNode *current=NULL;
        if(pHead1==NULL)
        {
            return pHead2;
        }
        if(pHead2==NULL)
        {
            return pHead1;
        }
        while(pHead1!=NULL && pHead2!=NULL)
        {
            if(pHead1->val<pHead2->val)
            {
                if(current==NULL)
                {
                    current=pHead1;
                    result=pHead1;
                }
                else
                {
                    current->next=pHead1;   // important
                    current=current->next;  // important
                }
                pHead1=pHead1->next;
            }
            else
            {
                if(current==NULL)
                {
                    current=pHead2;
                    result=pHead2;
                }
                else
                {
                    current->next=pHead2;  // important
                    current=current->next;  //important
                }
                pHead2=pHead2->next;
            }
        }
        if(pHead1!=NULL)// the rest of list
        {
            current->next=pHead1;
        }
        if(pHead2!=NULL)// the rest of list
        {
            current->next=pHead2;
        }
        return result;
    }
	
	ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)  //di gui suan fa
	{
		ListNode *current=NULL;
		if(pHead1==NULL)
		{
			return pHead2;
		}
		if(pHead2==NULL)
		{
			return pHead1;
		}
		if(pHead1->val<pHead2->val)
		{
			current=pHead1;
			current->next=Merge2(pHead1->next,pHead2);
			return current;
		}
		else
		{
			current=pHead2;
			current->next=Merge2(pHead1,pHead2->next);
			return current;
		}
	}
	
};
