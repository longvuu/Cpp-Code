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
void TRAU(string st,ll n,ll k){
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll dem = 0;
        for (ll j = i; j < n; j++) {
            if (st[j] == '1') dem++;
            if (dem == k) res++;
        }
    }
    cout << res;
}
void FULL(string st, ll n, ll k) {
    ll res = 0;
    vector<ll> s(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (st[i - 1] - '0');
    }
    for (ll i = 1; i <= n; i++) {
        if (s[i] >= k) {
            ll l = -1, r = -1;
            ll l1 = 0, r1 = i - 1;
            while (l1 <= r1) {
                ll mid = (l1 + r1) / 2;
                if (s[mid] == s[i] - k) {
                    l = mid;
                    r1 = mid - 1;
                } else if (s[mid] > s[i] - k) {
                    r1 = mid - 1;
                } else {
                    l1 = mid + 1;
                }
            }
            l1 = 0, r1 = i - 1;
            while (l1 <= r1) {
                ll mid = (l1 + r1) / 2;
                if (s[mid] == s[i] - k) {
                    r = mid;
                    l1 = mid + 1;
                } else if (s[mid] > s[i] - k) {
                    r1 = mid - 1;
                } else {
                    l1 = mid + 1;
                }
            }
            if (l != -1 && r != -1) {
                res += (r - l + 1);
            }
        }
    }

    cout << res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll k;
    string st;
    cin >> k;
    cin >> st;
    ll n = st.size();
    FULL(st,n,k);
    return 0;
}