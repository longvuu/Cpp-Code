#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[10006];
priority_queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1, greater<>());
    int L, P;
    cin>>L>>P;
    int i=1, d=0;
    while (P<L)
    {
        while (a[i].first>=L-P && i<=n)
        {
            q.push(a[i].second);
            i+=1;
        }
        if (q.empty()) break;
        P+=q.top();
        q.pop();
        d+=1;
    }
    if (P>=L) cout<<d;
    else cout<<-1;
    return 0;
}
