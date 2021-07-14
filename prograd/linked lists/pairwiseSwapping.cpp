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

void swapNodesPairwise(Node **head)
{
	Node *prev = NULL;
	if (*head == NULL)
		return;
	Node *cur1 = *head, *cur2 = cur1->next;

	while (cur1 && cur2)
	{
		if (prev)
			prev->next = cur2;
		cur1->next = cur2->next;
		cur2->next = cur1;

		if (cur1 == *head)
			*head = cur2;

		if (cur1->next)
		{
			cur2 = cur1->next;
			cur1 = cur1->next->next;
		}
		else
			break;

	}
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

	swapNodesPairwise(&head);

	printList(head);
}
