
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


void solve()
{
	ll a, b, k1, k2;
	cin >> a >> b >> k1 >> k2;

	if (abs(k1) == abs(k2) && a != b)
	{
		cout << "NO\n";
		return;
	}

	if (abs(k1) == abs(k2) && a == b)
	{
		cout << "YES\n";
		return;
	}


	double x = (double)(a * k1 - b * k2) / (k1 * k1 - k2 * k2);
	double y = (double)(a - k1 * x) / k2;


	if (floor(x) == x && floor(y) == y)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	//for time calculation
// #ifndef ONLINE_JUDGE
// 	auto start = chrono::steady_clock::now();
// #endif

	send help
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

// #ifndef ONLINE_JUDGE
// 	auto end = chrono::steady_clock::now();

// 	auto diff = end - start;

// 	cout << "\nTime taken: ";
// 	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
// #endif
}