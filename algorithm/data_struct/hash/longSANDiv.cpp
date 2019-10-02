//Given an array of N non-negative integers, task is to find the maximum size of a subarray such that the pairwise sum of the elements of this subarray is not divisible by a given integer, K. Also, print this subarray as well. If there are two or more subarrays which follow the above stated condition, then print the first one from the left.
#include<iostream>
#include<map>

using namespace std;

// function to find the subarray with // no pair sum divisible by k
void subarrayNDiv(int arr[],int n,int k)
{
	map<int,int> mp;//store remainders obtained by k
	    // s : starting index of the     
	    // current subarray, e : ending  
	    // index of the current subarray, maxs :     
	    //starting index of the maximum     
	    //size subarray so far, maxe : ending     
	    //index of the maximum size subarray     
	int s=0,e=0,maxs=0,maxe=0;

	mp[arr[0]%k]++;
	for(int i=1;i<n;i++)
	{
		int mod=arr[i]%k;
		while(mp[k-mod]!=0||(mod==0&&mp[mod]!=0))
		{
			mp[arr[s]%k]--;
			s++;
		}
		//include current element
		mp[mod]++;
		e++;

		if((e-s)>maxe-maxs)
		{
			maxe=e;
			maxs=s;
		}
	}
	cout << "The maximum size is "
         << maxe - maxs + 1 << " and "
         "the subarray is as follows\n"; 
	for (int i=maxs; i<=maxe; i++) 
        cout << arr[i] << " "<<"\n"; 
}
int main()
{
    int k = 3; 
    int arr[] = {5, 10, 15, 20, 25}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    subarrayNDiv(arr, n, k); 
	
    return 0;
}
