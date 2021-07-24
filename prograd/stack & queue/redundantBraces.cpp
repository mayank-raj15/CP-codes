#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	stack<char> braces;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')')
		{
			if (braces.top() == '(')
			{
				cout << "Yes";
				return 0;
			}

			while (braces.top() != '(')
				braces.pop();

			braces.pop();
		}
		else if (s[i] >= 40 && s[i] <= 47)
		{
			braces.push(s[i]);
		}

	}

	cout << "No";
}