//Given an array of length N that contains only integers, the task is to print the special numbers of array. A number in this array is called Special number if it is divisible by at least one other number in the array.
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void divCheck(int arr[],int n,int k)
{
	unordered_set<int ,int> s;
	int maxEle=INT_MIN;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
		maxEle=max(maxEle,arr[i]);
	}
	unordered_set<int> res;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
			for(int j=arr[i]*2;j<=maxEle;j+=arr[i])
				if(s.find(j)!=s.end())
					res.insert(j);
	}
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	unordered_map<int,int>::iterator iter;
	vector<int> ans;
	for(iter=mp.begin();iter!=mp.end();iter++)
	{
		if(iter->second==2)
		{
			if(res.find(iter->first)==res.end())
			{
				int val=iter->second;
				while(val--)
					ans.push_back(iter->first);
			}
		}
		if(res.find(iter->first)!=res.end())
		{
			int val=iter->second;
			while(val--)
				ans.push_back(iter->first);
		}
	}
	for(auto x:ans)
		cout<<x<<"    ";
	cout<<endl;
}


int main()
{
    int arr[] = { 2, 3, 8, 6, 9, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    divCheck(arr, n); 

	return 0;
}
