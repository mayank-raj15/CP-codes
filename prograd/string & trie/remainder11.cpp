#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int even = 0, odd = 0;
	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		if (i % 2)
			odd += int(s[i]) - 48;
		else
			even += int(s[i]) - 48;
	}


	if (abs(even - odd) % 11 == 0)
		cout << 0;
	else if (n % 2)
	{
		if (even > odd)
			cout << abs(even - odd) % 11;
		else
			cout << 11 - abs(even - odd) % 11;
	}
	else
	{
		if (even < odd)
			cout << abs(even - odd) % 11;
		else
			cout << 11 - abs(even - odd) % 11;

	}
}