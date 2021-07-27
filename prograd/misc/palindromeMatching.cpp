#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	string str, s;
	cin >> str;
	s = str;

	int i = 0, j = n - 1;
	while (i <= j)
	{
		if (s[i] != s[j])
		{
			k--;
			if (s[i] > s[j])
				s[j] = s[i];
			else
				s[i] = s[j];
		}
		i++;
		j--;
	}

	if (k < 0)
	{
		cout << "-1";
		return 0;
	}

	i = 0, j = n - 1;

	while (i <= j)
	{
		if (i == j && k > 0)
			s[i] = '9';

		if (s[i] < '9')
		{
			if (k >= 2 && s[i] == str[i] && s[j] == str[j])
			{
				k -= 2;
				s[i] = s[j] = '9';
			}
			else if (k >= 1 && (s[i] != str[i] || s[j] != str[j]))
			{
				k -= 1;
				s[i] = s[j] = '9';
			}
		}
		i++;
		j--;
	}

	for (int i = 0; i < n; i++)
		cout << s[i];
}