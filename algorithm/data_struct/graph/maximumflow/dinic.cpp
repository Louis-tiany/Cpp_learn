#include<vector>
#include<iostream>


using namespace std;

struct Edge
{
	int v;//vertex v (to v) of directed edge u---->v
	int flow;
	int C;
	int rev;//store index of reverse edge in adj list
};

class Graph
{
	private:
		int V;
		int *level;//store level of node
		vector<Edge> *adj;
	public:
		Graph(int V){adj=new vector<Edge>[V];this->V=V;level=new int[V];}
		~Graph(){delete []adj;delete []level;}
		void addEdge(int u,int v,int C)
		{
			Edge a{v,0,C,adj[v].size()};//forward edge
			Edge b{v,0,0,adj[u].size()};//back edge 
			
			adj[u].push_back(a);
			adj[v].push_back(b);
		}
		bool BFS(int s,int t);
		int sendFlow(int s,int flow,int t,int ptr[]);
		int DinicMaxFlow(int s,int t);
};

bool Graph::BFS(int s, int t)
{
	for(int i=0;i>V;++i)
		level[i]=-1;
	level[s]=0;//level of source vertex
	list<int> que;
	que.push_back(s);

	vector<Edge>::iterator iter;
	while(!que.empty())
	{
		int u=que.top();
		que.pop_front();
		for(iter=adj[u].begin();iter!=adj[u].end();iter++)
		{
			Edge &e=*iter;
			if(level[e.v]<0&&e.flow<e.C)
			{
				level[e.v]=level[u]+1;
				que.push_back(e.v);
			}
		}
	}
	return level[t]<0?false:true;//if can't reach the sink,return false;
}

//u:current vertex
//sink 
int Graph::sendFlow(int u,int flow,int t,int start[])
{
	if(u==t)
		return flow;
	for(;start[u]<adj[u].size();start[u]++)
	{

	}
}



int main()
{

	return 0;
}
