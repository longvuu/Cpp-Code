#include <bits/stdc++.h>
using namespace std;

const int Nmax = 5e5 + 5, Lim = 1e6 + 1;

int n;
int a[Nmax], F[Nmax], b[Nmax];
int pr[Lim], cnt[Lim];
void solve(){
    int m = 1;
    F[1] = 1;
    b[1] = a[1];
    for(int i = 2; i <= n; i++){
        F[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
        m = max(m, F[i]);
        b[F[i]] = a[i];
    }

    cout << m;
}
void sub2(){
    int limit = int(sqrt(1e9)) + 1;
    vector<int> primes;
    for(int i = 2; i <= limit; i++)
        if(pr[i] == i) primes.push_back(i);

    for(int idx = 1; idx <= n; idx++){
        int x = a[idx];
        int res = 1;
        for(int p : primes){
            if(1LL * p * p > x) break;
            if(x % p == 0){
                int cnt_pr = 0;
                while(x % p == 0){
                    cnt_pr++;
                    x /= p;
                }
                res *= (cnt_pr + 1);
            }
        }
        if(x > 1) res *= 2;
        a[idx] = res;
    }

    solve();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("DAYSODEP.INP", "r", stdin);
    freopen("DAYSODEP.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sub2();
    return 0;
}
