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
		else
			prev = cur2;
		cur1->next = cur2->next;
		cur2->next = cur1;

		if (cur1 == *head)
			*head = cur2;

		prev = cur1;

		if (cur1->next)
		{
			cur1 = cur1->next;
			cur2 = cur1->next;
		}
		else
			break;

	}
}

void printList(Node *head)
{
	if (head == NULL)
	{
		cout << "List is empty";
		return;
	}
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

	swapNodesPairwise(&head);

	printList(head);
}
