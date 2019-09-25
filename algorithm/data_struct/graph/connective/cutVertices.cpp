#include<list>
#include<iostream>

#define NIL -1
using namespace std;

class Graph
{
	private:		
		int V;
		list<int> *adj;
		void APUtil(int v,bool visited[],int disc[],int low[],int parent[],bool ap[]);
	public:
		Graph(int V){this->V=V;this->adj=new list<int> [V];}
		void addEdge(int u,int v);
		void AP();
};

void Graph::addEdge(int u,int v)
{	//this is a undirected graph
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::APUtil(int v,bool visited[],int disc[],int low[],int parent[],bool ap[])
{
	static int surTime=0;
	int children=0;

	visited[v]=true;
	disc[v]=low[v]=++surTime;
	
	list<int>::iterator iter;

	for(iter=adj[v].begin();iter!=adj[v].end();++iter)
	{
		int u=*iter;
		if(!visited[u])
		{
			children++;//if the node u hasn't been visited,and this is a children of v
			parent[u]=v;//the parent of u node is v 
			APUtil(u,visited,disc,low,parent,ap);
		
			//check if the node has ancester except v
			low[v]=min(low[v],low[u]);
			//if v is root node and it's children more than 1,it must be a AP node
			if(parent[v]==NIL&&children>1)
				ap[v]=true;
			//if v is not root  
			if(parent[v]!=NIL&&low[u]>=disc[v])
				ap[v]=true;
			
			else if(u!=parent[v])
				low[v]=min(disc[u],low[v]);
		}
	}
}

void Graph::AP()
{
	bool *visited=new bool[V];
	int *disc=new int[V];
	int *low=new int[V];
	int *parent=new int[V];
	bool *ap=new bool[V];
	//initalize visited  ap parent
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
		parent[i]=NIL;
		ap[i]=false;
	}
	for(int i=0;i<V;i++)
		if(visited[i]==false)
			APUtil(i,visited,disc,low,parent,ap);

	for(int i=0;i<V;i++)
		if(ap[i]==true)
			cout<<i<<"    ";

}

int main()
{
    cout << "\nArticulation points in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 
  
    cout << "\nArticulation points in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\nArticulation points in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
    
    cout<<endl;

    return 0;
}
