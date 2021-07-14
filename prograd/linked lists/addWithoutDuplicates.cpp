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
			if (temp->data == val)
			{
				free(newnode);
				return;
			}
			temp = temp->next;
		}

		if (temp->data == val)
		{
			free(newnode);
			return;
		}
		temp->next = newnode;
	}
}

void printList(Node *head)
{
	Node *temp = head;
	if (head == NULL)
		cout << "List is empty";
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

	printList(head);
}
