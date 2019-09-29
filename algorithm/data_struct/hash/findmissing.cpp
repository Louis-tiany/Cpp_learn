//Given an array arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in range, but not in array. The missing elements should be printed in sorted order.

#include<iostream>
#include<unordered_set>

using namespace std;

void findMissing(int arr[],int n,int low,int high)
{
	unordered_set<int> s;
	for(int i=0;i<n;i++)
		s.insert(arr[i]);
	for(int x=low;x!=high;x++)
		if(s.find(x)==s.end())
			cout<<x<<"   ";
	cout<<endl;
}
int main()
{
   int arr[] = {1, 3, 5, 4}; 
   int n = sizeof(arr)/sizeof(arr[0]); 
   int low = 1, high = 10; 
   findMissing(arr, n, low, high); 

	
   return 0;
}
