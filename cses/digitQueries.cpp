
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
	ull k;
	cin >> k;
	ull i = 1;
	ull cur;
	while (1)
	{
		// if (INT_MAX / 9 / i / 10 < cur / 2)
		// 	break;
		cur = (9 * i - 1) * pow(10, i - 1) / 9;
		if (cur > k)
			break;
		i++;
	}
	cout << cur << " ";
	int sz = i;
	i--;
	k -= (9 * i - 1) * pow(10, i - 1) / 9;
	i++;
	cout << k << " ";
	ull num = k / i + pow(10, i - 1) - 1;
	ull rem = k % i;
	if (rem > 0)
	{
		num++;
		string s = to_string(num);
		cout << s[rem - 1] << "\n";
	}
	else
	{
		string s = to_string(num);
		cout << s[s.length() - 1] << "\n";
	}

	cout << num;

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