#include<stdio.h>
#include<math.h>
#include <iostream>
#include<bits/stdc++.h> 
#include<vector>
#include<stack>
#include <unordered_map>
#include<map>
#include<unordered_set>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication1(ListNode* pHead)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        ListNode *begin=pHead;
        ListNode *cur=pHead;
        ListNode *aft=pHead->next;
        ListNode *pre=pHead;
        while(cur!=NULL)
        {
            if(aft==NULL)
            {
                break;
            }
            if(aft!=NULL && cur->val!=aft->val)
            {
                pre=cur;
                cur=aft;
                aft=aft->next;
            }
            else
            {
                while(aft!=NULL && cur->val==aft->val)
                {
                    aft=aft->next;
                    if(aft==NULL)
                    {
                        if(cur==begin)
                        {
                            begin=NULL;
                            cur=NULL;
                            pre=NULL;
                        }
                        else
                        {
                            pre->next=NULL;
                            cur=NULL;
                        }
                    }
                }
                if(aft!=NULL)
                {
                    if(cur==begin)
                    {
                        cur=aft;
                        begin=aft;
                        pre=aft;
                        aft=aft->next;
                        if(aft==NULL)
                        {
                            pre=cur;
                            cur=NULL;
                        }
                    }
                    else
                    {
                        pre->next=aft;
                        cur=aft;
                        cur->next=aft->next;
                        aft=aft->next;
                        if(aft==NULL)
                        {
                            pre=cur;
                            cur=NULL;
                        }
                    }
                }
            }
        }
        return begin;
    }
	
	ListNode* deleteDuplication2(ListNode* pHead)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        ListNode *begin=pHead;
        ListNode *cur=pHead;
        ListNode *aft=pHead->next;
        ListNode *pre=pHead;
        while(cur!=NULL && aft!=NULL)
        {
            if(aft!=NULL && cur->val!=aft->val)
            {
                pre=cur;
                cur=aft;
                aft=aft->next;
                if(aft==NULL)
                {
                    pre=cur;
                    cur=NULL;
                }
            }
            else
            {
                while(aft!=NULL && cur->val==aft->val)
                {
                    aft=aft->next;
                    if(aft==NULL)
                    {
                        if(cur==begin)
                        {
                            begin=NULL;
                            cur=NULL;
                            pre=NULL;
                        }
                        else
                        {
                            pre->next=NULL;
                            cur=NULL;
                        }
                    }
                }
                if(aft!=NULL)
                {
                    if(cur==begin)
                    {
                        cur=aft;
                        begin=aft;
                        pre=aft;
                        aft=aft->next;
                        if(aft==NULL)
                        {
                            pre=cur;
                            cur=NULL;
                        }
                    }
                    else
                    {
                        pre->next=aft;
                        cur=aft;
                        cur->next=aft->next;
                        aft=aft->next;
                        if(aft==NULL)
                        {
                            pre=cur;
                            cur=NULL;
                        }
                    }
                }
            }
        }
        return begin;
    }
	
	ListNode* deleteDuplication3(ListNode* pHead)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        if(pHead->next==NULL)
        {
            return pHead;
        }
        if(pHead->val==pHead->next->val)
        {
            ListNode *cur=pHead->next->next;
            while(cur!=NULL && pHead->val==cur->val)
            {
                cur=cur->next;
            }
            pHead=deleteDuplication3(cur);
            return pHead;
        }
        else
        {
            pHead->next=deleteDuplication3(pHead->next);
            return pHead;
        }
    }
	
	ListNode* deleteDuplication4(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL)
        {
            return pHead;
        }
        ListNode *cur=pHead;
        ListNode *aft=pHead->next;
        ListNode *begin=pHead;
        ListNode *pre=pHead;
        while(cur!=NULL)
        {
            if(aft!=NULL && cur->val==aft->val)
            {
                while(aft->next!=NULL && cur->val==aft->next->val)
                {
                    aft=aft->next;
                }
                if(cur==begin)
                {
                    begin=aft->next;
                    cur=begin;
                }
                else
                {
                    cur=aft->next;
                    pre->next=cur;
                    if(cur!=NULL)
                    {
                        aft=cur->next;
                    }
                }
            }
            else
            {
                pre=cur;
                cur=aft;
                if(cur!=NULL)
                {
                    aft=cur->next;
                }
            }
        }
        return begin;
    }
	
	ListNode* deleteDuplication5(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL)
        {
            return pHead;
        }
        ListNode *cur=pHead;
        ListNode *aft=pHead->next;
        ListNode *pre=pHead;
        while(cur!=NULL)
        {
            if(aft!=NULL && cur->val==aft->val)
            {
                while(aft->next!=NULL && cur->val==aft->next->val)
                {
                    aft=aft->next;
                }
                if(cur==pHead)
                {
                    pHead=aft->next;
                    cur=pHead;
                }
                else
                {
                    cur=aft->next;
                    pre->next=cur;
                    if(cur!=NULL)
                    {
                        aft=cur->next;
                    }
                }
            }
            else
            {
                pre=cur;
                cur=aft;
                if(cur!=NULL)
                {
                    aft=cur->next;
                }
            }
        }
        return pHead;
    }
	
	ListNode* deleteDuplication6(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL)
        {
            return pHead;
        }
        ListNode *head=new ListNode(-1);
        head->next=pHead;
        ListNode *pre=head;
        ListNode *cur=pHead;
        ListNode *aft=pHead->next;
        while(cur!=NULL)
        {
            if(aft!=NULL && cur->val==aft->val)
            {
                while(aft->next!=NULL && cur->val==aft->next->val)
                {
                    aft=aft->next;
                }
                cur=aft->next;
                pre->next=cur;
                if(cur!=NULL)
                {
                    aft=cur->next;
                }
            }
            else
            {
                pre=cur;
                cur=cur->next;
                if(cur!=NULL)
                {
                    aft=cur->next;
                }
            }
        }
        return head->next;
    }
};

int main()
{
	return 0;
}