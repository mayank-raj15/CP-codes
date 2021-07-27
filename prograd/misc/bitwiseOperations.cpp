#include <bits/stdc++.h>
using namespace std;

int setBits(int n)
{
	int temp = n, count = 0;
	while (temp > 0)
	{
		if (temp & 1)
			count++;
		temp = temp >> 1;
	}
	return count;
}

int lsb(int n)
{
	int pos = 0;
	while (n > 0)
	{
		if (n & 1)
			return pos;
		n = n >> 1;
		pos++;
	}
	return 0;
}

int msb(int n)
{
	int pos = 0, ans = 0;
	while (n > 0)
	{
		if (n & 1)
			ans = pos;
		n = n >> 1;
		pos++;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int a = setBits(n);
	int b = lsb(n);
	int c = msb(n);
	cout << a << '#' << b << '#' << c;
}