//Given an array of n elements such that elements may repeat. We can delete any number of elements from array. The task is to find minimum number of elements to be deleted from array to make it equal.
#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;


int minDele(int arr[],int n)
{
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	//find max freq of among all frequencies
	int maxFreq=INT_MIN;
	for(auto iter=freq.begin();iter!=freq.end();iter++)
		maxFreq=max(maxFreq,iter->second);
	return n-maxFreq;
}

int main()
{
    int arr[] = {4, 3, 4, 4, 2, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << minDele(arr, n)<<endl; 
	
    return 0;
}

