/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "METEOR"
#define ll long long
using namespace std;
ll n, q;
vector<int> type;   
vector<int> l1, r1;  
vector<ll> v1;      
vector<int> p1;  
vector<ll> a; 
void sub1() {
    for(int i=0;i<q;i++){
        if(type[i]==1) {
            int L=l1[i],R=r1[i];ll v=v1[i];
            for(int j=L;j<=R;j++) a[j]+=v;
        }else{
            int p=p1[i];
            cout << a[p] << '\n';
        }
    }
}
void sub2() {
    vector<ll> d(n+2,0);
    for(int i=0;i<q;i++){
        if(type[i]==1){
            ll L=l1[i],R=r1[i],v=v1[i];
            d[L]+=v;
            if(R<n) d[R+1]-=v;
        }
    }
    a[0]=0;
    for(int i=1;i<=n;i++) a[i]=a[i-1]+d[i];
    for(int i=0;i<q;i++) {
        if (type[i]==2) cout << a[p1[i]] << '\n';
    }
}
vector<ll> seg;
void st_init(int n){
    seg.resize(4*n+5,0); 
}
void update(int id,int l,int r,int L,int R,ll val) {
    if(R<l||r<L) return;
    if(L<=l&&r<=R) { 
        seg[id]+=val; 
        return; 
    }
    int m=(l+r)>>1;
    update(id<<1,l,m,L,R,val);
    update(id<<1|1,m+1,r,L,R,val);
}
ll query(int id, int l, int r, int p, ll c = 0) {
    c+=seg[id];
    if(l==r) return c;
    int m=(l+r)>>1;
    if (p<=m) 
        return query(id<<1,l,m,p,c);
    else        
        return query(id<<1|1,m+1,r,p,c);
}
void sub3() {
    st_init(n);
    for (int i=0;i<q;i++){
        if (type[i]==1)
            update(1,1,n,l1[i],r1[i],v1[i]);
        else
            cout << query(1,1,n,p1[i]) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    a.resize(n + 1, 0);
    type.resize(q);
    l1.resize(q); r1.resize(q); v1.resize(q); p1.resize(q);
    for(int i=0;i<q;i++){
        int t; 
        cin >> t;
        type[i]=t;
        if(t==1){
            ll L,R, v; 
            cin >> L >> R >> v;
            l1[i] = L; r1[i] = R; v1[i] = v;
        }else{
            int p; 
            cin >> p;
            p1[i] = p;
        }
    }
    if(n<=1000){
        sub1();
        return 0;
    }
    bool kt = false;
    bool kt1 = false;
    for(int i=0;i<q;i++){
        if(type[i] == 2) kt = true;
        else if(type[i]==1&&kt){ 
            kt1 = true; 
            break; 
        }
    }
    if (!kt1) sub2();  
    else sub3();
    return 0;
}