#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    ll n,res=0,t=0;
    cin >> n;
    if(n<10){
        res=n;
    }else if(n<100){
        res=(n-9)*2+9;
    }else if(n<1000){
        res=(n-99)*3+90*2+9;
    }else if(n<10000){
        res=(n-999)*4+900*3+90*2+9;
    }else if(n<100000){
        res=(n-9999)*5+9000*4+900*3+90*2+9;
    }else if(n<1000000){
        res=(n-99999)*6+90000*5+9000*4+900*3+90*2+9;
    }else if(n<10000000){
        res=(n-999999)*7+900000*6+90000*5+9000*4+900*3+90*2+9;
    }else if(n<100000000){
        res=(n-9999999)*8+9000000*7+900000*6+90000*5+9000*4+900*3+90*2+9;
    }else if(n<1000000000){
        res=(n-99999999)*9+90000000*8+9000000*7+900000*6+90000*5+9000*4+900*3+90*2+9;
    }
    cout << res;
    return 0;
}
