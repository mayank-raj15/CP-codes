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
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			braces.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']' )
		{
			if (braces.empty())
			{
				cout << "Not Balanced";
				return 0;
			}
			else if (s[i] == ')' && braces.top() != '(' || s[i] == '}' && braces.top() != '{' ||
			         s[i] == ']' && braces.top() != '[')
			{
				cout << "Not Balanced";
				return 0;
			}

			braces.pop();

		}
	}

	if (!braces.empty())
	{
		cout << "Not Balanced";
	}
	else
		cout << "Balanced";
}