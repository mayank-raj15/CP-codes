#include <bits/stdc++.h>
using namespace std;

int ans;

struct Node
{
	int data;
	Node *next;
};

void getNthNode(Node *head, int &n)
{
	if (head == NULL)
		return;
	getNthNode(head->next, n);
	n--;
	if (n == 0)
		ans = head->data;
}

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

int main()
{
	Node *head = NULL;
	int x;
	while (cin >> x)
	{
		if (x == -1)
			break;
		append(&head, x);
	}
	int n;
	cout << "Enter the nth node:" << endl;
	cin >> n;
	ans = -1;
	getNthNode(head, n);
	if (ans == -1)
		cout << "There is no nth node in the list";
	else
		cout << ans << " is the nth node element in the list";
}
