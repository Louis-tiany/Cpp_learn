#include<iostream>


using namespace std;

unsigned int fiboIter(unsigned int n)
{
	if(n<=1)
		return n;
	return fiboIter(n-1)+fiboIter(n-2);
}

unsigned int fiboDp(unsigned int n)
{
	unsigned int fi[n+2];
	unsigned int i;
	fi[0]=0;
	fi[1]=1;
	for(i=2;i<=n;i++)
		fi[i]=fi[i-1]+fi[i-2];
	return fi[n];
}



int main()
{
	unsigned int n=30;
	cout<<fiboIter(n)<<"\n";

	cout<<fiboDp(n)<<endl;

	return 0;
}
