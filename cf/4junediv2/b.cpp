
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			b.push_back(a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 1)
			b.push_back(a[i]);
	}
	int cnt = 0;

	// for (int i = 0; i < n; i++)
	// 	cout << b[i] << " ";
	// cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x = max(b[i], 2 * b[j]), y = min(b[i], 2 * b[j]);
			//cout << x << " " << y << ": ";
			if (gcd(x, y) > 1)
			{
				//cout << x << " " << y;
				cnt++;
			}
			//cout << "\n";
		}
	}

	cout << cnt << "\n";
}

int main()
{
	//for time calculation
#ifndef ONLINE_JUDGE
	auto start = chrono::steady_clock::now();
#endif

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

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}