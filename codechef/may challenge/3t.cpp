#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if ((m % j) % i == (m % i) % j)
				cnt++;
		}
	}

	cout << cnt;
}

