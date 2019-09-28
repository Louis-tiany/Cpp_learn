#include<list>
#include<stack>
#include<iostream>

#define NIL -1

using namespace std;

class Graph
{
	private:
		int V;
		list<int> *adj;
		void tarjanSccUtil(int u,int disc[],int low[],stack<int> *st,bool stackMember[]);
	public:
		Graph(int V){this->V=V;this->adj=new list<int>[V];}
		~Graph(){delete []adj;}
		void tarjanSCC();
		void addEdge(int u,int v){adj[u].push_back(v);}
};

//a recursive function 
//u is a vertex to be visit next
//disc[] store discover time of visited vertex
//low[] earthe vertex that can be reached from subtree rooted with current vertex
//st store all connected component,stackmember check whether a node is in stack
void Graph::tarjanSccUtil(int u,int disc[],int low[],stack<int> *st,bool stackMember[])
{
	static int visitTime=0;
	disc[u]=low[u]=++visitTime;
	st->push(u);
	list<int>::iterator iter;
	for(iter=adj[u].begin();iter!=adj[u].end();iter++)
	{
		int v=*iter;
		//if v hasn't visited,recur for it
		if(disc[v]==-1)
		{
			tarjanSccUtil(v,disc,low,st,stackMember);
			//check if v have a connection to u' ancestor 
			low[u]=min(low[u],low[v]);
		}
		//v have been visited and v is still in stack 
		else if(stackMember[v]==true)
			low[u]=min(low[u],disc[v]);
	}
	int w=0;
	//if low[u]=disc[u],u and u's subtree is a SCC component
	if(low[u]=disc[u])
	{
		while(st->top()!=u)
		{
			w=(int)st->top();
			cout<<w<<"   ";
			stackMember[w]=false;
			st->pop();
		}
		w=(int)st->top();
		cout<<w<<"   ";
		stackMember[w]=false;
		st->pop();
	}
}

void Graph::tarjanSCC()
{
	int *disc=new int[V];
	int *low=new int[V];
	bool *stackMember=new bool[V];
	stack<int> *st=new stack<int>();
	for(int i=0;i<V;i++)
	{
		disc[i]=NIL;
		low[i]=NIL;
		stackMember[i]=false;
	}
	for(int i=0;i<V;i++)
		if(disc[i]==-1)
			tarjanSccUtil(i,disc,low,st,stackMember);
}


int main()
{
    cout << "\nSCCs in first graph \n"; 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.tarjanSCC(); 
  
    cout << "\nSCCs in second graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.tarjanSCC(); 
  
    cout << "\nSCCs in third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.tarjanSCC(); 
  
    cout << "\nSCCs in fourth graph \n"; 
    Graph g4(11); 
    g4.addEdge(0,1);g4.addEdge(0,3); 
    g4.addEdge(1,2);g4.addEdge(1,4); 
    g4.addEdge(2,0);g4.addEdge(2,6); 
    g4.addEdge(3,2); 
    g4.addEdge(4,5);g4.addEdge(4,6); 
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9); 
    g4.addEdge(6,4); 
    g4.addEdge(7,9); 
    g4.addEdge(8,9); 
    g4.addEdge(9,8); 
    g4.tarjanSCC(); 
  
    cout << "\nSCCs in fifth graph \n"; 
    Graph g5(5); 
    g5.addEdge(0,1); 
    g5.addEdge(1,2); 
    g5.addEdge(2,3); 
    g5.addEdge(2,4); 
    g5.addEdge(3,0); 
    g5.addEdge(4,2); 
    g5.tarjanSCC(); 
	cout<<endl;
	return 0;
}
