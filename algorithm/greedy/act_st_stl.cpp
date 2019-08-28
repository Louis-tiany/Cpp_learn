#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<functional>
using namespace std;
void selectActivity(vector<int> s,vector<int> f)
{
	vector<pair<int,int>> ans;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;

	for(int i=0;i<s.size();i++)
		p.push(make_pair(f[i],s[i]));

	auto it=p.top();
	int start=it.second;
	int finish=it.first;
	p.pop();
	ans.push_back(make_pair(start,finish));
	while(!p.empty())
	{
		auto iter=p.top();
		p.pop();
		if(iter.second>=finish)
		{
			start=iter.second;
			finish=iter.first;
			ans.push_back(make_pair(start,finish));
		}
	}
	cout<<"Follow activeity  selected\n";
	for(auto itr=ans.begin();itr!=ans.end();itr++)
	{
		cout<<"activity start at:"<<(*itr).first<<"end at"<<(*itr).second<<endl;
	}
}



int main()
{
	vector<int> s ={1, 3, 0, 5, 8, 5};
	vector<int> f= {2, 4, 6, 7, 9, 9};
	selectActivity(s,f);
	return 0;
}
