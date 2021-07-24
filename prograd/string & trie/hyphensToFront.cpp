#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.length();
	int hyphens = 0;
	for (int i = 0; i < n;)
	{
		if (s[i] == '-')
		{
			hyphens++;
			s.erase(i, 1);
		}
		else
			i++;
	}

	string hyp(hyphens, '-');
	string ans = hyp + s;
	cout << ans;
}