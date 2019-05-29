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
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        /*
        int row=array.size();
        if(row==0)
        {
            return false;
        }
        int col=array[0].size();
        if(col==0)
        {
            return false;
        }*/
        /*
        int row=array.size();
        int col=array[0].size();
        if(row==0 || col==0)
        {
            return false;
        }
        int ref=array[row-1][0];
        int i=row-1;
        int j=0;
        bool find=true;
        while(ref!=target)
        {
            if(ref>target)
            {
                i--;
                if(i<0)
                {
                    find=false;
                    break;
                }
                ref=array[i][j];
            }
            else if(ref<target)
            {
                j++;
                if(j>(col-1))
                {
                    find=false;
                    break;
                }
                ref=array[i][j];
            }
        }
        return find;
        */
        int row=array.size();
        int col=array[0].size();
        int i=row-1;
        int j=0;
        while(i>=0 && j<col)
        {
            if(array[i][j]<target)
            {
                j++;
            }
            else if(array[i][j]>target)
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
	return 0;
}
