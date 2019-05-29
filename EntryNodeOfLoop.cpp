#include <stdio.h>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <unordered_set>
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
    ListNode* EntryNodeOfLoop1(ListNode* pHead)  //using set,easy to understand it
    {
        unordered_set <ListNode *> lopset;
        while(pHead!=NULL)
        {
            if(lopset.count(pHead)==0)
            {
                lopset.insert(pHead);
            }
            else
            {
                return pHead;
            }
            pHead=pHead->next;
        }
        return NULL;
    }
	
    ListNode* EntryNodeOfLoop2(ListNode* pHead)
    {      
       if(pHead==NULL)
       {
           return NULL;
       }
       ListNode *slow=pHead->next;   //slow pointer go 1 step
       if(slow==NULL)
       {
           return NULL;
       }
       ListNode *fast=pHead->next->next;  //fast pointer go 2 steps
        ListNode *meet=NULL;
        while(fast!=NULL)// when there is a loop in the link, fast must meet slow in this loop, when fast is two times as slow
        {
            if(slow==fast)   //genius thinking
            {
                meet=slow;
                break;
            }
            slow=slow->next;
            if(fast->next==NULL || fast->next->next==NULL)
            {
                return NULL;
            }
            fast=fast->next->next;
        }
        ListNode *meet1=meet->next;
        int lengthofring=1;
        while(meet1!=meet) //when we find a point in the loop, let the pointer go, it will come back to this point and get the length of the loop
        {
            meet1=meet1->next;
            lengthofring++;//get length of the loop
        }
        fast=pHead;
        slow=pHead;
        for(int i=0;i<lengthofring;i++)//when there are m nodes in the loop,first the fast pointer go m steps, then fast and slow go together 
        {// then the fast and slow pointer must meet at the beginning of the loop, it can be analysed by math
            fast=fast->next;
        }
        while(fast!=slow)//genius thinking
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
	
    ListNode* EntryNodeOfLoop3(ListNode* pHead)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        ListNode *slow=pHead->next;//slow pointer go 1 step
        if(slow==NULL)
        {
            return NULL;
        }
        ListNode *fast=pHead->next->next;//fast pointer go 2 steps
        ListNode *meet=NULL;// when there is a loop in the link, fast must meet slow in this loop, when fast is two times as slow
        while(fast!=NULL)
        {
            if(slow==fast) //genius thinking
            {
                meet=slow;
                break;
            }
            slow=slow->next;
            if(fast->next==NULL || fast->next->next==NULL)
            {
                return NULL;
            }
            fast=fast->next->next;
        }
        fast=meet;  //see blog, genius thinking in math
        slow=pHead; //see blog, genius thinking in math
        while(fast!=slow) //see blog, genius thinking in math
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

int main()
{
	return 0;
}
