/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "XCLT"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
string st;
void TRAU(){
    string res;
    for(ll i =0;i<st.size();i++){
        string s;
        s.pb(st[i]);
        if(s.size()>res.size()||(s.size()==res.size())&&s>res) res=s;
        for(ll j=i+1;j<st.size();j++){
            if(st[j]==st[j-1]) break;
            s.pb(st[j]);
            if(s.size()>res.size()||(s.size()==res.size())&&s>res) res=s;
        }
    }
    cout << res;
}

void FULL(){
    string res;
    ll l =0;
    for(ll i=1;i<st.size();i++){
        if(st[i]==st[i-1]){
            string s=st.substr(l,i-l);
            if(s.size()>res.size()||(s.size()==res.size())&&s>res) res=s;
            l=i;
        }
    }
    string s=st.substr(l,st.size()-l);
    if(s.size()>res.size() || ((s.size()==res.size())&&s>res)) res = s;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
 
    cin >> st;
    FULL();
    return 0;
}