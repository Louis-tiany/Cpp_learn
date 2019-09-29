//Given an array of distinct integers, print all the pairs having positive value and negative value of a number that exists in the array. We need to print pairs in order of their occurrences. A pair whose any element appears first should be printed first.
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

//two loops

void getpairs(int arr[],int n)
{
	vector<int> v;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(abs(arr[i])==abs(arr[j]))
				v.push_back(abs(arr[i]));
	if(v.size()==0)
		return;
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		cout<<-v[i]<<"  "<<v[i];
}

void printpairs(int arr[],int n)
{
	vector<int> v;
	unordered_map<int,bool> cnt;
	for(int i=0;i<n;i++)
	{
		if(cnt[abs(arr[i])]==0)
			cnt[abs(arr[i])]=true;
		else
		{
			v.push_back(abs(arr[i]));
			cnt[abs(arr[i])]=false;
		}
	}
	if(v.size()==0)
		return;
	sort(v.begin(),v.end());
	
    sort(v.begin(), v.end()); 
    for (int i = 0; i < v.size(); i++) 
        cout << -v[i] << " " << v[i] << " "; 
    cout<<endl;

}


int main()
{
    int arr[] = { 4, 8, 9, -4, 1, -1, -8, -9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    getpairs(arr,n);
    cout<<endl;
    printpairs(arr, n); 
    return 0; 

}
