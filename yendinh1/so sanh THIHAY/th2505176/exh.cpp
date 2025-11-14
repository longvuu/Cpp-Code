#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int n,l,r;
pair <int,int> p[500005];
//map <int ,int> d;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("exh.inp","r",stdin);
    freopen("exh.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>p[i].f>>p[i].s;
        //d[p[i].f]++;
    }
    if(n<10000)
    {
    	int dem=LLONG_MIN;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
			   //cout<<p[i].f<<' '<<p[j].f<<' '<< p[i].s<<' '<<p[j].s<<' '<<'\n';
               dem=max(dem,(p[i].s+p[j].s-abs(p[i].f-p[j].f)));
            }
        }
        cout<<dem;
    }
    else{
    	vector <int> loi(n+1);
		sort(p+1,p+1+n);
		for(int i=1;i<=n/2;i++){
			//cout<<p[i].f<<' '<< p[i].s<<' '<<'\n';
	        loi.push_back(p[i].f+p[i].s);
		}
		for(int i=n/2+1;i<=n;i++){
			//cout<<p[i].f<<' '<< p[i].s<<' '<<'\n';
	        loi.push_back(-p[i].f+p[i].s);
		}
		sort(loi.rbegin(),loi.rend());
		cout<<loi[0]+loi[1];
    }
    return 0;
}
/*
3
2 3
9 2
4 5
*/
