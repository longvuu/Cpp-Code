#include <bits/stdc++.h>
#define N 10000
using namespace std;
int a[N+3];
int n, ans;
int main()
{
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        s= " " + s;
        memset(a,0, sizeof(a));
        a[1] = 1;
        for(int i=1; i<s.size(); i++)
            {
                if (s[i-1] == s[i])   a[i] = a[i-1] + 1;
                else a[i] = 1;
                ans = max(ans, a[i]);
            }
    }
    cout << ans;
    return 0;
}
