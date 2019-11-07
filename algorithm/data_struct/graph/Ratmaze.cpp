#include<stdio.h>
#include<iostream>

#define N 4
using namespace std;

void printRes(int res[N][N])
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;j++)
			printf("%d",res[i][j]);
		printf("\n");
	}		
}

bool isReachable(int maze[N][N],int m,int n)
{
	if(m<N-1&&m>0&&n<N-1&&n>0&&maze[m][n]==1)
		return true;
	else
		return false;
}
bool solveMazeUtil(int maze[N][N],int m,int n,int res[N][N])
{
	if(m==N-1&&n==N-1)	
	{
		res[m][n]=1;
		return 1;
	}	
	if(isReachable(maze,m,n)==true)
	{
		res[m][n]=1;
		if(isReachable(maze,m+1,n)==true)
			return true;
		if(isReachable(maze,m,n+1)==true)
			return true;
		res[m][n]=0;
		return false;
	}
	return false;
}

bool solveMaze(int maze[N][N])
{
	    int res[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
	if(solveMazeUtil(maze,0,0,res)==false)
		return false;
	printRes(res);
	return true;
}

int main()
{
	int maze[N][N]={{ 1, 0, 0, 0}, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 }}; 
	solveMaze(maze);
	return 0;
}

