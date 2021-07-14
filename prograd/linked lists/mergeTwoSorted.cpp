#include <bits/stdc++.h>
using namespace std;

int ans;

struct Node
{
	int data;
	Node *next;
};

void append(Node **head, int val)
{
	Node *newnode = new Node;
	newnode->data = val;
	newnode->next = NULL;

	if (*head == NULL)
		*head = newnode;
	else
	{
		Node *temp = *head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void deleteDuplicates(Node *head)
{
	Node *ptr1 = head;
	while (ptr1 && ptr1->next)
	{
		Node *ptr2 = ptr1;
		while (ptr2 && ptr2->next)
		{
			if (ptr1->data == ptr2->next->data)
			{
				Node *temp = ptr2->next;
				ptr2->next = temp->next;
				free(temp);
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

Node *mergeLinkedList(Node **head1, Node **head2)
{
	Node *head = NULL;
	Node *dummyNode = new Node;
	Node *cur = dummyNode;
	Node *ptr1 = *head1, *ptr2 = *head2;
	while (ptr1 && ptr2)
	{
		if (ptr1->data <= ptr2->data)
		{
			Node *temp = ptr1;	//saving the node
			ptr1 = ptr1->next;	//moving the pointer
			temp->next = NULL;	//breaking the connection
			cur->next = temp;	//adding node to final list
		}
		else
		{
			Node *temp = ptr2;
			ptr2 = ptr2->next;
			temp->next = NULL;
			cur->next = temp;
		}
		cur = cur->next;
	}

	if (ptr1)
	{
		cur->next = ptr1;
	}

	if (ptr2)
	{
		cur->next = ptr2;
	}

	head = dummyNode->next;
	free(dummyNode);
	return head;

}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL";
}

int main()
{
	Node *head1 = NULL, *head2 = NULL;
	int x, y, temp;
	cin >> x;
	while (x--)
	{
		cin >> temp;
		append(&head1, temp);
	}
	cin >> y;
	while (y--)
	{
		cin >> temp;
		append(&head2, temp);
	}

	Node *head = mergeLinkedList(&head1, &head2);

	printList(head);
}
