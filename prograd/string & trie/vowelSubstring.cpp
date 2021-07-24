#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	unordered_map<char, int> vowel;
	vowel['a'] = 1, vowel['e'] = 1, vowel['i'] = 1, vowel['o'] = 1, vowel['u'] = 1;
	unordered_map<char, int> sub;
	int n = s.length();
	int i = 0, ans = 0;
	while (i < n)
	{
		for (int j = i; j < n; j++)
		{
			if (vowel.find(s[j]) != vowel.end())
			{
				sub[s[j]]++;
			}
			else
			{
				if (sub.size() < 5)
				{
					i = j;
				}
				break;
			}

			if (sub.size() == 5)
			{
				ans++;
			}
		}
		i++;
		sub.clear();
	}
	cout << ans;
}