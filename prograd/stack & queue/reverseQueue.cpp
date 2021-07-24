#include <bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> q;
	int temp;
	while (cin >> temp)
	{
		if (temp == -1)
			break;
		q.push(temp);
	}

	if (q.empty())
	{
		cout << "Queue is empty\n";
		return 0;
	}

	stack<int> stack;
	cout << "Before reversing:\n";
	while (!q.empty())
	{
		cout << q.front() << " ";
		stack.push(q.front());
		q.pop();
	}

	cout << "\n";

	while (!stack.empty())
	{
		q.push(stack.top());
		stack.pop();
	}

	cout << "After reversing:\n";
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
}