#include <bits/stdc++.h>
using namespace std;

void getCombinations(multiset<int> &st, vector<int> &nums, int cur, int &len)
{
	if (cur == len)
	{
		for (auto it : nums)
			cout << it << ",";
		cout << "\n";
		return;
	}

	multiset<int> temp = st;

	for (auto it : st)
	{
		temp.erase(it);
		nums.push_back(it);
		getCombinations(temp, nums, cur + 1, len);
		nums.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	reverse(a.begin(), a.end());

	multiset<int> st(a.begin(), a.end());
	vector<int> nums;
	for (int i = n; i >= 0; i--)
	{
		multiset<int> temp = st;
		for (auto it : st)
		{
			nums.push_back(it);
			temp.erase(it);
			getCombinations(temp, nums, 1, i);
			nums.pop_back();
		}
	}
	cout << "\n";

}