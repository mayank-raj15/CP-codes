#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> s(3);
	for (int i = 0; i < 3; i++)
		cin >> s[i];

	string ans = "0000";
	for (int i = 0; i < 4; i += 2)
	{
		char mn = '9';
		for (int j = 0; j < 3; j += 1)
		{
			if (mn > s[j][i])
				mn = s[j][i];
		}
		ans[i] = mn;
	}

	for (int i = 1; i < 4; i += 2)
	{
		char mx = '0';
		for (int j = 0; j < 3; j += 1)
		{
			if (mx < s[j][i])
				mx = s[j][i];
		}
		ans[i] = mx;
	}

	cout << ans;
}

/*

Find the Key
You are provided with 3 numbers: input1, input 2 and input 3. Each of these is a four-digit number within the range >=1000 and <=9999. i.e. 1000<=input1<=9999 1000<=input2<=9999 1000<=input3<=9999 You are expected to find the key using this formula: Key = [smallest digit in the thousands place of all three numbers] [largest digit in the hundreds place of all three numbers] [smallest digit in the tens place of all three numbers] [largest digit in the units place of all three numbers]
Input Format

First line consists of integer value of input1

Second line consists of integer value of input2

Third line consists of integer value of input3

Output Format

Output should be an integer value of given key

Constraints

1000 <= input1 <= 9999

1000 <= input2 <= 9999

1000 <= input3 <= 9999

Refer the sample output for formatting

Sample Input:

3521

2452

1352

Sample Output:

Key=1522

*/