#include<iostream>
#include<stack>
#include<list>
#define NIL -1
using namespace std;
int bccCount=0;
class Edge
{
	public:
		int u,v;
		Edge(int u,int v);
};

Edge::Edge(int u,int v)
{
	this->u=u;
	this->v=v;
}

class Graph
{
	private:
		int V;
		int E;
		list<int> *adj;
		void BCCUtil(int u,int disc[],int low[],list<Edge> *st,int parent[]);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void BCC();
};

Graph::Graph(int V)
{
	this->V=V;
	this->E=0;
	adj=new list<int>[V];
}

void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	E++;
}

void Graph::BCCUtil(int u,int disc[],int low[],list<Edge> *st,int parent[])
{
	static int dfsTime=0;
	disc[u]=low[u]=++dfsTime;
	int children=0;
	
	//visit all vertices 
	list<int>::iterator iter;
	for(iter=adj[u].begin();iter!=adj[u].end();iter++)
	{
		int v=*iter;
		//if vertex is not visited, it is a children of u
		if(disc[v]==-1)
		{
			children++;
			parent[v]=u;
			//u---v is a tree edge,store them
			st->push_back(Edge(u,v));
			BCCUtil(v,disc,low,st,parent);
			//check if v has connect to an ancestor of u
			low[u]=min(low[u],low[v]);
			//if u is articulation point,pop all edge from stack till u--v
			if(disc[u]==1&&children>1||disc[u]>1&&disc[u]<=low[v])
			{
				while(st->back().u!=u||st->back().v!=v)
				{
					cout<<st->back().u<<"----"<<st->back().v<<"    ";
					st->pop_back();
				}
				cout<<st->back().u<<"----"<<st->back().v<<"    ";
				st->pop_back();
				cout<<endl;
				bccCount++;
			}
		}
		else if(v!=parent[u])
		{
			low[u]=min(low[u],disc[v]);//u-v is a back edge 
			if(disc[v]<disc[u])
				st->push_back(Edge(u,v));
		}
	}
}

void Graph::BCC()
{
	int *disc=new int[V];
	int *low=new int[V];
	int *parent=new int[V];
	list<Edge> *st=new list<Edge>[V];
	for(int v=0;v<V;v++)
	{
		disc[v]=NIL;
		low[v]=NIL;
		parent[V]=NIL;
	}
	for(int v=0;v<V;v++)
	{
		if(disc[v]==NIL)
			BCCUtil(v,disc,low,st,parent);
		int j=0;
		while(st->size()==0)
		{
			j=1;
			cout<<st->back().u<<"----"<<st->back().v<<"    ";
			st->pop_back();
		}
		if(j==1)
		{
			cout<<endl;
			bccCount++;
		}
	}
	
}


int main()
{
    Graph g(12); 
    g.addEdge(0, 1); 
    g.addEdge(1, 0); 
    g.addEdge(1, 2); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
    g.addEdge(3, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 2); 
    g.addEdge(2, 4); 
    g.addEdge(4, 2); 
    g.addEdge(3, 4); 
    g.addEdge(4, 3); 
    g.addEdge(1, 5); 
    g.addEdge(5, 1); 
    g.addEdge(0, 6); 
    g.addEdge(6, 0); 
    g.addEdge(5, 6); 
    g.addEdge(6, 5); 
    g.addEdge(5, 7); 
    g.addEdge(7, 5); 
    g.addEdge(5, 8); 
    g.addEdge(8, 5); 
    g.addEdge(7, 8); 
    g.addEdge(8, 7); 
    g.addEdge(8, 9); 
    g.addEdge(9, 8); 
    g.addEdge(10, 11); 
    g.addEdge(11, 10); 
    g.BCC(); 
    cout << "Above are " << bccCount << " biconnected components in graph\n"; 

    return 0;
}
