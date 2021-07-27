#include <bits/stdc++.h>
using namespace std;

int flipBit(unsigned int n)
{
	int left = 0, right = 0, ans = 0;
	bool zero = false;
	while (n > 0)
	{
		if (n & 1)
		{
			right++;
			zero = false;
		}
		else if (!zero && !(n & 1))
		{
			zero = true;
			ans = max(ans, right);
			if (left && right)
			{
				ans = max(ans, left + right);
			}
			left = right;
			right = 0;
		}
		else if (zero && !(n & 1))
		{
			left = right = 0;
		}

		n = n >> 1;
	}

	if (left && right)
		ans = max(ans, left + right);
	else
		ans = max(right, ans);
	return ans + 1;
}

int main()
{
	unsigned int n;
	cin >> n;
	cout << flipBit(n);
}