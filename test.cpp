#include <bits/stdc++.h>
#define ll long long 
using namespace std
ll n; 
int main(){
      cin >> n;
      ll a[n+1]
      for(ll i = 1 ; i<= n; i++){
            cin >> a[i];
      }
      for(ll i = 1; i<=n;i++){
          if(a[i] > 0){
               cout <<  i << " ";
            }
          break;
      }
for(ll i = n; i>=0n;i--){
          if(a[i] > 0){
               cout <<  i << " ";
            }
          break;
      }
     
}