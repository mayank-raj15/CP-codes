#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    vector<int> x;
    vector<int> y;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n + 2);
        for (int i = 0; i < n + 2; i++)
            cin >> b[i];

        ll sum = 0, sum2 = 0;
        sort(b.begin(), b.end());
        int mx = b[n + 1];

        for (int i = 0; i < n; i++)
        {
            sum2 += b[i];
        }
        int index;
        sum -= mx;
        if (sum - sum2 == b[n])
        {
            for (int i = 0; i < n; i++)
                cout << b[i] << " ";
            cout << "\n";
            break;
        }
        else
        {
            for (int i = 0; i <= n; i++)
            {
                if (sum - b[i] == mx)
                {
                    index = i;
                    break;
                }
            }

            for (int i = 0; i < n + 1; i++)
            {
                if (i != index)
                {
                    cout << b[i] << " ";
                }
            }
            cout << "\n";
            break;
        }
        cout << -1;
    }
}