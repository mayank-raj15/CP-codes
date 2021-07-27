#include <bits/stdc++.h>
using namespace std;

int getBits(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		n = n >> 1;
		cnt++;
	}
	return cnt;
}

bool isSetBit(int n, int k)
{
	return (n & (1 << k)) ? true : false;
}

int main()
{
	int n;
	cin >> n;
	int l = 0, r = getBits(n) - 1;
	while (l <= r)
	{
		if (isSetBit(n, l) != isSetBit(n, r))
		{
			cout << "no";
			return 0;
		}
		l++; r--;
	}
	cout << "yes";
}