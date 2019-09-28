#include<iostream>
#include<list>
#include<string.h>
#include<algorithm>
using namespace std;


class Graph
{
	private:
		int V;
		list<int> *adj;
	public:
		Graph(int V){this->V=V;this->adj=new list<int>[V];}
		~Graph(){delete []adj;}
		void addEdge(int u,int v){adj[u].push_back(v);adj[v].push_back(u);}
		void rmvEdge(int u,int v);
		//methods to print eulerian tour
		void printEulerTour();
		void printEulerUtil(int s);
		
		int DFSCount(int v,bool visited[]);
		//methods to check if edge u---v is valid next edge in eulerian trial
		bool isValidEdge(int u,int v);
};

//this function that print euler path.It firstly find an odd degree vertex and call printEulerUtil funtion to print the path
void Graph::printEulerTour()
{
	int u=0;
	for(int i=0;i<V;i++)
		if(adj[i].size()&1==1)
		{
			u=i;//find an odd degree vertex
			break;
		}
	printEulerUtil(u);
	cout<<endl;
}

//print euler tour start with given vertex u
void Graph::printEulerUtil(int u)
{
	list<int>::iterator iter;
	for(iter=adj[u].begin();iter!=adj[u].end();iter++)
	{
		int v=*iter;
		//if edge u---v hasn't been removed and u--v is valid edge,print it
		if(v!=-1&&isValidEdge(u,v))
		{
			cout<<u<<"----"<<v<<"  ";
			rmvEdge(u,v);
			printEulerUtil(v);
		}
	}
}

bool Graph::isValidEdge(int u,int v) 
{
	//two cases
	//first case:v is the only vertex of u
	list<int>::iterator iter;
	int countVertices=0;
	for(iter=adj[u].begin();iter!=adj[u].end();iter++)
		if(*iter!=-1)
			countVertices++;
	if(countVertices==1)
		return true;

	//second case:if there are multiple adjacent vertices,and u---v is not bridge edge
	//following operation is checking if u---v is a bridge edge
	//2.a count number of vertices u can reachable
	int count1=0;
	bool visited[V];
	memset(visited,false,V);
	count1=DFSCount(u,visited);
	
	//2.b remove edge u---v,after removing the edge,count vertices reachable from u
	rmvEdge(u,v);
	memset(visited,false,V);
	int count2=DFSCount(u,visited);

	//2.c add edge back to graph
	addEdge(u,v);
	//2.d if count1 is greater than count2,u---v is a bridge
	return (count1>count2)?false:true;
}
//removes edge by replacing adjacent vertex value with -1
void Graph::rmvEdge(int u,int v)
{
	list<int>::iterator iteru=find(adj[u].begin(),adj[u].end(),v);
	*iteru=-1;
	list<int>::iterator iterv=find(adj[v].begin(),adj[v].end(),u);
	*iterv=-1;
}

int Graph::DFSCount(int v,bool visited[])
{
	visited[v]=true;
	int countV=1;
	
	list<int>::iterator iter;
	for(iter=adj[v].begin();iter!=adj[v].end();iter++)
		if((*iter!=-1&&visited[*iter]==false))
			countV+=DFSCount(*iter,visited);
	return countV;
}

int main()
{
  // Let us first create and test graphs shown in above figure 
  Graph g1(4); 
  g1.addEdge(0, 1); 
  g1.addEdge(0, 2); 
  g1.addEdge(1, 2); 
  g1.addEdge(2, 3); 
  g1.printEulerTour(); 
  
  Graph g2(3); 
  g2.addEdge(0, 1); 
  g2.addEdge(1, 2); 
  g2.addEdge(2, 0); 
  g2.printEulerTour(); 
  
  Graph g3(5); 
  g3.addEdge(1, 0); 
  g3.addEdge(0, 2); 
  g3.addEdge(2, 1); 
  g3.addEdge(0, 3); 
  g3.addEdge(3, 4); 
  g3.addEdge(3, 2); 
  g3.addEdge(3, 1); 
  g3.addEdge(2, 4); 
  g3.printEulerTour(); 


	return 0;
}
