#include<iostream>
#include<list>
#define NIL -1
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void bridgeUtil(int v,bool visited[],int disc[],int low[],int parent[]);
	public:
	Graph(int V);
	void addEdge(int u,int v);
	void bridge();
};

Graph::Graph(int V)
{
	this->V=V;
	this->adj=new list<int>[V];
}

void Graph::addEdge(int u,int v)
{	//this is a undirected graph
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::bridgeUtil(int u,bool visited[],int disc[],int low[],int parent[])
{
	static int dfsTime=0;
	//mark current vertex visited
	visited[u]=true;
	disc[u]=low[u]=++dfsTime;

	list<int>::iterator iter;
	for(iter=adj[u].begin();iter!=adj[u].end();iter++)
	{
		int v=*iter;
		//if v hasn't been visited,u---v is tree edge
		if(visited[v]==false)
		{
			parent[v]=u;
			bridgeUtil(v,visited,disc,low,parent);

		
			//check if subtree has a connection to ancestor of vertex u
			//find back edge
			low[u]=min(low[u],low[v]);
			//if v's ancestor below u in dfs tree,and u---v is a bridge edge
			if(low[v]>disc[u])
				cout<<u<<"---"<<v<<"\n";
		}
		else if(v!=parent[u])
			low[u]=min(low[u],disc[v]);//update low value of u if v 
	}
}

void Graph::bridge()
{
	bool *visited = new bool[V];
	int *disc=new int[V];
	int *low=new int[V];
	int *parent=new int[V];
	for(int v=0;v<V;v++)
	{
		parent[v]=NIL;
		visited[v]=false;
	}
	for(int v=0;v<V;v++)
		if(visited[v]==false)
			bridgeUtil(v,visited,disc,low,parent);
}



int main()
{

    cout << "\nBridges in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
  
    cout << "\nBridges in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.bridge(); 
  
    cout << "\nBridges in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.bridge(); 

	return 0;
}
