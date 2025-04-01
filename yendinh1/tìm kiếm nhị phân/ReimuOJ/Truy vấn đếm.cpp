/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "main"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
int lower(vector<int> a,int x){
    int l=0,r=a.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int upper(vector<int> a,int x){
    int l=0,r=a.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> a(1e5 + 1);
    for(int i =1;i<=n;i++){
        int k;
        cin >> k;
        a[k].pb(i);
    }
    while(q--){
        int l ,r,x;
        cin >> l >> r >> x;
        vector<int> s=a[x];
        int i = lower(s,l);
        int j = upper(s,r);
        cout << j-i << '\n';
    }

    return 0;
}
