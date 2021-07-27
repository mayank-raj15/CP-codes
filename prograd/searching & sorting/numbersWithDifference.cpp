#include <bits/stdc++.h>
using namespace std;

int sumDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n, d;
	cin >> n >> d;
	int ans = 0;
	for (int i = 1; i <= n; i++ )
	{
		if (abs(i - sumDigits(i)) >= d)
			ans ++;
	}

	cout << ans;
}