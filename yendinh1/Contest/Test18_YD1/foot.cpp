/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "FOOT"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll m;
    cin>>m;
    vector<ll> c(m+1);
    for(int i=1;i<=m;i++) 
		cin>>c[i];
    ll t=0;
    for(int i=1;i<=m;i++)
	{
        ll x=c[i];
        if(i>=2) 
			x=min(x,c[i-1]);
        if(i>=3) 
			x=min(x,c[i-2]);
        t+=2*x;
    }
    cout<<t;
    return 0;
}