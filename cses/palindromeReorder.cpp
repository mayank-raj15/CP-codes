
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	map<char, int> cnt;
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	int odd = 0;
	char mid;
	for (auto it : cnt)
	{
		if (it.se % 2)
		{
			mid = it.fi;
			odd++;
		}
	}
	if (odd > 1 || (n % 2 != 1 && odd == 1))
	{
		cout << "NO SOLUTION";
		return ;
	}
	if (odd == 1)
	{
		cnt[mid]--;
		s[n / 2] = mid;
	}
	int i = 0;
	for (auto it = cnt.begin(); it != cnt.end(); it++)
	{
		while (it->second > 0)
		{
			if (i != n / 2 || odd == 0)
			{
				s[i] = it->first;
				s[n - i - 1] = s[i];
				it->second -= 2;
			}
			i++;
		}
	}

	cout << s;
}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--)
	solve();
}