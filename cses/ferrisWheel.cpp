
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
	int p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	sort(p, p + n);

	int g = 0, i = 0, j = n - 1;
	while (i <= j)
	{
		if (i == j)
		{
			g++;
			break;
		}
		else if (p[i] + p[j] <= x)
		{
			i++;
			j--;
			g++;
		}
		else
		{
			j--;
			g++;
		}
	}

	cout << g;

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