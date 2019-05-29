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

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone1(RandomListNode* pHead)  //san bu cha ru fa, see blog
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        RandomListNode* p1=pHead;
        RandomListNode* p2=pHead;
        while(p1!=NULL)
        {
            RandomListNode* clone=new RandomListNode(p1->label);
            clone->next=p1->next;
            p1->next=clone;
            p1=p1->next->next;
        }
        while(p2!=NULL)
        {
            if(p2->random!=NULL)//important, boundary condition, deal with NULL situation
            {
                p2->next->random=p2->random->next;
            }
            p2=p2->next->next;
        }
        RandomListNode* p3=pHead;
        RandomListNode* p4=pHead->next;
        RandomListNode* p5=pHead->next;
        while(p3!=NULL)
        {
            p3->next=p3->next->next;
            if(p4->next!=NULL)
            {
                p4->next=p4->next->next;
            }
            p3=p3->next;
            p4=p4->next;
        }
        return p5;
    }
	
    RandomListNode* Clone2(RandomListNode* pHead)  //using map(ordered) method, it's easy to realize it(or can use unordered_map)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        map<RandomListNode*,RandomListNode*> clone;
        RandomListNode *h=pHead;
        RandomListNode *p=new RandomListNode(h->label);
        clone[h]=p;
        while(h->next!=NULL)
        {
            h=h->next;
            p->next=new RandomListNode(h->label);
            p=p->next;
            clone[h]=p;
        }
        map<RandomListNode*,RandomListNode*>::iterator iter;
        iter=clone.begin();
        while(iter!=clone.end())
        {
            if(iter->first->random!=NULL)
            {
                iter->second->random=clone[iter->first->random];
            }
            iter++;
        }
        return clone[pHead];
    }
	
    RandomListNode* Clone3(RandomListNode* pHead)
    {
        if(pHead==NULL)
        {
            return NULL;
        }
        RandomListNode *clone=new RandomListNode(pHead->label);
        map1[pHead]=clone;
        clone->next=Clone3(pHead->next);
        if(pHead->random!=NULL)
        {
            clone->random=map1[pHead->random];
        }
        return clone;
    }
    unordered_map<RandomListNode *,RandomListNode *>map1;
};

int main()
{
	return 0;
}
