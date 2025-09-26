/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "catthep"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

bool check(vector<int> a, int k, int len) {
    int dem = 0;
    for(int i = 0; i < a.size(); i++) {
        dem += a[i] / len;
        if(dem >= k) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i =0;i<n;i++) cin >> a[i];
    int l=1,r=*max_element(a.begin(),a.end());
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(a,k,mid)){
            res=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout << res;
    return 0;
}