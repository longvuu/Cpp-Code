/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "TONGUOC"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n; 
vector<ll> a;
void TRAU(){
    for(ll i=0;i<n;i++){
        ll x=a[i];
        ll s=0;
        for(ll d=1;d*d<=x;d++){
            if(x%d==0){
                s+=d;
                if(d*d!=x) s+=x/d;
            }
        }
        if(i) cout<<' ';
        cout<<s;
    }
    cout<<'\n';
}

void FULL(){
    if(n==0){cout<<'\n';return;}
    bool ok=true;
    for(ll i=1;i<n;i++){
        if(a[i]!=a[i-1]+1){ok=false;break;}
    }
    ll s=0;
    for(ll x:a) if(x>s) s=x;
    ll r;
    if(ok){
        r=a[0]+n-1;
    } else {
        r=s;
    }
    ll m=sqrt((long double)r);
    vector<ll> primes; primes.reserve(m/10+10);
    if(m>=2){
        vector<bool> isPrime(m+1,true);
        isPrime[0]=isPrime[1]=false;
        for(ll p=2;p*p<=m;p++){
            if(isPrime[p]){
                for(ll q=p*p;q<=m;q+=p) isPrime[q]=false;
            }
        }
        for(ll p=2;p<=m;p++) if(isPrime[p]) primes.pb(p);
    }
    if(ok){
        ll l=a[0];
        vector<ll> a(n),b(n,1);
        for(ll i=0;i<n;i++) a[i]=l+i;
        if(l==1){b[0]=1;}

        for(ll p:primes){
            ll prime=p;
            ll t=((l+prime-1)/prime)*prime;
            for(ll m=t;m<=r;m+=prime){
                ll i=m-l;
                ll dem=0;
                while(a[i]%prime==0){
                    a[i]/=prime;
                    dem++;
                }
                if(dem){
                    ll c=1,d=1;
                    for(ll k=0;k<dem;k++){d*=prime;c+=d;}
                    b[i]*=c;
                }
            }
        }
        for(ll i=0;i<n;i++){
            if(a[i]>1) b[i]*=(a[i]+1);
            if(i) cout<<' ';
            cout<<b[i];
        }
        cout<<'\n';
        return;
    }
    for(ll i=0;i<n;i++){
        ll x=a[i];
        ll k=x;
        ll sum=1;
        for(ll p:primes){
            ll prime=p;
            if(prime*prime>k) break;
            if(k%prime==0){
                ll f=1,pp=1;
                while(k%prime==0){
                    k/=prime;
                    pp*=prime;
                    f+=pp;
                }
                sum*=f;
            }
        }
        if(k>1) sum*=(k+1);
        if(i) cout<<' ';
        cout<<sum;
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    cin >> n;
    a.resize(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    FULL();
    return 0;
}