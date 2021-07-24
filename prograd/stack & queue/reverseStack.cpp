#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	stack<char> stack1;
	for (int i = 0; i < n; i++)
		stack1.push(s[i]);

	stack<char> stack2;
	while (!stack1.empty())
	{
		stack2.push(stack1.top());
		stack1.pop();
	}

	while (!stack2.empty())
	{
		stack1.push(stack2.top());
		stack2.pop();
	}

	string ans = "";
	while (!stack1.empty())
	{
		ans += stack1.top();
		stack1.pop();
	}

	cout << ans;
}