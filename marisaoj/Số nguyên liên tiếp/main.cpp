/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
long long n;

int main(){
    cin >> n;
    a = vector<long long>(n);
    for(long long &d : a) 
        cin >> d;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    long long ans = 0;
    for(long long &d : a){
        ans = max(ans, (long long)(upper_bound(a.begin(), a.end(), d + n - 1) - lower_bound(a.begin(), a.end(), d)));
    }
    cout << n - ans;
}
