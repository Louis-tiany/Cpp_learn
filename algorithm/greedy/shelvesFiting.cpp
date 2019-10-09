#include<iostream>

using namespace std;


void minSpacePreferLarge(int wall,int m,int n)
{
	//assume m < n
	int mNum=0;
	int nNum=0;
	int minEmpty=wall;
	int p=0,q=0;
	int rem;//remain of wall
	while(wall>=n)
	{
		p=wall/m;
		rem=wall%m;
		if(rem<minEmpty)
		{
			mNum=p;
			nNum=q;
			minEmpty=rem;
		}
		q+=1;
		wall=wall-n;

	}

    cout << mNum<< " " << nNum << " "
         << minEmpty << endl; 
}

int main()
{
    int wall = 24, m = 3, n = 5; 
    minSpacePreferLarge(wall, m, n); 
  
    wall = 24, m = 4, n = 7; 
    minSpacePreferLarge(wall, m, n); 
	return 0;
}

