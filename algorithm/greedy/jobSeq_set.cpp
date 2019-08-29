#include<iostream>
#include<set>


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
		for(int i=0;i<n;i++)
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
		parent[c]=u;
	}
};

bool cmp(job a u,job b)
{
	return (a.profit>b.profit);
}

int findJobScheduling(job arr[],int n)
{
	sort(arr,arr+n,cmp); 
	maxDeadline=findMaxDeadline(arr,n);

}


int main()
{

	return 0;
}
