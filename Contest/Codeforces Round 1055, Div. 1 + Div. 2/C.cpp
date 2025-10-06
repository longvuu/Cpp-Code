/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int T; cin >> T;
    while(T--){
        int n,q; cin >> n >> q;
        string s; s.resize(n+1);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){cin >> a[i]; s[i] = char('0'+a[i]);}
        vector<int> pref0(n+1,0), pref1(n+1,0), prefAdj(n+1,0);
        for(int i=1;i<=n;i++){
            pref0[i]=pref0[i-1]+(a[i]==0);
            pref1[i]=pref1[i-1]+(a[i]==1);
            if(i>1) prefAdj[i]=prefAdj[i-1]+(a[i]==a[i-1]); else prefAdj[i]=0;
        }
        while(q--){
            int l,r; cin >> l >> r;
            int c0 = pref0[r]-pref0[l-1];
            int c1 = pref1[r]-pref1[l-1];
            if(c0%3||c1%3){ cout << -1 << '\n'; continue; }
            int len = r-l+1;
            int base = len/3;
            int sameAdj = prefAdj[r]-prefAdj[l];
            if(sameAdj==0) cout << base+1 << '\n'; else cout << base << '\n';
        }
    }
    return 0;
}