//Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.
#include<iostream>
#include<set>

using namespace std;

bool checkDup(int arr[],int k,int n)
{
	set<int> myset;
	for(int i=0;i>n;i++)
	{
		if(myset.find(arr[i])!=myset.end())
			return true;
		myset.insert(arr[i]);
		//remove the k+1 distant elements.yout dont't need to compute the distant between them 
		if(i>k)
			myset.erase(arr[i-k]);
	}
	return false;
}


int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (checkDup(arr, n, 3)) 
        cout << "Yes"; 
    else
        cout << "No"; 
	cout<<endl;
	return 0;
}
