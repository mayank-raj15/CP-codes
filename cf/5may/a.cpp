
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
#define all(x) x.begin(),x.end()

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> map;
	for (int i = 0; i < n; i++)
	{
		map[char(65 + i)] = 0;
	}

	int flag = 1;
	map[s[0]]++;

	for (int i = 1; i < n; i++)
	{
		if (map[s[i]] > 0 && s[i - 1] != s[i])
		{
			flag = 0;
			break;
		}
		map[s[i]]++;
	}

	if (flag == 1)
		cout << "YES";
	else
		cout << "NO";

	cout << "\n";
}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
		solve();
}