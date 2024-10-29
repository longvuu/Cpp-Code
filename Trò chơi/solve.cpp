/*
    Contest:
    Problem: Tro Choi
    Author: enderlearningc
*/
#include <bits/stdc++.h>
#define inl inline
#define maxN 500005
#define freopen(tenfile) if(fopen(tenfile".inp","r")){freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define nhanh ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define compile (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
typedef long double ldb;
typedef long long ll;
typedef string str;
inl int chk(const vector<int>& a) 
{
    int ixor = a[1] - a[0];
    for (int i = 2; i < a.size(); i += 2) {
        ixor ^= (a[i + 1] - a[i]);
    }
    return ixor;
}
inl void solve() 
{
    int u;
    cin >> u; 
    while (u--) 
    {
        int n;
        cin >> n;
        int le = (n % 2 != 0) ? 1 : 0;
        vector<int> a(n + le, 0);
        for (int i = le; i < n + le; ++i)
        {
            cin >> a[i];
        }
        int ok = (a.size() == 2) ? (a[1] ^ a[0]) : chk(a);
        if (ok != 0) 
        {
            cout << "TAK" << '\n';  
        }
        else 
        {
            cout << "NIE" << '\n';  
        }
    }
    cerr << '\n' << "Done in: " << compile << " s\n"; 
}

int main()
{
    freopen("")
    nhanh;
    solve();
    return 0;
}