
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
	char start, end;
	cin >> start >> end;
	int n;
	cin >> n;
	unordered_map<char, int> map;
	map['v'] = 0;
	map['<'] = 1;
	map['^'] = 2;
	map['>'] = 3;

	int si = map[start], ei = map[end];
	bool cw = false, ccw = false;

	if ((si + n) % 4 == ei)
		cw = true;
	if (si - n >= 0 && (si - n) % 4 == ei)
		ccw = true;
	else if (si - n < 0 && (4 + (si - n) % 4) % 4 == ei)
		ccw = true;

	if (cw && ccw)
		cout << "undefined\n";
	else if (cw)
		cout << "cw\n";
	else if (ccw)
		cout << "ccw\n";
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

	// int t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}