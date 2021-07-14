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

bool deleteSecondLast(Node **head)
{
	Node *prev = NULL;
	Node *cur = *head;
	if (cur == NULL || cur->next == NULL)
		return false;

	while (cur->next->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	prev->next = cur->next;
	free(cur);
	return true;
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
	int x;
	while (cin >> x)
	{
		if (x < 0)
			break;
		append(&head, x);
	}

	bool isPossible = deleteSecondLast(&head);

	if (!isPossible)
	{
		cout << "Deletion of second last element is not possible";
		return 0;
	}
	printList(head);
}
