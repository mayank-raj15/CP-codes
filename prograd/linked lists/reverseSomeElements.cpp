#include <bits/stdc++.h>
using namespace std;

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

void reverseElements(Node **head, int x)
{
	Node *prev = *head, *oldHead = *head;
	if (prev == NULL || prev->next == NULL)
		return;
	Node *cur = prev->next , *temp = cur;
	x--;
	prev->next == NULL;
	while (cur && x > 0)
	{
		temp = temp->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
		x--;
	}

	if (cur == NULL || (cur->next) == NULL)
	{
		(*head)->next = cur;
		*head = prev;
		return;
	}

	Node *prev2 = cur;
	cur = prev2->next, temp = cur;
	prev2->next = NULL;

	while (cur)
	{
		temp = temp->next;
		cur->next = prev2;
		prev2 = cur;
		cur = temp;
	}

	(*head)->next = prev2;
	*head = prev;
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
	int temp;
	while (1)
	{
		cin >> temp;
		if (temp < 0)
			break;
		append(&head, temp);
	}

	int x;
	cin >> x;

	reverseElements(&head, x);

	printList(head);
}
