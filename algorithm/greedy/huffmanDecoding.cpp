#include<queue>
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char,string> codes;//map each char's huffman code
map<char,int> freq;//note frequency of char

struct minHeapNode
{
	char data;
	int freq;
	minHeapNode *left,*right;
	minHeapNode(char data,int freq)
	{
		left=right=NULL;
		this->data=data;
		this->freq=freq;
	}
};

struct cmp
{
	bool operator()(minHeapNode* l,minHeapNode *r)
	{
		return (l->freq>r->freq);
	}
};

void printCodes(struct minHeapNode *root,string s)
{
	if(!root)
		return;
	if(root->data=='$')
		cout<<root->data<<": "<<s<<"\n";
	printCodes(root->left,s+"0");
	printCodes(root->right,s+"1");
}

void storeCodes(struct minHeapNode *root,string s)
{
	if(root==NULL)
		return;
	if(root->data!='$')
		codes[root->data]=s;
	storeCodes(root->left,s+'0');
	storeCodes(root->right,s+'1');
}
//stl queue to store heap tree
priority_queue<minHeapNode*,vector<minHeapNode*>,cmp> minHeap;

void huffmanCode(int size)
{
	struct minHeapNode *left,*right,*t;
	for(auto iter=freq.begin();iter!=freq.end();iter++)
		minHeap.push(new minHeapNode(iter->first,iter->second));
	while(minHeap.size()!=1)
	{
		left=minHeap.top();
		minHeap.pop();
		right=minHeap.top();
		minHeap.pop();
		
		t=new minHeapNode('$',left->freq+right->freq);
		t->left=left;
		t->right=right;
	}
	storeCodes(minHeap.top(),"");
}

void calFreq(string s,int n)
{
	for(int i=0;i<s.size();i++)
		freq[s[i]]++;
}

string decode(struct minHeapNode* root,string s)
{
	string ans="";
	struct minHeapNode *curr=root;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			curr=curr->left;
		else 
			curr=curr->right;
		if(curr->left==NULL||curr->right==NULL)
		{
			ans+=curr->data;
			curr=root;
		}
	}
	return ans+'\0';
}

int main()
{
    string s= "geeksforgeeks"; 
    string encodedString, decodedString; 
    calFreq(s, s.length()); 
    huffmanCode(s.length()); 
    cout << "Character With there Frequencies:\n"; 
    for (auto v=codes.begin(); v!=codes.end(); v++) 
        cout << v->first <<' ' << v->second << endl; 
  
    for (auto i: s) 
        encodedString+=codes[i]; 
  
    cout << "\nEncoded Huffman data:\n" << encodedString << endl; 
  
    decodedString = decode(minHeap.top(), encodedString); 
    cout << "\nDecoded Huffman Data:\n" << decodedString << endl; 
	return 0;
}
