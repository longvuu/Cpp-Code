/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "TDX"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
ll n; 
vector<string> a; 
vector<ll> s;
void FULL(){
    s.assign(26,0);
    for(ll i=0;i<n;i++){
        for(char c:a[i]) 
        s[c-'a']++;
    }
    for(int i=0;i<26;i++) 
    if(s[i]%n!=0){ 
        cout<<"NO"<<'\n'; 
        return; 
    }
    cout<<"YES"<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll q; 
    cin>>q;
    while(q--){
        cin>>n;
        a.assign(n,"");
        for(ll i=0;i<n;i++) cin>>a[i];
        FULL();
    }
    return 0;
}