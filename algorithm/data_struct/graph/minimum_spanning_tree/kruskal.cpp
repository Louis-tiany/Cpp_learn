#include<algorithm>
#include<iostream>


using namespace std;

class Edge
{
	public:
		int src,dest,weights;
};

class Graph
{
	public:
		int E,V;
		Edge *edge;
};

Graph* creatgraph(int V,int E)
{
	Graph *graph=new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;
}
class subset
{
	public:
		int parent;
		int ranks;
};

int find(subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

void myunion(subset subsets[],int x,int y)
{
	int xroot=find(subsets,x);
	int yroot=find(subsets,y);
	if(subsets[xroot].ranks<subsets[yroot].ranks)
		subsets[xroot].parent=yroot;
	else if(subsets[xroot].ranks>subsets[yroot].ranks)
		subsets[yroot].parent=xroot;
	else
	{
		subsets[yroot].parent=xroot;
		subsets[xroot].ranks++;
	}
}

int mycmp(const void* a,const void* b)
{
	Edge* a1=(Edge*)a;
	Edge* b1=(Edge*)b;
	return a1->weights>b1->weights;
}

void kruskalMst(Graph *graph)
{
	int V=graph->V;
	Edge result[V];
	int e,i=0;
	qsort(graph->edge,graph->E,sizeof(graph->edge[0]),mycmp);
	subset *subsets=new subset[(V*sizeof(subset))];
	for(int v=0;v<V;++v)
	{
		subsets[v].parent=v;
		subsets[v].ranks=0;
	}
	while(e<V-1&&i<graph->E)
	{
		Edge next_edge=graph->edge[i++];
		int x=find(subsets,next_edge.src);
		int y=find(subsets,next_edge.dest);

		if(x!=y)
		{
			result[e++]=next_edge;
			myunion(subsets,x,y);
		}
	}
	cout<<"Follow are the edges in Mst:\n";
	for(i=0;i<e;++i)
		cout<<result[i].src<<"--->"<<result[i].dest<<"  ==  "<<result[i].weights<<"\n";
	return;
}

int main()
{

    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph* graph = creatgraph(V, E);  
  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weights = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weights = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weights = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weights = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weights = 4;  
  
    kruskalMst(graph);  


	return 0;
}
