/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "XDB"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
string a,b,st;
void TRAU(){
    vector<int> s(256,-2);
    for(char c:a) s[c]=1;
    for(char c:b) s[c]=-1;
    s[' ']=0;
    ll n=st.size();
    ll res=0;
    for(ll i=0;i<n;i++){
        int x=0;
        for(ll j=i;j<n;j++){
            int t=s[st[j]];
            if(t==-2) break;
            if(t==1) x++;
            else if(t==-1) x--;
            if(x==0) res++;
        }
    }
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    cin>>a;cin>>b;
    cin.ignore();
    getline(cin,st);
    TRAU();
    return 0;
}