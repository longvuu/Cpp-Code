/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define pb push_back
using namespace std;
string st;
ll key;
int main() {
    freopen(taskname ".inp", "r", stdin);
    freopen(taskname ".out", "w", stdout);
    ll n;
    map<string,ll> m;
    cin >> n;
    while(n--){
        cin >> key >> st;
        if(key == 1){
            m[st]++;
        }else{
            cout << m[st]<< endl;
        }
    }
    return 0;
}