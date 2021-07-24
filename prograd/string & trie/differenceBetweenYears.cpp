#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "", temp, ds = "";
	while (getline(cin, temp))
	{
		s += temp + " ";
	}

	unordered_set<string> set;

	int i = 0, j = 0;
	while (i < s.length())
	{
		if (s[i] == '-' && (j == 2 || j == 5))
		{
			ds = "";
			i++, j++;
		}
		else if ((j != 2 && j != 5) && s[i] <= '9' && s[i] >= '0')
		{
			ds.push_back(s[i]);
			i++;
			j++;

			if (ds.length() == 4)
			{
				set.insert(ds);
				ds = "";
				j = 0;
			}
		}
		else
		{
			i = i - j + 1;
			j = 0;
			ds = "";
		}
	}

	cout << set.size();
}