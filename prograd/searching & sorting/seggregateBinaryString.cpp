#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		if (s[i] == '1' && s[i - 1] == '0')
		{
			s.erase(i, 1);
			s = '1' + s;
		}
	}

	cout << s;
}