#include<vector>
#include<string>
#include<queue>
#include<iostream>




using namespace std;

struct minHeapNode
{
	char data;
	unsigned freq;
	struct minHeapNode *left,*right;
	minHeapNode(char data,unsigned freq)
	{
		left=right=NULL;
		this->data=data;
		this->freq=freq;
	}
};

struct comp
{
	bool operator()(minHeapNode *l,minHeapNode *r)
	{
		return (l->freq>r->freq);
	}
};

void printCodes(struct minHeapNode *root,string s)
{	
	if(!root)
		return;
	if(root->data!='$')
		cout<<root->data<<": "<<s<<"\n";
	printCodes(root->left,s+"0");
	printCodes(root->right,s+"1");
}


void huffmanCode(char data[],int freq[],int size)
{
	struct minHeapNode *left,*right,*t;
	priority_queue<minHeapNode*,vector<minHeapNode*>,comp> minHeap;
	for(int i=0;i<size;i++)
		minHeap.push(new minHeapNode(data[i],freq[i]));

	while(minHeap.size()!=1)
	{
		left=minHeap.top();
		minHeap.pop();
		right=minHeap.top();
		minHeap.pop();

		t=new minHeapNode('$',left->freq+right->freq);
		t->left=left;
		t->right=right;
		
		minHeap.push(t);
	}
	printCodes(minHeap.top(),"");
}

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    huffmanCode(arr, freq, size); 
    return 0;
}
