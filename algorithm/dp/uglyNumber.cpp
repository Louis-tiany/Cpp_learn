#include<stdio.h>
#include<iostream>

using namespace std;


class UglyLoop
{
	private:
		int maxDivide(int a,int b)//get max divsible power
		{
			while(a%b==0)
				a=a/b;
			return a;
		}
		int isUgly(int no)
		{
			no=maxDivide(no,2);
			no=maxDivide(no,3);
			no=maxDivide(no,5);
			return (no==1)?1:0;
		}
	public:
		int getNthUglyno(int n)
		{
			int i=1;
			int coun=1;
			while(n>coun)
			{
				i++;
				if(isUgly(i))
					coun++;

			}
			return i;
		}
		void printUgly(int n)
		{
			    unsigned no = getNthUglyno(150);
			    printf("150th ugly no. is %d \n",  no);
		}
};


class UglyDp
{
	private:
		unsigned int getUgly(unsigned int n)
		{
			unsigned int ugly[n];//dp arr
			unsigned int i2=0,i3=0,i5=0;
			unsigned int next2=2;
			unsigned int next3=3;
			unsigned int next5=5;
			unsigned int  nextUgly=1;
			ugly[0]=1;
			for(int i=1;i<n;i++)
			{
				nextUgly=min(next2,min(next3,next5));
				ugly[i]=nextUgly;
				if(nextUgly==next2)
				{
					++i2;
					next2=ugly[i2]*2;
				}
				if(nextUgly==next3)
				{
					++i3;
					next3=ugly[i3]*3;
				}
				if(nextUgly==next5)
				{
					++i5;
					next5=ugly[i5]*5;
				}
			}
			return nextUgly;
		}
	public:
		void printUgly(unsigned int n)
		{
			unsigned int x=getUgly(n);
			cout<<x<<endl;
		}
};



int main()
{
	UglyLoop a;
	a.printUgly(150);
	
	UglyDp b;
	b.printUgly(150);
	return 0;
}

