
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
	vector<string> v1 = {"0", "1"};
	n--;
	while (n--)
	{
		vector<string> v2 = v1;
		reverse(all(v2));
		for (int i = 0; i < v1.size(); i++)
		{
			v1[i] = "0" + v1[i];
		}

		for (int i = 0; i < v2.size(); i++)
		{
			v1.push_back("1" + v2[i]);
		}
	}

	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "\n";
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