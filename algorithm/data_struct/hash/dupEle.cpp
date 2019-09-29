//Given an array of n integers. The task is to print the duplicates in the given array. If there are no duplicates then print -1
#include<iostream>
#include<unordered_map>

using namespace std;

void findDup(int arr[],int n)
{
	unordered_map<int,int> freq;
	for(int i=0;i<n;i++)
		freq[arr[i]]++;
	bool duplicator;
	for(auto iter=freq.begin();iter!=freq.end();iter++)
	{
		if(iter->second>1)
		{
			cout<<iter->first<<"---"<<iter->second<<"\n";
			duplicator=true;
		}
		else
			duplicator=false;
	}
	if(duplicator==false)
		cout<<"-1";
}


int main()
{

    int arr[] = {12, 11, 40, 12, 5, 6, 5, 12, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    findDup(arr, n); 

    return 0;
}
