
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
	string s;
	cin >> s;
	int n = s.length();
	string ans = "";
	unordered_map<char, int> index;
	unordered_map<char, int> map;
	for (int i = 0; i < n; i++)
	{
		map[s[i]]++;
		index[s[i]] += i;
	}

	unordered_map<char, int> place;

	for (auto item : map)
	{
		int cur = index[item.first] / item.second;
		if (cur >= (n + 1) / 2)
			place[item.first] = 1;
		else
			place[item.first] = 0;
	}

	set<char> p0;
	set<char> p1;

	for (auto i : place)
	{
		if (i.second == 0)
			p0.insert(i.first);
		else if (i.second == 1)
			p1.insert(i.first);
	}

	char lf;
	char rf;

	for (int i = 0; i < n; i++)
	{
		if (p0.find(s[i]) != p0.end())
		{
			lf = s[i];
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (p0.find(s[i]) != p0.end())
		{
			rf = s[i];
		}
	}

	p0.erase(lf);
	p1.erase(rf);

	for (auto i : p0)
	{
		while (map[i] > 0)
		{
			ans = i + ans;
			map[i]--;
		}
	}

	for (auto i : p1)
	{
		while (map[i] > 0)
		{
			ans = ans + i;
			map[i]--;
		}
	}

	while (map[lf] > 0)
	{
		ans = lf + ans;
		map[lf]--;
	}

	while (map[rf] > 0)
	{
		ans = ans + rf;
		map[lf]--;
	}

	cout << ans << "\n";
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