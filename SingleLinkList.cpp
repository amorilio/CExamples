// SingleLinkList.cpp: implementation of the SingleLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "SingleLinkList.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int count = 0;

SingleLinkList::SingleLinkList()
{
	head = NULL;
	add (&head, 10);
	add (&head, 20);
	add (&head, 30);
	add (&head, 40);
	add (&head, 50);
	add (&head, 60);
	print(head);
	printReverse(head);

	
	cout<<"-------cyclic Test-------->" <<endl;
	checkIfListCyclic();
	makeListCyclic();
	checkIfListCyclic();
	Node* next = head->next;
	head->next = NULL;
	destroyTheList(&next);

	
	cout<<"-------Sorted Insert Test-------->" <<endl;
	head = CreateRandomList(10);
	print(head);
	insertSorted(&head, 5);	
	insertSorted(&head, 35);		
	insertSorted(&head, 35);		
	insertSorted(&head, 35);	
	insertSorted(&head, 65);
	insertSorted(&head, 65);
	print(head);
	
	cout<<"-------Remove Duplicates Test-------->" <<endl;
	removeDuplicates();
	print(head);
	
	findNTHElementFromTheEnd(3);
	findNTHElementFromTheEnd(30);

	Node *newList = NULL;
	copyTheList(&newList, head);
	print(newList);
	
	compareLists(newList, head);
	insertSorted(&newList,41);	
	compareLists(newList, head);
	
	cout<<"-------Middle Test-------->" <<endl;
	destroyTheList(&newList);
	newList = CreateRandomList(10);
	print(newList);	
	Node * middle = findMiddleNode(newList);
	if(!middle)
		cout << "Empty List supplied to findMiddleNode" << endl;
	else
		cout << "Middle Value is :" << middle->data<<endl;
	destroyTheList(&newList);	
	
	
	cout<<"-------Reverse Test-------->" <<endl;
	Node* RandomeList = CreateRandomList(10);
	print(RandomeList);
	reverseListIterative(&RandomeList);
	print(RandomeList);	
	reverseListRecursive(RandomeList);
	print(RandomeList);	


	cout<<"-------bubbleSort Test-------->" <<endl;
	newList = CreateRandomList(10);	
	/*
	cout<<"-------Swap Test-------->" <<endl;
	print(newList);		
	swap(&newList->next, &newList->next->next);
	print(newList);	
	swap(&newList->next->next, &newList->next->next->next);
	swap(newList->next, newList->next->next);
	print(newList);	
	swap(newList->next->next, newList->next->next->next);
	print(newList);	
	*/
	cout<<"<Before>" <<endl;
	print(newList);
	bubbleSort(&newList);
	//bubbleSort2(&newList);
	cout<<"<After>" <<endl;
	print(newList);
	destroyTheList(&newList);		
	
	cout<<"-------mergeSort Test-------->" <<endl;
	newList = CreateRandomList(10);
	cout<<"<Before>" <<endl;
	print(newList);
	mergeSort(&newList);
	cout<<"<After>" <<endl;
	print(newList);
	destroyTheList(&newList);		
}

SingleLinkList::~SingleLinkList()
{
	
}



SingleLinkList::Node* SingleLinkList::CreateRandomList(int iSize)
{
	Node* head = NULL;
	Node* last = NULL;
	while(iSize-- > 0)
	{
		Node* node = new Node();
		node->data = rand() % 100;
		node->next = NULL;
		if ( last == NULL )
			head = node;
		else
			last->next = node;
		last = node;
		
		
		cout << node->data << " , ";
	}
	cout << "\n";
	return &(*head);
}

void SingleLinkList::add (Node **node, int data)
{
	
	if(!(*node))
	{
		(*node) = new Node();
		(*node)->data = data;
		(*node)->next = NULL;
		return;
	}

	Node* current = (*node);
	while (current->next)
		current = current->next;
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	current->next = newNode;

}


void SingleLinkList::destroyTheList(Node **node)
{
	Node* current	= *node;
	while(current)
	{
		Node* next = current->next;
		delete current;
		current = NULL;
		current = next;
	}
	*node = NULL;
}

void SingleLinkList::print(Node* node)
{	
	int i = 0;
	Node* current = node;
	cout<<"Printing the List:"<<endl;
	while (current!=NULL)
	{
		cout<<current->data << " ";
		current = current->next;
	}
	cout<< endl;
}


void SingleLinkList::copyTheList(Node **trg, Node* src)
{
	if ( (*trg) == NULL)
		(*trg) = new Node();
	(*trg)->data = src->data;
	(*trg)->next = NULL;
	if (src->next)
		copyTheList(&(*trg)->next, src->next);
}


void SingleLinkList::compareLists(Node* list1, Node* list2)
{
	
	if ( !list1 && !list2 )
	{
		cout <<"Same lists" << endl;
		return;
	}

	if ( (!list1 && list2) || (list1 && !list2) || (list1->data != list2->data) )
	{
		cout <<"Different lists" << endl;
		return;
	}	
	
	compareLists(list1->next, list2->next);
}


SingleLinkList::Node* SingleLinkList::findMiddleNode(Node* node)
{
	if (!node)
	{
		return NULL;
	}
	if (!node->next)
	{
		return node;
	}

	Node* p1 = node;
	Node* p2 = node->next;
	while (p2)
	{		
		p2 = p2->next;
		if(p2)
		{
			p2 = p2->next;
			p1 = p1->next;
		}
	}
	return p1;
}

void SingleLinkList::insertSorted(Node **node, int num)
{
	
	Node *newNode = new Node();
	newNode->data = num;
	newNode->next = NULL;

	Node *current = (*node);

	if (newNode->data < current->data) 
	{
		newNode->next = current;
		(*node) = newNode;
		return;
	}

	while(current->next)
	{
		if (newNode->data < current->next->data)
		{
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		if(current->next)
			current = current->next;
	}

	current->next = newNode;
}


void SingleLinkList::removeDuplicates()
{
	Node *current = head;

	while (current && current->next)
	{
		if (current->data == current->next->data)
		{
			Node* tmp = current->next;
			current->next = current->next->next;
			delete tmp;
		} else 
			current = current->next;
	}
}

void SingleLinkList::findNTHElementFromTheEnd(int nthElement)
{
	int counter=0;
	Node *p1 = head;
	Node *p2 = head;

	while (p1->next)	
	{
		if (++counter >= nthElement)
			p2 = p2->next;
		p1 = p1->next;
	}
	if (p2 == head)
		cout<<"There is less then "<<nthElement<<" Elements in list"<<endl;
	else
		cout<<nthElement<<" Element from the end is :"<<p2->data<<endl;

}

void SingleLinkList::printReverse(Node * node)
{	
	static i = 0;
	if (i == 0)		
	{
		i++;
		cout<<"Printing the List in Reverse Order:"<<endl;
	}
	if (node->next)
	{
		i++;
		printReverse(node->next);
	}
	
	cout<<"Element "<<i-- <<" : "<< node->data << endl;
}

void SingleLinkList::makeListCyclic()
{	
	Node *current = head;
	if (!current)
		head->next = head;
	while (current->next)
		current = current->next;
	current->next = head;
	cout<<"Made List Cyclic" << endl;
}

void SingleLinkList::checkIfListCyclic()
{	

	if(!head) 
		cout<<"Empty List"<<endl;
	if(!head->next || !head->next->next)
		cout<<"Not cyclic List"<<endl;
	
	Node *first		= head->next;	
	Node *second	= head->next->next;

	while (first != second)
	{
		if	(!first->next || !second->next ||  !second->next->next) 
		{
			cout<<"Not cyclic List"<<endl;
			return;
		}
		first		= first->next;	
		second	= second->next->next;
	}
	cout<<"Is cyclic List"<<endl;
	return;
}

void SingleLinkList::reverseListIterative(Node **node)
{
	
	cout<<"Reversing (Iterative) the list"<<endl;
	if (!(*node))
		return;

	Node* curr = (*node);
	Node* next = (*node)->next;

	(*node)->next = NULL;

	while (next)
	{
		Node* temp = next->next;
		next->next = curr;
		curr = next;
		next = temp;
	}

	(*node) = curr;
}

void SingleLinkList::reverseListRecursive(Node *root)
{

	if (root->next)
	{
		reverseListRecursive(root->next);
		root->next->next = root;
		root->next = NULL;
	}
	else
	{
		head = root; 
	}
}

void SingleLinkList::swap(Node* p1,Node* p2)
{
    Node * tmp = p2->next;	
	p1->next = tmp;
	p2->next = p1;
}


void SingleLinkList::bubbleSort2(Node **head)
{
	int i, j;
	Node *p0, *p1, *p2, *p3;
	
	for(i = 1; i < count; i++)
	{
		p0 = NULL;
		p1 = (*head);
		p2 = (*head)->next;
		p3 = p2->next;
		
		for(j = 1; j <= (count - i); j++)
		{
			if(p1->data > p2->data)  
			{
				// Adjust the pointers... 
				swap(p1,p2);

				if(p0)
					p0->next=p2;
				
				// Set the head pointer if it was changed...
				if((*head) == p1)
					(*head)=p2;
				
				// Progress the pointers
				p0 = p2;
				p2 = p1->next;
				p3 = ((p3!=NULL) && (p3->next!=NULL))?p3->next:NULL;
			}
			else
			{
				// Nothing to swap, just progress the pointers...
				p0 = p1;
				p1 = p2;
				p2 = p3;
				p3 = ((p3!=NULL) && (p3->next!=NULL))?p3->next:NULL;
			}
		}
	}
}


void SingleLinkList::bubbleSort(Node **node)
{
	bool bIsSorted = true;

	do 
	{
		Node * p0 = NULL;
		Node * p1 = (*node);
		Node * p2 = p1->next;
		Node * p3 = p2->next;

		while (p3)
		{
			bIsSorted = true;
			if(p1->data > p2->data)
			{
				bIsSorted = false;
				swap(p1,p2);
				if(p0)
					p0->next = p2;
				if((*node) == p1)
					(*node) = p2;

				
				p0 = p2;
				p2 = p1->next;
				if (p3)
					p3 = p3->next;
			} else 
			{
				p0 = p1;
				p1 = p2;
				p2 = p3;
				if (p3)
					p3 = p3->next;
			}

		}
		
	} while (!bIsSorted);
}




void SingleLinkList::mergeSort(Node **node)
{
		if (!(*node) || !(*node)->next)
			return;
		
		Node * head1 = (*node);
		Node * middle = findMiddleNode(*node);
		Node * head2 = middle->next;
		middle->next = NULL;

		mergeSort(&head1);
		mergeSort(&head2);
		*node = merge(head1, head2);
}

SingleLinkList::Node * SingleLinkList::merge(Node *a, Node *b)
{
	Node * result = NULL;
		
	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b==NULL)
		return(a);
		
	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return(result);
}