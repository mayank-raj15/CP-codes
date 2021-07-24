#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<int> stack;
	stack.push(-1);

	int n = s.length(), ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			stack.push(i);
		}
		else if (s[i] == ')')
		{
			stack.pop();
			if (stack.empty())
				stack.push(i);
			ans = max(ans, i - stack.top());
		}
	}

	cout << ans;

}
