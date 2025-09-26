/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "hohang"
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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        ll sum1=0,sum2=0;
        for(ll i=0;i<n;i++) sum1+=(ll)s1[i];
        for(ll i=0;i<n;i++) sum2+=(ll)s2[i];
        if(sum1==sum2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    
    return 0;
}