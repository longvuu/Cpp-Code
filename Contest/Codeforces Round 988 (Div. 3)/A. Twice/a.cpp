/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;

int main() {
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> cnt(101, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        ll res=0;
        for(int i = 0; i < 101; i++) {
            if (cnt[i] % 2 == 0) {
                res+=cnt[i]/2;
            }else if(cnt[i]>=3&&cnt[i]%2==1){
                res+=cnt[i]/2;
            }
        }
        cout << res << endl;
    }

    return 0;
}