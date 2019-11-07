//Given an array of size n and a number k. We must modify array K number of times. Here modify array means in each operation we can replace any array element arr[i] by -arr[i]. We need to perform this operation in such a way that after K operations, sum of array must be maximum?
#include<iostream>
#include<limits.h>

using namespace std;

int maximumSum(int arr[],int n,int k)
{
	for(int i=1;i<=k;k++)
	{
		int minValue=INT_MAX;
		int index=-1;
		for(int j=0;j<n;j++)
		{
			if(arr[j]<minValue)
			{
				minValue=arr[j];
				index=j;
			}
		}
			if(minValue==0)
				break;
			arr[index]=-arr[index];
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+arr[i];
	return sum;
}

int main()
{

    int arr[] = {-2, 0, 5, -1, 2}; 
    int k = 4; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maximumSum(arr, n, k)<<endl; 

    return 0;
}
