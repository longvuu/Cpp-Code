/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "btkptich"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n;
vector<int> a;

void inkq(){
    cout << n << " = ";
    for(ll i =0;i<a.size();i++){
        cout << a[i];
        if(i<a.size()-1)  cout << "+";
    }
    cout << endl;
}
void quaylui(ll sum, int i) {
    for (ll v = i; v <= n; v++) {
        if (sum + v > n) break;
        a.pb(v);
        if (sum + v == n) {
            inkq();
        } else {
            quaylui(sum + v, v);
        }
        a.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n;
    quaylui(0, 1);
    return 0;
}