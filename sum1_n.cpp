#include <iostream>
using namespace std;
class Solution{  //luo ji &&, || de duan lu te xing, interesting!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	public:
		int Sum_Solution(int n)//di gui sum(1+2.....+n) wihtout if, for, while....
		{
			if(n==1)  //zhong zhi di gui
			{
				return n;
			}
			return n+Sum_Solution(n-1);
		}
		
		int Sum_Solution1(int n)//di gui sum(1+2.....+n) wihtout if, for, while....
		{
			int x=0;
			n&&(x=n+Sum_Solution1(n-1));// luo ji &&
			return x;
		}
		
		int Sum_Solution2(int n)//di gui sum(1+2.....+n) wihtout if, for, while....
		{
			n&&(n=n+Sum_Solution2(n-1));// luo ji &&
			return n;
		}
};


int main()
{
	
	Solution s1;
	int sum=0;
	sum=s1.Sum_Solution(10);
	cout<<sum<<endl;
	sum=s1.Sum_Solution1(100);
	cout<<sum<<endl;
	sum=s1.Sum_Solution2(99);
	cout<<sum<<endl;
	cout<<(99&&99+1)<<endl;
	
	return 0;
}