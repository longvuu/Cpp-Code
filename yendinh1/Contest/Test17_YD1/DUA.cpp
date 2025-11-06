/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DUA"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int k,n,d[100010];
bool kt[100010];
ll a[100010];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin>>k>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    a[0]=LLONG_MIN;
    vector<ll>v;
    for(int i=1;i<=n;i++)
    {
        if(k==0)
            break;
        if(!kt[i]&&a[i]!=a[i-1])
        {
            v.push_back(a[i]);
            kt[i]=true;
            k--;
        }
    }
    if(k>0)
    {
        for(int i=n;i>=1;i--)
        {
            if(k==0)
                break;
            if(!kt[i])
            {
                v.push_back(a[i]);
                k--;
            }
        }
    }
    ll res=0;
    for(int i=0;i<v.size();i++)
        d[v[i]]++;
    for(int i=0;i<v.size();i++)
        if(d[v[i]]==1)
            res+=v[i];
    cout<<res;
    return 0;
    
    return 0;
}