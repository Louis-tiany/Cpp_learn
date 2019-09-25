#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph
{
	private:
		int V;
		list<int>* adj;
		void dfsUtil(int v,bool visited[]);
	public:
		Graph(int V){this->V=V;adj=new list<int>[V];}
//		~Graph(){delete [] adj;}
 		void addEdge(int v,int w);
		Graph getTranspose();
		bool isSC();
};

void Graph::dfsUtil(int v,bool visited[])
{
	visited[v]=true;
	list<int>::iterator iter;
	for(iter=adj[v].begin();iter!=adj[v].end();iter++)
		if(!visited[*iter])
			dfsUtil(*iter,visited);
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);		
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for(int v=0;v<V;v++)
	{
		list<int>::iterator iter;
		for(iter=adj[v].begin();iter!=adj[v].end();iter++)
			//graph->adj:u->*iter------>g->adj:*iter->u;exchange u and *iter
			g.adj[*iter].push_back(v);
	}
	return g;
}

bool Graph::isSC()
{
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	dfsUtil(0,visited);
	//if dfs don't visit all vertices return false
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			return false;
	//create reversed graph,and check 
	Graph g=getTranspose();
	for(int i=0;i<V;i++)
		visited[i]=false;
	g.dfsUtil(0,visited);
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			return false;
	return true;
}

int main()
{
    Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 0); 
    g1.addEdge(2, 4); 
    g1.addEdge(4, 2); 
    g1.isSC()? cout << "Yes\n" : cout << "No\n"; 
  
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.isSC()? cout << "Yes\n" : cout << "No\n"; 

    return 0;
}
