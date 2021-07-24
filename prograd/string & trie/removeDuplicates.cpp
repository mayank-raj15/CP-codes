#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<char, bool> map;

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); )
	{
		if (map[s[i]])
			s.erase(i, 1);
		else
		{
			map[s[i]] = true;
			i++;
		}
	}

	cout << s;
}