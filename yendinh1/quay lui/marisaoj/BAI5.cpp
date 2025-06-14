/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int x[100],b[100],n,k;
void inkq(){
    for(ll i =1;i<=k;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
void quaylui(int i) {
    for (ll v = 1; v <= n; v++) {
        if (b[v] == 0) {
            x[i] = v;
            b[v] = 1;
            if (i == k) {
                inkq();
            } else {
                quaylui(i + 1);
            }
            b[v] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    quaylui(1);
    return 0;
}