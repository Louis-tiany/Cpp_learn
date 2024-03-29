//Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
#include<iostream>
#include<map>
using namespace std;


bool canPairs(int arr[],int n,int k)
{
	if(n&1)
		return false;
	map<int ,int > freq;
	//count occurances of all remainders 
	for(int i=0;i<n;i++)
		freq[arr[i]%k]++;
	for(int i=0;i<n;i++)
	{
		int rem=arr[i]%k;
		if(rem*2==k)
			if(freq[rem]%2!=0)
				return false;
		else if(rem==0)
			if(freq[rem]&1)
				return false;
 		 // Else number of occurrences of remainder 
	        // must be equal to number of occurrences of 
        	// k - remainder 
		else if(freq[rem]!=freq[k-rem])
			return false;
	}
	return true;
}

int main()
{
    int arr[] =  {92, 75, 65, 48, 45, 35}; 
    int k = 10; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    canPairs(arr, n, k)? cout << "True": cout << "False";
    cout<<"\n";
    return 0;
}
