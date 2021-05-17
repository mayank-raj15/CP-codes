
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

vector<string> ans;

void createStr(string s, map<char, int> cnt, int n)
{
	if (s.length() == n)
	{
		ans.push_back(s);
	}

	for (auto it = cnt.begin(); it != cnt.end(); it++)
	{
		if (it->second == 0)
			continue;
		//create a copy of everything that's to be passed
		string t = s;
		map<char, int> cntCopy = cnt;

		//add element to the string
		t += it->first;

		//reduct the remaining element in the copy of map
		cntCopy[it->first]--;
		createStr(t, cntCopy, n);
	}
}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	map<char, int> cnt;
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	createStr("", cnt, n);

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
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