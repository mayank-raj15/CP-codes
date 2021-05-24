
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

vector<vector<int>> v(1001, vector<int> (1001, 0));

void solve()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	ll sum = 0;
	for (int i = x1; i <= x2; i++)
	{
		sum += v[i][y1];
	}
	for (int j = y1 + 1; j <= y2; j++)
	{
		sum += v[x2][j];
	}

	cout << sum << "\n";
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
	v[1][1] = 1;
	int k = 2;
	for (int i = 2; i <= 1000; i++)
	{
		v[i][1] = v[i - 1][1] + k;
		k++;
	}
	k = 1;
	for (int j = 2; j <= 1000; j++)
	{
		v[1][j] = v[1][j - 1] + k;
		k++;
	}

	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			v[i][j] = 2 * v[i][j - 1] - v[i - 1][j - 1];
		}
	}

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