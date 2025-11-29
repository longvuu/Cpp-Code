/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MAXRANGE"
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
ll n,q;
vector<ll> a;
bool kt=false,kt1=false;
vector<ll> b;
const int N = 1e6 + 5;
const int LOG = 21;
ll st[N][LOG];
int logg[N];
void pre() {
    logg[0]=0;
    logg[1]=0;
    for(int i=2;i<N;i++)
        logg[i]=logg[i/2]+1;
    for(int i=1;i<=n;i++)
        st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

ll xuly(ll l, ll r){
    int len = (r - l + 1);
    int k = logg[len];
    return max(st[l][k], st[r - (1<<k) + 1][k]);
}

vector<ll> seg;
void seg_init(int _n) {
    seg.assign(4*_n + 5, LLONG_MIN);
}
void build(int id,int l,int r) {
    if(l == r){ 
        seg[id] = a[l]; 
        return; 
    }
    int m = (l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    seg[id] = max(seg[id<<1],seg[id<<1|1]);
}
void update(int id, int l, int r, int pos, ll val) {
    if(l==r){ 
        seg[id]=val; 
        return; 
    }
    int m = (l+r)>>1;
    if (pos<=m) update(id<<1,l,m,pos,val);
    else update(id<<1|1,m+1,r,pos,val);
    seg[id]=max(seg[id<<1],seg[id<<1|1]);
}
ll query(int id, int l, int r, int L, int R) {
    if(R<l||r<L) return LLONG_MIN;
    if(L<=l&&r<=R) return seg[id];
    int m=(l+r)>>1;
    return max(query(id<<1, l, m, L, R),query(id<<1|1, m+1, r, L, R));
}
void sub1(){
    while(q--){
        ll i,l,r;
        cin >> i >> l >> r;
        if(i==1) a[l]=r;
        else{
            ll k =*max_element(a.begin()+l,a.begin()+r+1);
            cout << k << '\n';
        }
    }
}
void sub2(){
    b.resize(n+2,0);
    b[1]=a[1];
    for(ll i =1;i<=n;i++){
        b[i]=max<ll>(b[i-1],a[i]);
    }
    while(q--){
        ll i,l,r;
        cin >> i >> l >> r;
        if(i==1) kt1=true;
        if(l!=1) kt=true;
        if(kt==true||kt1==true) return;
        cout << b[r] << '\n';
    }
}
void sub3(){
    while(q--){
        ll i,l,r;
        cin >> i >> l >> r;
        if(i==1) kt1=true;
        if(kt1==true) return;
        cout << xuly(l,r) << '\n';
    }
}
void sub4(){
    seg_init(n);
    build(1, 1,n);
    while(q--){
        ll i,l,r;
        cin >> i >> l >> r;
        if(i==1){
            a[l]=r;
            update(1, 1, n, l, r);
        } else {
            if(l>r) swap(l,r);
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> q;
    a.resize(n+1);
    for(ll i =1;i<=n;i++) cin >> a[i];
    pre();
    if(n<=1000){
        sub1();
    }else{
        sub2();
        if(kt==true&&kt1==false)
            sub3();
        else
            sub4();
    }
    return 0;
}