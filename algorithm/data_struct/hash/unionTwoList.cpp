#include<unordered_map>
#include<stdio.h>
#include<iostream>

using namespace std;

struct node
{
	int data;
	struct node *nextNode;
};

void pushNode(struct node** head,int newData)
{
	struct node *newNode=new struct node;
	newNode->data=newData;
	newNode->nextNode=(*head);
	(*head)=newNode;
}

//to store elements of both list
void storeEle(struct node *head1,struct node *head2,unordered_map<int,int> &eleOcc)
{
	struct node *ptr1=head1;
	struct node *ptr2=head2;
	while(ptr1!=NULL||ptr2!=NULL)
	{
		if(ptr1!=NULL)
		{
			eleOcc[ptr1->data]++;
			ptr1=ptr1->nextNode;
		}
		if(ptr2!=NULL)
		{
			eleOcc[ptr2->data]++;
			ptr2=ptr2->nextNode;
		}
	}
}

struct node* getUnion(unordered_map<int,int> eleOcc)
{
	//打印两个链表合并后的值
	struct node *result=NULL;
	for(auto iter=eleOcc.begin();iter!=eleOcc.end();iter++)
		pushNode(&result,iter->first);
	return result;
}

struct node* getIntersection(unordered_map<int,int> eleOcc)
{
	//打印两个链表中重合的值
	struct node* result=NULL;
	for(auto iter=eleOcc.begin();iter!=eleOcc.end();iter++)
		if(iter->second>1)
			pushNode(&result,iter->first);
	return result;
}

void printList(struct node* node)
{
	while(node!=NULL)
	{
		cout<<node->data<<"    ";
		node=node->nextNode;
	}
}

void printUnionIntersection(struct node *head1,struct node *head2)
{
	unordered_map<int,int> eleOcc;
	storeEle(head1,head2,eleOcc);

	node *intersectionList=getIntersection(eleOcc);
	node *unionList=getUnion(eleOcc);

	printf("\nIntersection list is \n");
    	printList(intersectionList);

	printf("\nUnion list is \n");
	printList(unionList); 
}

int main()
{
	struct node* head1 = NULL;
    struct node* head2 = NULL;

    /* create a linked list 11->10->15->4->20 */
    pushNode(&head1, 1);
    pushNode(&head1, 2);
    pushNode(&head1, 3);
    pushNode(&head1, 4);
    pushNode(&head1, 5);

    /* create a linked list 8->4->2->10 */
    pushNode(&head2, 1);
    pushNode(&head2, 3);
    pushNode(&head2, 5);
    pushNode(&head2, 6);

    printf("First list is \n");
    printList(head1);

    printf("\nSecond list is \n");
    printList(head2);

    printUnionIntersection(head1, head2);

    cout<<endl;
	
    return 0;
}
