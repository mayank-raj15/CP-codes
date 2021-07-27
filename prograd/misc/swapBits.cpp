#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int x)
{
	return (n >> x) & 1;
}

void swapBit(int &n, int x, int y)
{
	int bx = getBit(n, x), by = getBit(n, y);
	int mask = (1 << x);
	n = (n & ~mask) | (-by & mask);
	mask = (1 << y);
	n = (n & ~mask) | (-bx & mask);
}

int main()
{
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	swapBit(n, x, y);
	cout << n << "\n";
	string ans = "";
	while (n > 0)
	{
		if (n & 1)
			ans = "1" + ans;
		else
			ans = "0" + ans;
		n = n >> 1;
	}

	while (ans.length() % 8 != 0)
	{
		ans = "0" + ans;
	}

	cout << ans;
}