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

void swapNodes(Node **head, int p, int q)
{
	Node *prev1 = NULL, *cur1 = *head;
	Node *prev2 = NULL, *cur2 = *head;
	while (cur1)
	{
		if (cur1->data == p)
			break;
		prev1 = cur1;
		cur1 = cur1->next;
	}

	while (cur2)
	{
		if (cur2->data == q)
			break;
		prev2 = cur2;
		cur2 = cur2->next;
	}

	if (prev1)
		prev1->next = cur2;
	if (prev2)
		prev2->next = cur1;
	Node *temp = cur2->next;
	cur2->next = cur1->next;
	cur1->next = temp;

	if (cur1 == *head)
		*head = cur2;
	else if (cur2 == *head)
		*head = cur1;
}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	Node *head = NULL;
	int x, temp, p, q;
	cin >> x;
	while (x--)
	{
		cin >> temp;
		append(&head, temp);
	}

	cin >> p >> q;

	swapNodes(&head, p, q);

	printList(head);
}
