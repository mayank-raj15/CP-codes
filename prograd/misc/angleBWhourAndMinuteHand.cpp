#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, min;
	cin >> h >> min;
	int ah = 30 * (h % 12) + min / 2;
	int am = 6 * min;

	int ans = abs(ah - am);

	cout << ans << " degree";
}