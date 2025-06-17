/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
int n,k,x[10000];
void inkq(){
    for(ll i =1;i<=k;i++){
        cout << x[i]<<" ";
    }
    cout << '\n';
}
void quaylui(int i){
    for(ll v =x[i-1]+1;v<=n;v++){
            x[i]=v;
            if(i==k) inkq();
            else
                quaylui(i+1);
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    cin >> n >> k;
    x[0]=0;
    quaylui(1);
    return 0;
}