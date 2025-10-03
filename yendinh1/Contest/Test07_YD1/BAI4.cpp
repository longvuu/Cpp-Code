/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "BAI4"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> a(n+1);
        for(ll i=1;i<=n;++i) cin >> a[i];
        vector<ll> s(n+1,0);
        for(ll i=1;i<=n;++i) s[i]=s[i-1]+a[i];
        const ll INF = (ll)4e18;
        vector<ll> dem(n+1,-1);  
        vector<ll> l(n+1,INF);    
        dem[0]=0; l[0]=0;
        for(ll i=1;i<=n;++i){
            dem[i]=-1; l[i]=INF;
            for(ll j=0;j<i;++j){
                if(dem[j]==-1) continue;
                ll sum = s[i]-s[j];
                if(sum >= l[j]){
                    ll t = dem[j] + 1;
                    if(t > dem[i] || (t==dem[i] && sum < l[i])){
                        dem[i]=t; l[i]=sum;
                    }
                }
            }
        }
        cout << dem[n] << '\n';
    }
    return 0;
}
