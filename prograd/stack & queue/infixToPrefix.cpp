#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	stack<char> stack;
	int n = s.length();
	string ans = "";

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			s[i] = ')';
		else if (s[i] == ')')
			s[i] = '(';
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			stack.push(s[i]);
		else if (s[i] == ')')
		{
			while (stack.top() != '(')
			{
				ans += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else if (s[i] >= 42 && s[i] <= 47)
		{
			while ((s[i] == '+' || s[i] == '-') && !stack.empty() && stack.top() != '(')
			{
				ans += stack.top();
				stack.pop();
			}

			while ((s[i] == '*' || s[i] == '/') && !stack.empty() && stack.top() != '(' &&
			        stack.top() != '+' && stack.top() != '-')
			{
				ans += stack.top();
				stack.pop();
			}

			stack.push(s[i]);
		}
		else
			ans += s[i];
	}

	while (!stack.empty())
	{
		ans += stack.top();
		stack.pop();
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
}
