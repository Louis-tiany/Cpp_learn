#include<algorithm>
#include<boost/functional/hash.hpp>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;


int maxPoints(vector<pair<int,int>> points)
{
	int N=points.size();
	int curMax,overlapPoints,verticalPoints;
	if(N<2)
		return N;
	int maxPoint=0;
	
	unordered_map<pair<int,int>,int,boost::hash<pair<int,int>>> slopeMap;
	for(int i=0;i<N;i++)
	{
		curMax=overlapPoints=verticalPoints=0;
		for(int j=i+1;j<N;j++)
		{	
			//two points are equal
			if(points[i]==points[j])
				overlapPoints++;
			//x相等，垂直与x轴的线
			else if(points[i].first==points[j].second)
				verticalPoints++;
			else
			{
				int xDiff=points[j].first-points[i].first;
				int yDiff=points[j].second-points[i].second;
				int g=__gcd(xDiff,yDiff);
				
				//reduce the difference by their gcd
				xDiff /= g;
				yDiff /= g;
				
				//note the frequency of xdiff and ydiff
				slopeMap[make_pair(xDiff,yDiff)]++;
				curMax=max(curMax,slopeMap[make_pair(xDiff,yDiff)]);
			}
			curMax=max(curMax,verticalPoints);
		}
		maxPoint=max(maxPoint,curMax+overlapPoints+1);
		slopeMap.clear();
	}
	return maxPoint;
}



int  main()
{

    const int N = 6; 
    int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, 
                    {3, 3}, {3, 4}}; 
  
    vector< pair<int, int> > points; 
    for (int i = 0; i < N; i++) 
        points.push_back(make_pair(arr[i][0], arr[i][1])); 
  
    cout << maxPoints(points) << endl; 

    return 0;
}
