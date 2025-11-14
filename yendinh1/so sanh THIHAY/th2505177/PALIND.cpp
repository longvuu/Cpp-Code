/*
    @github longvuu
*/
#include <bits/stdc++.h>
#define taskname "PALIND"
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
    string st;
    cin >> st;
    ll n=st.size();
    if(st.size()%2!=0){
        int t=n/2;
        string s=st.substr(0,(n/2)-1);
        string s1=st.substr(0,(n/2)-1);
        char k=st[n/2-1];
        int k1=(k-'0')+1;
        if(k1>9) k1=0;
        char k2=(k1+'0');
        reverse(s1.begin(),s1.end());
        string res=s+k2+'0'+k2+s1;
        cout << res;
    }else{
        string s=st.substr(0,(n/2)-1);
        string s1=st.substr(0,(n/2)-1);
        reverse(s1.begin(),s1.end());
        char a=st[n/2-1];
        char b=st[n/2];
        int a1=(a-'0');
        int b1=(b-'0');
        if(a1<b1) a1=b1;
        else if(a1>b1) b1=a1;
        char a2=a1+'0';
        char b2=b1+'0';
        string res;
        res=s+a2+b2+s1;
        cout << res;
    }

    return 0;
}
