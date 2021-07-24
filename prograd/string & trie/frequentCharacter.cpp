#include <bits/stdc++.h>
using namespace std;

int mostFrequentCharacter(string s, int n)
{
	vector<int> alpha(26, 0);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		alpha[s[i] - 97]++;
		ans = max(ans, alpha[s[i] - 97]);
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	cout << mostFrequentCharacter(s, n);
}