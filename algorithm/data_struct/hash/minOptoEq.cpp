//Given an array with n positive integers. We need to find the minimum number of operation to make all elements equal. We can perform addition, multiplication, subtraction or division with any element on an array element.
#include<unordered_map>
#include<iostream>

using namespace std;
int minOperation(int arr[],int n)
{
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
		m[arr[i]]++;

	int maxCount=0;
	for(auto iter:m)
		if(maxCount<iter.second)
			maxCount=iter.second;
	return n-maxCount;
}

int main()
{
	    int arr[] = {1, 5, 2, 1, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minOperation(arr, n)<<endl;

	return 0;
}
