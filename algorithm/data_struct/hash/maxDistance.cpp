//Given an array with repeated elements, the task is to find the maximum distance two occurrences of an element.
//Input : arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
//Output: 10
// maximum distance for 2 is 11-1 = 10
// maximum distance for 1 is 4-2 = 2
// maximum distance for 4 is 10-5 = 5
#include<iostream>
#include<unordered_map>

using namespace std;

int maxDistance(int arr[],int n)
{
	unordered_map<int,int> dist;
	int maxDist=0;
	for(int i=0;i<n;i++)
		if(dist.find(arr[i])==dist.end())
			dist[arr[i]]=i;
		else
			maxDist=max(maxDist,i-dist[arr[i]]);
	return maxDist;
}

int main()
{

    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxDistance(arr, n)<<endl; 
    return 0;
}
