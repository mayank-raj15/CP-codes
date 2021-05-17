
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
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int i = 0, j = n - 1;
	int cnt = 0;
	while (i <= j)
	{
		if (i == j)
			cnt++;
		else
		{
			if (a[i] + a[j] <= x)
			{
				cnt++;
				i++;
				j--;
			}
			else
			{
				cnt++;
				j--;
			}
		}
	}

	cout << cnt;
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