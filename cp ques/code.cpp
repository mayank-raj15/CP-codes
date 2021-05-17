#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int t,q,d;
    cin>>t>>q>>d;
    while(t--)
    {
        int qr=q;
        ll x1=0,y1=0,x2=0,y2=0;
        string s;
        cout<<1<<" "<<x1<<" "<<y1;
        cout<<endl;
        cin>>s;
        qr--;
        if(s=="O")
        {
            continue;
        }
        else if(s=="PY")
        {
            y2=y1;
            x1=-1e18;
        }
        else if(s=="NY")
        {
            x2=1e18;
            y2=y1;
        }
        else if(s=="XP")
        {
            x2=x1;
            y1=-1e18;
        }
        else if(s=="XN")
        {
            x2=x1;
            y2=1e18;
        }
        else if(s=="PP")
        {
            x1=-1e18;
            y1=-1e18;
        }
        else if(s=="PN")
        {
            x1=-1e18;
            y2=1e18;
        }
        else if(s=="NP")
        {
            x2=1e18;
            y1=-1e18;
        }
        else if(s=="NN")
        {
            x2=1e18;
            y2=1e18;
        }
        while(1)
        {
            int x=(x1+x2)/2, y=(y1+y2)/2;
            cout<<1<<" "<<x<<" "<<y;
            cout<<endl;
            cin>>s;
            qr--;
            if(s=="O")
            {
                cout<<endl;
                break;
            }
            else if(s=="PY")
            {
                y2=y1=y;
                x2=x;
            }
            else if(s=="NY")
            {
                x1=x;
                y2=y1=y;
            }
            else if(s=="XP")
            {
                x2=x1=x;
                y2=y;
            }
            else if(s=="XN")
            {
                x2=x1;
                y1=y;
            }
            else if(s=="PP")
            {
                x2=x;
                y2=y;
            }
            else if(s=="PN")
            {
                x2=x;
                y1=y;
            }
            else if(s=="NP")
            {
                x1=x;
                y2=y;
            }
            else if(s=="NN")
            {
                x1=x;
                y1=y;
            }
            
            if(qr==0)
                return 0;
        }
    }
    return 0;
}