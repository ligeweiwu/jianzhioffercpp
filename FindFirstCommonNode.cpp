#include<stdio.h>
#include<math.h>
#include <iostream>
#include<bits/stdc++.h> 
#include<vector>
#include<stack>
#include <unordered_map>
#include<map>
#include<unordered_set>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode1( ListNode* pHead1, ListNode* pHead2) {//stack
        stack<ListNode *>p1;
        stack<ListNode *>p2;
        ListNode *p11;
        ListNode *p22;
        if(pHead1==NULL)
        {
            return NULL;
        }
        if(pHead2==NULL)
        {
            return NULL;
        }
        while(pHead1!=NULL)
        {
            p1.push(pHead1);
            pHead1=pHead1->next;
        }
        while(pHead2!=NULL)
        {
            p2.push(pHead2);
            pHead2=pHead2->next;
        }
        while(!p1.empty() && !p2.empty())
        {
            p11=p1.top();
            p22=p2.top();
            if(p11!=p22)
            {
                return p11->next;
            }
            p1.pop();
            p2.pop();
        }
        return p11;
    }
	
	ListNode* FindFirstCommonNode2( ListNode* pHead1, ListNode* pHead2) {//set
        unordered_set <ListNode*>s;
        if(pHead1==NULL)
        {
            return NULL;
        }
        if(pHead2==NULL)
        {
            return NULL;
        }
        while(pHead1!=NULL)
        {
            s.insert(pHead1);
            pHead1=pHead1->next;
        }
        while(pHead2!=NULL)
        {
            if(s.find(pHead2)!=s.end())//s.count(pHead2)!=0
            {
                return pHead2;
            }
            pHead2=pHead2->next;
        }
        return NULL;
    }
	
	ListNode* FindFirstCommonNode3( ListNode* pHead1, ListNode* pHead2) {
       if(pHead1==NULL)
       {
           return NULL;
       }
        if(pHead2==NULL)
        {
            return NULL;
        }
        int l1=getlength(pHead1);
        int l2=getlength(pHead2);
        int diff=0;
        if(l1>l2)
        {
            diff=l1-l2;
            while(diff>0)
            {
                pHead1=pHead1->next;
                diff--;
            }
        }
        else
        {
            diff=l2-l1;
            while(diff>0)
            {
                pHead2=pHead2->next;
                diff--;
            }
        }
        while(pHead1!=NULL)
        {
            if(pHead1==pHead2)
            {
                return pHead1;
            }
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return NULL;
    }
	
	ListNode* FindFirstCommonNode4( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL)
        {
            return NULL;
        }
        if(pHead2==NULL)
        {
            return NULL;
        }
        int l1=getlength(pHead1);
        int l2=getlength(pHead2);
        if(l1<l2)
        {
            ListNode *temp=pHead2;
            pHead2=pHead1;
            pHead1=temp;
            int l=l2;
            l2=l1;
            l1=l;
        }
        int diff=l1-l2;
        while(diff>0)
        {
            pHead1=pHead1->next;
            diff--;
        }
        while(pHead1!=NULL)
        {
            if(pHead1==pHead2)
            {
                return pHead1;
            }
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return NULL;
    }
	
	ListNode* FindFirstCommonNode5( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL)
        {
            return NULL;
        }
        if(pHead2==NULL)
        {
            return NULL;
        }
        int l1=getlength(pHead1);
        int l2=getlength(pHead2);
        if(l1<l2)
        {
            return FindFirstCommonNode5(pHead2,pHead1);
        }
        int diff=l1-l2;
        while(diff>0)
        {
            pHead1=pHead1->next;
            diff--;
        }
        while(pHead1!=NULL)
        {
            if(pHead1==pHead2)
            {
                return pHead1;
            }
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        return NULL;
    }
	
    int getlength(ListNode* pHead1)
    {
        int count=0;
        while(pHead1!=NULL)
        {
            pHead1=pHead1->next;
            count++;
        }
        return count;
    }
};

int main()
{
	return 0;
}
