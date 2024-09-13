/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
ll n,k,l=1;
ll N,  A,  B;
int solve(ll N, ll A, ll B) {
    set<ll> a;
    for (ll i = A; i <= B; ++i) {
        for (ll j = i; j <= B; ++j) {
            a.insert(i + j);
        }
    }
    return a.size();
}
int main()
{
    // freopen(taskname".inp", "r", stdin);
    // freopen(taskname".out","w",stdout);
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
    cin >> N >> A >> B;
    cout << solve(N,A,B);
    return 0;
}