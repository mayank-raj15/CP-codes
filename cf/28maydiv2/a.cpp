
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
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())


void solve()
{
	int n;
	cin >> n;
	n = 2 * n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int b[n];
	int i = 0, j = 1;
	while (j < n)
	{
		b[j] = a[i];
		j += 2;
		i++;
	}
	j = 0;
	while (j < n)
	{
		b[j] = a[i];
		i++;
		j += 2;
	}

	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << "\n";
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