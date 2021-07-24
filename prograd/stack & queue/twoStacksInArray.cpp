#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

int Stack[SIZE], top1 = -1, top2 = SIZE;

void push(int value, int n)
{
	if (top1 == top2)
	{
		return;
	}

	switch (n)
	{
	case 1:
		top1++;
		Stack[top1] = value;
		break;

	case 2:
		top2--;
		Stack[top2] = value;
		break;
	}
}

int pop(int n)
{
	switch (n)
	{
	case 1:
		if (top1 == -1)
			return INT_MAX;
		else
		{
			int ret = Stack[top1];
			top1--;
			return ret;
		}
		break;

	case 2:
		if (top2 == n)
			return INT_MAX;
		else
		{
			int ret = Stack[top2];
			top2++;
			return ret;
		}
		break;
	}
}

void display(int n)
{
	switch (n)
	{
	case 1:
		for (int i = top1; i >= 0; i--)
			cout << Stack[i] << " ";
		break;
	case 2:
		for (int i = top2; i < SIZE; i++)
			cout << Stack[i] << " ";
		break;
	}
	cout << "\n";
}

int main()
{
	int m, n, val;
	cin >> m;
	while (m--)
	{
		cin >> val;
		push(val, 1);
	}

	cin >> n;
	while (n--)
	{
		cin >> val;
		push(val, 2);
	}

	cout << "Stack 1 Elements:\n";
	display(1);
	cout << "Stack 2 Elements:\n";
	display(2);

	cin >> m >> n;
	while (m--)
	{
		int ans = pop(1);
		if (ans == INT_MAX)
		{
			cout << "Stack underflow. pop from Stack 1 failed \n";
			break;
		}
	}

	while (n--)
	{
		int ans = pop(2);
		if (ans == INT_MAX)
		{
			cout << "Stack underflow. pop from Stack 2 failed \n";
			break;
		}
	}

	cout << "Stack 1 Elements: \n";
	display(1);
	cout << "Stack 2 Elements: \n";
	display(2);
}