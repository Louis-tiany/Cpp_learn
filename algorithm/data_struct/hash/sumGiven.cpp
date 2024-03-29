#include<iostream>
#include<unordered_set>

using namespace std;


void printPairs(int arr[],int arrSize,int sum)
{
	unordered_set<int> s;
	for(int i=0;i<arrSize;i++)
	{
		int temp=sum-arr[i];
		if(s.find(temp)!=s.end())
			 cout << "Pair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << endl;
		s.insert(arr[i]);
	}
}


int main()
{

    int A[] = { 1, 4, 45, 6, 10, 8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    // Function calling
    printPairs(A, arr_size, n);
	return 0;
}
