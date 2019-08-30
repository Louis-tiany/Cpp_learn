#include<limits.h>
#include<algorithm>
#include<iostream>


using namespace std;

struct job
{
	char id;
	int deadline;
	int profit;
};

struct disjointSet
{
	int *parent;
	disjointSet(int n)
	{
		parent = new int[n+1];
		for(int i=0;i<=n;i++)
			parent[i]=i;
	}
	int find(int s)
	{
		if(s==parent[s])
			return s;
		return parent[s]=find(parent[s]);
	}
	void merge(int u,int v)
	{
		parent[v]=u;
	}
};

bool cmp(struct job a,struct job b)
{
	return (a.profit>b.profit);
}

int findMaxDeadline(struct job arr[],int n)
{
	int ans=-1;
	for(int i=0;i<n;i++)
		ans=max(ans,arr[i].deadline);
	return ans;
}

int findJobScheduling(struct job arr[],int n)
{
	sort(arr,arr+n,cmp); 
	int maxDeadline=findMaxDeadline(arr,n);
	disjointSet ds(maxDeadline);

	for(int i=0;i<n;i++)
	{
		int availableSlot=ds.find(arr[i].deadline);
		if(availableSlot>0)
		{
			ds.merge(ds.find(availableSlot-1),availableSlot);
			cout<<arr[i].id<<"    ";
		}
	}
	return 0;
}


int main()
{

	struct job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 },  
                   { 'c', 2, 27 },  { 'd', 1, 25 },  
                   { 'e', 3, 15 } }; 
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"job be selected:"<<"\n";
	findJobScheduling(arr,n);
	cout<<endl;
	return 0;
}
