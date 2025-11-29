/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "BIRTHDAY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n,k;
    cin >> n >> k;
    vector<ll> x(n),t(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> t[i];
    }
    priority_queue<ll> q;
    ll sum=0;
    ll res=0;
    for(ll i=0;i<n;i++){
        q.push(t[i]);
        sum+=t[i];
        while(!q.empty()&&x[i]+sum>k){
            sum-=q.top();
            q.pop();
        }
        res=max<ll>(res,q.size());
    }
    cout << res;
    return 0;
}