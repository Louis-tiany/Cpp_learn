//Given an arr[] containing n integers and a positive integer k. The problem is to find the length of the longest subarray with sum of the elements divisible by the given value k.

#include<iostream>
#include<unordered_map>

using namespace std;

int longSubArrWithSumDiv(int arr[],int n,int k)
{
	unordered_map<int,int> um;
	int modArr[n];
	int maxValue=0;
	int currSum=0;
	for(int i=0;i<n;i++)
	{
		currSum+=arr[i];
		modArr[i]=(currSum%k+k)%k;//lest currSum%k is negative,get mode twice
	}

	for(int i=0;i<n;i++)
	{
		if(modArr[i]==0)
			maxValue=i+1;
		else if(um.find(modArr[i])==um.end())
			um[modArr[i]]=i;
		else
			//if true, then update 'max',this is a hard point
			if(maxValue<(i-um[modArr[i]]))
				maxValue=i-um[modArr[i]];
	}
	return maxValue;
}

int main()
{
    int arr[] = {2, 7, 6, 1, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
      
    cout << "Length = "
         << longSubArrWithSumDiv(arr, n, k)>>"\n"; 

    return 0;
}
