
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

void towerOfHanoi(int n, int s, int d, int h)
{
	if (n == 1)
	{
		cout << s << " " << d << "\n";
		return ;
	}
	towerOfHanoi(n - 1, s, h, d);
	cout << s << " " << d << "\n";
	towerOfHanoi(n - 1, h, d, s);
}

void solve()
{
	int n;
	cin >> n;
	cout << pow(2, n) - 1 << "\n";
	towerOfHanoi(n, 1, 3, 2);
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