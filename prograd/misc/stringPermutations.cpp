#include <bits/stdc++.h>
using namespace std;

void getPermutations(string cur, int index, set<char> st)
{
	if (st.empty())
	{
		cout << cur << "\n";
		return;
	}

	for (auto it : st)
	{
		set<char> temp = st;
		temp.erase(it);
		cur.push_back(it);
		getPermutations(cur, index + 1, temp);
		cur.pop_back();
	}
}

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	set<char> st(s.begin(), s.end());
	getPermutations("", 0, st);
}

/*

Permutations - All of Them
"I'm not a fan of having kids memorize formulas, and I'm even less of a fan of pushing them to learn those formulas," says Mr. John, 7th grade Math teacher. Maybe he has got a point. He believes in teaching the logic rather than the formula. Anyway, we aren't here to weigh/debate about his opinions. All we gotta do is help Mr. John and his students by writing an algorithm that can calculate & print all the permutations of a given number in strictly sorted order. Remember, Mr. John is gonna use your algorithm to demonstrate permutations in his next class.
Input Format

The input consists of a string

Output Format

Print all the permutations of the given string

Refer the sample output for formatting

Sample Input:

abc

Sample Output:

abc

acb

bac

bca

cab

cba

*/