#include <bits/stdc++.h>
using namespace std;

vector<long long> weights;
vector<string> ans;
int sz;

bool comp(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++)
		{
			if (s1[i] > s2[j])
				return false;
			else if (s1[i] < s2[j])
				return true;
		}
		return true;
	}
	return s1.length() < s2.length();
}

void getAllStrings(long long wt, string cur, int index)
{
	if (wt < 0)
		return;

	if (wt == 0)
	{
		ans.push_back(cur);
		return;
	}

	if (index == -1)
		return ;

	string temp = cur;

	long long curWt = wt - weights[index];
	cur.push_back(char(65 + index));
	if (curWt >= weights[index])
		getAllStrings(curWt, cur, index);
	getAllStrings(curWt, cur, index - 1);
	getAllStrings(wt, temp, index - 1);

}

int main()
{
	long long wt;
	cin >> wt;

	long long cur = 1;
	weights.push_back(1);
	for (int i = 1; i < 26; i++)
	{
		cur = (i + 1) * cur + cur;
		if (cur > 1e16)
			break;
		weights.push_back(cur);
	}

	sz = weights.size();
	getAllStrings(wt, "", sz - 1);

	sort(ans.begin(), ans.end(), comp);

	string answer = ans[0];
	reverse(answer.begin(), answer.end());

	if (ans.size())
		cout << answer;
}


/*

#include <bits/stdc++.h>
using namespace std;

vector<long long> weights;
vector<string> ans;
int sz;

int main()
{
	long long wt;
	cin >> wt;

	long long cur = 1;
	weights.push_back(1);
	for (int i = 1; i < 26; i++)
	{
		cur = (i + 1) * cur + cur;
		if (cur > 1e16)
			break;
		weights.push_back(cur);
	}

	sz = weights.size();

	string curStr = "";
	for (int i = sz - 1; i >= 0; )
	{
		if (weights[i] > wt)
		{
			i--;
			continue;
		}

		wt -= weights[i];
		curStr.push_back(char(i + 65));
	}

	reverse(curStr.begin(), curStr.end());
	cout << curStr;
}

*/