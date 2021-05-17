
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
	int k = 1;
	int a[n][n];
	int i = 0, j = 0, c = 0;

	if (n == 2)
	{
		cout << "-1\n";
		return;
	}

	int x = i, y = j;
	while (x < n && y < n)
	{
		a[x][y] = k;
		x++;
		y++;
		k++;
	}
	c++;

	while (c < n)
	{
		x = i;
		y = i + c;

		while (x < n - c && y < n)
		{
			a[x][y] = k;
			x++;
			y++;
			k++;
		}

		x = i + c;
		y = i;

		while (x < n && y < n - c)
		{
			a[x][y] = k;
			x++;
			y++;
			k++;
		}

		c++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
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