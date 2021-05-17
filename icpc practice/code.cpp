
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
	int a[100001] = {0};
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a[temp]++;
	}

	ll ans = 0;

	for (int i = 0; i < 100001; i++)
	{
		int cur = a[i];
		ll curAns = 1;
		while (cur--)
		{
			curAns = (curAns * 2) % mod;
			if (cur == 0)
			{
				ans += curAns % mod;
				ans -= 1;
				if (ans < 0)
					ans = (ans % mod) + mod;
			}
		}

	}

	cout << ans;
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