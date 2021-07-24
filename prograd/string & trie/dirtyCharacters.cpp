#include <bits/stdc++.h>
using namespace std;

string removeDirtyChars(string &str, string &mask_str)
{
	unordered_map<char, bool> map;
	for (int i = 0; i < mask_str.length(); i++)
		map[mask_str[i]]++;

	string ans = str;
	for (int i = 0; i < str.length();)
	{
		if (map[ans[i]])
			ans.erase(i, 1);
		else
			i++;
	}

	return ans;
}

int main()
{
	string str, mask_str;
	getline(cin, str);
	getline(cin, mask_str);

	cout << removeDirtyChars(str, mask_str);
}