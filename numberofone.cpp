#include <iostream>
using namespace std;
class Solution
{
		public:
			int NumberOF1(int n) //1st. the best algorithm
			{
				int count=0;
				while(n!=0)   //(n&(n-1))
				{
					n=(n&(n-1));
					count++;
				}
				return count;
			}
			
			int NumberOF12(int n) //2nd
			{
				int count=0;
				int i;
				int x;
				for(i=0;i<32;i++)
				{
					x=((n>>i)&1);
					if(x==1)
					{
						count++;
					}
				}
				return count;
			}
			
			int NumberOF13(int n)  //3rd
			{
				int count=0;
				if(n<0)
				{
					count++;
					n=n&(0x7FFFFFFF);//convert signed to unsigned
				}	
				while(n!=0)
				{
					if((n&1)==1)
					{
						count++;
					}
					n=n>>1;
				}
				return count;
			}
			
			int NumberOF01(int n)
			{
				int count=0;
				while(n!=0)   //(n&(n-1)),best algorithm
				{
					n=(n&(n-1));
					count++;
				}
				count=32-count;
				return count;
			}
			
			int NumberOF02(int n)
			{
				int count=0;
				int i;
				int x;
				for(i=0;i<32;i++)
				{
					x=((n>>i)&1);
					if(x==0)
					{
						count++;
					}
				}
				return count;
			}
			
			int NumberOF03(int n)
			{
				int count=0;
				int shift=0;
				if(n<0)
				{
					count--;
					n=n&(0x7FFFFFFF);//convert signed to unsigned
				}	
				while(n!=0)
				{
					if((n&1)!=1)
					{
						count++;
					}
					n=n>>1;
					shift++;
				}
				count=count+(32-shift);
				return count;
			}
			
			int Numberofleadingzeros(int n)
			{
				int mask=0x80000000;
				int x=0;
				int count=0;
				x=n&mask;
				while(x==0)
				{
					count++;
					n=n<<1;
					x=n&mask;
				}
				return count;
			}

};
int main()
{
	Solution sl;
	int num=0;
	num=sl.NumberOF1(10);
	cout<<num<<endl;
	num=sl.NumberOF12(10);
	cout<<num<<endl;
	num=sl.NumberOF13(10);
	cout<<num<<endl;
	num=sl.NumberOF01(10);
	cout<<num<<endl;
	num=sl.NumberOF02(10);
	cout<<num<<endl;
	num=sl.Numberofleadingzeros(4);
	cout<<num<<endl;
	return 0;
}
