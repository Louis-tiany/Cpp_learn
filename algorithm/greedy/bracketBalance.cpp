#include<string>
#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;
long swapCount(string s)
{
	vector<int> pos;
	for(int i=0;i<s.length();++i)
		if(s[i]=='[')
			pos.push_back(i);
	int coun=0;
	int p=0;
	long sum=0;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='[')
		{
			++coun;
			++p;
		}
		else if (s[i]==']')
			--coun;
		if(coun<0)
		{
			sum+=pos[p]-i;//distance of ] and  next [
			swap(s[pos[p]],s[i]);

			++p;//p is the next element will be visited
			coun=1;
		}
	}
	return sum;
}

int main()
{

    string s = "[]][]["; 
    cout << swapCount(s) << "\n"; 

    s = "[[][]]"; 
    cout << swapCount(s) << "\n"; 
    return 0;
}

