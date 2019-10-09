#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int policeThief(char arr[],int n,int k)
{
	int res=0;
	vector<int> thi;
	vector<int> pol;
	for(int i=0;i<n;++i)
	{
		if(arr[i]=='T')
			thi.push_back(i);
		else if(arr[i]=='P')
			pol.push_back(i);
	}
	int l=0,r=0;
	while(l<thi.size()&&r<pol.size())//when still have thi and pol,do the loop
	{
		//can be caught
		if(abs(thi[l]-pol[r])<=k)
		{
			res++;
			l++;
			r++;//consume a pol and a thi
		}
		else if(thi[l]<pol[r])//can't caught,should incrment l or r
			l++;
		else
			r++;
	}
	return res;
}

int main()
{

    int k,n;
    char arr1[] = { 'P', 'T', 'T', 'P', 'T' }; 
    k = 2; 
    n = sizeof(arr1) / sizeof(arr1[0]); 
    cout << "Maximum thieves caught: "
         << policeThief(arr1, n, k) << endl; 
  
    char arr2[] = { 'T', 'T', 'P', 'P', 'T', 'P' }; 
    k = 2; 
    n = sizeof(arr2) / sizeof(arr2[0]); 
    cout << "Maximum thieves caught: "
         << policeThief(arr2, n, k) << endl; 
  
    char arr3[] = { 'P', 'T', 'P', 'T', 'T', 'P' }; 
    k = 3; 
    n = sizeof(arr3) / sizeof(arr3[0]); 
    cout << "Maximum thieves caught: " 
         << policeThief(arr3, n, k) << endl; 
	return 0;
}


