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

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "\n";
		temp = temp->next;
	}
}

int main()
{
	Node *head = NULL;
	int x;
	while (cin >> x)
	{
		if (x < 0)
			break;
		append(&head, x);
	}
	cout << "Linked list before removal of duplicates\n";
	printList(head);
	cout << "Linked list after removal of duplicates\n";
	deleteDuplicates(head);
	printList(head);
}
