#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//a struct to represent adjacency list node
struct adjListNode
{
	int dest;
	int weight;
	struct adjListNode* anext;
};
//a struct to represent adjacency list
struct adjList
{
	struct adjListNode* head;
};

struct Graph
{
	int V;
	struct adjList* myarray;//size of array will be the number of vertex in graph
};
//a utility function to create a new adjacency list node 
struct adjListNode* newListNode(int weight,int dest)
{
	struct adjListNode* newNode=(struct adjListNode*)malloc(sizeof(struct adjListNode));
	newNode->weight=weight;
	newNode->dest=dest;
	newNode->anext=NULL;
	return newNode;
}
//a utility function to create a new graph represented by adjacency list
struct Graph* createGraph(int V)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;
	graph->myarray=(struct adjList*)malloc(V*sizeof(struct adjList));
	for(int i=0;i<V;++i)
		graph->myarray[i].head=NULL;
	return graph;
}

void addEdge(struct Graph* graph,int src,int dest,int weight)
{
	struct adjListNode *newNode=newListNode(weight,dest);
	newNode->anext=graph->myarray[src].head;//head is at the begining of list's node
	graph->myarray[src].head=newNode;//the node is added at the begining
	
	//add an edge from dest to src 
	newNode=newListNode(src,weight);
	newNode->anext=graph->myarray[dest].head;
	graph->myarray[dest].head=newNode;
}

struct minHeapNode
{
	int v,key;
};
struct minHeap
{
	int capa;
	int size;
	int *pos;
	struct minHeapNode** harray;
};

struct minHeapNode* newHeapNode(int v,int key)
{
	struct minHeapNode* newNode=(minHeapNode*)malloc(sizeof(struct minHeapNode));
	newNode->v=v;
	newNode->key=key;
	return newNode;
}

struct minHeap* createMinHeap(int capa)
{
	struct minHeap* heap=(struct minHeap*)malloc(sizeof(struct minHeap));
	heap->pos=(int *)malloc(capa*sizeof(int));
	heap->size=0;
	heap->capa=capa;
	heap->harray=(struct minHeapNode**)malloc(capa*sizeof(struct minHeapNode*));
	return heap;
}

void swapHeapNode(struct minHeapNode** a,struct minHeapNode** b)
{
	struct minHeapNode* t= *a;
	*a=*b;
	*b=t;
}
//a function to heapify at given idx
//the function also updates pos of nodes
void minHeapify(struct minHeap* heap,int idx)
{
	int smallest,left,right;
	smallest=idx;
	left=2*idx+1;
	right=2*idx+2;
	if(left<heap->size&&heap->harray[left]->key<heap->harray[smallest]->key)
		smallest=left;
	if(right<heap->size&&heap->harray[right]->key<heap->harray[smallest]->key)
		smallest=right;
	if(smallest!=idx)
	{
		minHeapNode* smallestNode=heap->harray[smallest];
		minHeapNode* idxNode=heap->harray[idx];
		//swap position
		heap->pos[smallestNode->v]=idx;
		heap->pos[idxNode->v]=smallest;
		swapHeapNode(&heap->harray[smallest],&heap->harray[idx]);

		minHeapify(heap,smallest);
	}

}

int isEmpty(struct minHeap* heap)
{
	return heap->size==0;
}

struct minHeapNode *extractMin(struct minHeap* heap)
{
	if(heap->size==0)
		return NULL;
	struct minHeapNode *root=heap->harray[0];
	struct minHeapNode *lastNode=heap->harray[heap->size-1];
	heap->harray[0]=lastNode;

	heap->pos[root->v]=heap->size-1;
	heap->pos[lastNode->v]=0;
	--heap->size;
	minHeapify(heap,0);
	return root;
}

void decreaseKey(struct minHeap* heap,int v,int key)
{
	int i=heap->pos[v];
	heap->harray[i]->key=key;
	while(i&&heap->harray[i]->key<heap->harray[(i-1)/2]->key)
	{
		heap->pos[heap->harray[i]->v]=(i-1)/2;
		heap->pos[heap->harray[(i-1)/2]->v]=i;
		swapHeapNode(&heap->harray[i],&heap->harray[(i-1)/2]);
		i=(i-1)/2;
	}
}
//a function to detect if the vertex in min heap or not 
bool isInHeap(struct minHeap* heap,int v)
{
	if(heap->pos[v]<heap->size)
		return true;
	return false;
}

void printArr(int arr[],int n)
{
	for(int i=1;i<n;++i)
		printf("%d - %d \n ",arr[i],i);
}

void primTree(struct Graph* graph)
{
	int V=graph->V;
	int parent[V];//store vertexs in MST
	int key[V];//array to store weights
	struct minHeap* heap=createMinHeap(V);
	for(int v=1;v<V;v++)
	{
		parent[v]=-1;
		key[v]=INT_MAX;
		heap->harray[v]=newHeapNode(v,key[v]);//construct min heap
		heap->pos[v]=v;
	}
	key[0]=0;
	heap->harray[0]=newHeapNode(0,key[0]);
	heap->pos[0]=0;

	heap->size=V;

	while(!isEmpty(heap))	
	{
		struct minHeapNode* heapNode=extractMin(heap);
		int u=heapNode->v;
		struct adjListNode* pCrawl=graph->myarray[u].head;
		//traverse all the vertices of adjacency list u
		while(pCrawl!=NULL)
		{
			int v=pCrawl->dest;

			if(isInHeap(heap,v)&&pCrawl->weight<key[v])
			{
				key[v]=pCrawl->weight;
				parent[v]=u;
				decreaseKey(heap,v,key[v]);
			}
			pCrawl=pCrawl->anext;
		}
	}
	printArr(parent,V);
}

int main()
{

    int V = 9; 
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7); 
  
    primTree(graph); 
	return 0;
}
