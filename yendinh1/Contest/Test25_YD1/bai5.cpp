/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BAI5"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
vector<ll> TRAU(vector<ll> p){
    ll n =p.size()-1;
    vector<ll> d(n+1,1), pr(n+1,-1);
    ll b = 1;
    for(ll i=1;i<=n;i++){
        for(ll j=i-1;j>=1;j--){
            if(p[j] < p[i] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                pr[i] = j;
            }
        }
        if(d[i] > d[b]) b = i;
    }
    vector<ll> s;
    for(ll c = b; c != -1; c = pr[c]) s.pb(c);
    reverse(s.begin(), s.end());
    return s;
}
void FULL(int n, vector<ll>& d)
{
    vector<int> pb(n+1);
    for(int j=1;j<=n;j++) 
		pb[d[j]]=j;
    vector<int> a,b(n+1),c(n+1);
    for(int i=1;i<=n;i++)
	{
        int x=pb[i];
        int k=lower_bound(a.begin(),a.end(),x)-a.begin();
        if(k==(int)a.size()) 
			a.push_back(x);
        else 
			a[k]=x;
        c[k]=i;
       	if (k>0)
		    b[i]=c[k-1];
		else
		    b[i]=0;
    }
    int k=a.size();
    vector<int> dp;
    int cur=c[k-1];
    while(cur>0)
	{
        dp.push_back(cur);
        cur=b[cur];
    }
    reverse(dp.begin(),dp.end());
    cout<<k<<"\n";
    for(int i:dp) 
		cout<<i<<" "<<pb[i]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin >> a[i];
    FULL(n,a);
    return 0;
}
