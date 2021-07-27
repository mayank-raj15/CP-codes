#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), ans(n, 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int lp = 1, rp = 1;
	for (int i = 0; i < n; i++)
	{
		ans[i] *= lp;
		ans[n - i - 1] *= rp;
		lp *= a[i];
		rp *= a[n - i - 1];
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}