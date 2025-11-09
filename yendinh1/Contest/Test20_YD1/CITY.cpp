/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "CITY"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5000;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n;
    cin >> n;
    vector<int> a(N+1,0);
    int k = 0;
    for(int i =0,x;i<n;i++){
        cin >> x;
        if (1 <= x && x <= N) {
            a[x]++;
            k = max(k, x);
        }
    }
    ll res = 0;
    for(int i = 1; i <= N;i++) {
        if (a[i]>=2) res+=1LL*a[i]*(a[i]-1)/2;
    }
    int t = 0;
    while ((1 << (t + 1)) <= max(N, k)) t++;
    for(int i = 1; i <= N;i++) if (a[i]) {
        for(int j = 0; j <= t;j++) {
            int u = i ^ (1 << j);
            if (u > i && u <= N) res += 1LL * a[i] * a[u];
        }
    }
    cout << res << "\n";
    return 0;
}