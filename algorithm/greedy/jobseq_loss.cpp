#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>


using namespace std;


typedef pair<int ,pair<int,int>> job;

bool cmp_pair(job a,job b)
{
	int a_Li,a_Ti,b_Li,b_Ti;
	a_Li=a.second.first;
	a_Ti=a.second.second;
	b_Li=b.second.first;
	b_Ti=b.second.second;
	return (a_Li*b_Ti>b_Li*a_Ti);
}
void printOptimal(int L[],int T[],int N)
{
	vector<job> list;
	for(int i=0;i<N;i++)
	{
		int t=T[i];
		int l=L[i];
		list.push_back(make_pair(i+1,make_pair(l,t)));
	}
	stable_sort(list.begin(),list.end(),cmp_pair);
	cout<<"Job num in minmum loss:\n";
	for(int i=0;i<N;i++)
		cout<<list[i].first<<"\n";
}

int main()
{
    int L[] = { 1, 2, 3, 5, 6 }; 
    int T[] = { 2, 4, 1, 3, 2 }; 
    int N = sizeof(L) / sizeof(L[0]); 
    printOptimal(L, T, N); 	
	
    
    return 0;
}
