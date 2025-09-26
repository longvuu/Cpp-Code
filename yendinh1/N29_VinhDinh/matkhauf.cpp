/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "matkhauf"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(),"r")!=NULL){
        freopen((string(taskname)+".inp").c_str(),"r",stdin);
        freopen((string(taskname)+".out").c_str(),"w",stdout);
    }
    string s;
    getline(cin,s);
    int n=s.size();
    int x=-1,y=-1,z=-1;
    ll res=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(isupper(c)) x=i;
        else if(islower(c)) y=i;
        else if(isdigit(c)) z=i;
        if(x!=-1 && y!=-1 && z!=-1){
            int l=min(x,min(y,z));
            int r=min(l,i-5);
            if(r>=0) res+= (ll)r+1;
        }
    }
    cout << res;
    return 0;
}