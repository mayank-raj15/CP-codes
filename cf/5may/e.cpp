
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

	int sc = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
			sc++;
	}

	int sl = 0, md = sc / 2;
	int cnt = 0, index;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
			s1++;

		if (s1 == md)
		{
			index = i;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '*')
		{
			cnt += abs(index - i) - s1;
		}
	}

	cout <<
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
	{
		solve();
	}
}