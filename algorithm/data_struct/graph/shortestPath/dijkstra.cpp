#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

struct adjListNode
{
	int dest;
	int weight;
	struct adjListNode* adjnext;
};

struct adjList
{
	struct adjListNode* head;
};

struct Graph{
	int V;
	adjList* garray;
};

struct adjListNode* newListNode(int dest,int weight)
{
	struct adjListNode* newNode=(struct adjListNode*)malloc(sizeof(struct adjListNode));
	newNode->dest=dest;
	newNode->weight=weight;
	newNode->adjnext=NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;

	graph->garray=(struct adjList*)malloc(V*sizeof(struct adjList));
	for(int i=0;i<V;++i)
	{
		graph->garray[i].head=NULL;
	}
	return graph;
}
//add edge to an undirect graph
void addEdge(struct Graph* graph,int src,int dest,int weigh)
{
	struct adjListNode* newNode=newListNode(dest,weigh);
	newNode->adjnext=graph->garray[src].head;
	graph->garray[src].head=newNode;

	newNode=newListNode(src,weigh);
	newNode->adjnext=graph->garray[dest].head;
	graph->garray[dest].head=newNode;
}

struct minHeapNode
{
	int v;
	int dist;
};

struct minHeap
{
	int size;
	int cap;
	int *pos;
	struct minHeapNode** harray;
};

struct minHeapNode* newHeapNode(int v,int dist)
{
	struct minHeapNode* heapNode=(struct minHeapNode*)malloc(sizeof(minHeapNode));
	heapNode->v=v;
	heapNode->dist=dist;
	return heapNode;
}

struct minHeap* createMinHeap(int cap)
{
	struct minHeap* heap=(struct minHeap*)malloc(sizeof(struct minHeap));
	heap->pos=(int *)malloc(cap*sizeof(int));
	heap->size=0;
	heap->cap=cap;
	heap->harray=(struct minHeapNode**)malloc(cap*sizeof(struct minHeapNode*));
	return heap;
}

void swapHeapNode(struct minHeapNode **a,struct minHeapNode **b)
{
	struct minHeapNode *t=*a;
	*a=*b;
	*b=t;
}

void minHeapify(struct minHeap* heap,int idx)
{
	int smallest,left,right;
	smallest = idx;
	left=2*idx+1;
	right=2*idx+2;
	if(left<heap->size&&heap->harray[left]->dist<heap->harray[smallest]->dist)
		smallest=left;
	if(right<heap->size&&heap->harray[right]->dist<heap->harray[smallest]->dist)
		smallest=right;
	if(smallest!=idx)
	{
		struct minHeapNode *smallestNode=heap->harray[smallest];
		struct minHeapNode *idxNode=heap->harray[idx];

		//swap pos
		heap->pos[smallestNode->v]=idx;
		heap->pos[idxNode->v]=smallest;
		//swap nodes
		swapHeapNode(&heap->harray[smallest],&heap->harray[idx]);
		minHeapify(heap,smallest);
	}
}

int isEmpty(struct minHeap* heap)
{
	return heap->size==0;
}

struct minHeapNode* extractMin(struct minHeap* heap)
{
	if(isEmpty(heap))
		return NULL;
	struct minHeapNode* root=heap->harray[0];
	struct minHeapNode* lastNode=heap->harray[heap->size-1];
	heap->harray[0]=lastNode;

	heap->pos[root->v]=heap->size-1;
	heap->pos[lastNode->v]=0;
	//update the position of last node
	//reduce heap size and heapify the new root
	--heap->size;
	minHeapify(heap,0);
	return root;
}

void decreasekey(struct minHeap* heap,int v,int dist)
{
	int i=heap->pos[v];
	heap->harray[v]->dist=dist;
	while(i&&heap->harray[i]->dist<heap->harray[(i-1)/2]->dist)
	{
		//swap parent node and child node when child's dist < parent's dist
		heap->pos[heap->harray[i]->v]=(i-1)/2;
		heap->pos[heap->harray[(i-1)/2]->v]=i;
		swapHeapNode(&heap->harray[i],&heap->harray[(i-1)/2]);
		i=(i-1)/2;
	}
}

bool isInHeap(struct minHeap *heap,int v)
{
	if(heap->pos[v]<heap->size)
		return true;
	return false;
}

void printArr(int dist[],int n)
{
	printf("vertex distance from source \n");
	for(int i=0;i<n;++i)
		printf("%d \t\t %d \n ",i,dist[i]);
}

void dijkstra(struct Graph* graph,int src)
{
	int V=graph->V;
	int dist[V];
	struct minHeap* heap=createMinHeap(V);
	for(int v=0;v<V;++v)
	{
		dist[v]=INT_MAX;
		heap->harray[v]=newHeapNode(v,dist[v]);
		heap->pos[v]=v;
	}

	heap->harray[src]=newHeapNode(src,dist[src]);
	heap->pos[src]=src;
	dist[src]=0;
	decreasekey(heap,src,dist[src]);
	heap->size=V;
	while(!isEmpty(heap))
	{
		struct minHeapNode* heapNode=extractMin(heap);
		int u=heapNode->v;
		struct adjListNode* pCrawl=graph->garray[u].head;
		while(pCrawl!=NULL)
		{
			int v=pCrawl->dest;
			if(isInHeap(heap,v)&&dist[u]!=INT_MAX&&pCrawl->weight+dist[u]<dist[v])
			{
				dist[v]=pCrawl->weight+dist[u];
				decreasekey(heap,v,dist[v]);
			}
			pCrawl=pCrawl->adjnext;
		}
	}
	printArr(dist,V);
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
  
    dijkstra(graph, 0); 

}
