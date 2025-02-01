#include <bits/stdc++.h>
#define fopenn(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define compile (1.0 * clock() / CLOCKS_PER_SEC)
using namespace std;
//void debug()
//{            
//            
//}      
const int MX = 5e6 + 5;
bool p[MX];
inline void sieve() 
{
    fill(p, p + MX, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i * i <= MX; ++i) if (p[i]) for (int j = i * i; j <= MX; j += i) p[j] = false;
    
}     
signed main(void)
{
    fopenn("")
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    sieve();
    string s; cin >> s;
    int64_t  d_cnt = 0, mx_p = 0, tmp = 0;
    bool ok = 0;
    for (char c : s) 
    {
        if (isdigit(c)) 
        {
            ++d_cnt;
            tmp = tmp * 10 + (c - '0');
            ok = 1;
        } 
        else 
        {
            if (ok) 
            {
                if (tmp <= MX && p[tmp]) mx_p = max(mx_p, tmp);
                tmp = 0;
                ok = 0;
            }
        }
    }
    if (ok && tmp <= MX && p[tmp]) mx_p = max(mx_p, tmp);
    cout << d_cnt << "\n" << mx_p << "\n";
    cerr << '\n' << "Done in: " << compile << " s\n"; 
    return 0;
}