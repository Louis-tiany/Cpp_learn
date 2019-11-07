#include<limits.h>
#include<iostream>

using namespace std;


int minProduct(int a[],int n)
{
	if(n==1)
		return a[0];
	int maxNeg=INT_MIN;
	int minPos=INT_MAX;
	int countNeg=0;
	int countZero=0;
	int prod=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			countZero++;
			continue;
		}
		if(a[i]<0)
		{
			countNeg++;
			maxNeg=max(maxNeg,a[i]);
		}
		if(a[i]>0)
			minPos=min(minPos,a[i]);
		prod=prod*a[i];
	}
	if(countZero==n||(countNeg==0&&countZero>0))
		return 0;
	if(countNeg==0)
		return minPos;
	if(!(countNeg&1)&&countNeg!=0)//if nnumber negative is even
		prod=prod/maxNeg;

	return prod;
}
int main()
{
    int a[] = { -1, -1, -2, 4, 3 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << minProduct(a, n)<<endl; 
	return 0;
}

