/**

 *    author:       _longvu
**/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,dem=0;
bool check(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int main()
{
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
  for(ll i = 0; i < n; i++) {
    if(check(a[i])){
        dem++;
    }
  }

  cout << dem << endl;
  return 0;
}