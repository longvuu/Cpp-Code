/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "DIGITSUM"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

string tinh(string a,string b) {
    int i = a.size() - 1, j = b.size() - 1, k = 0;
    string s;
    while (i >= 0 || j >= 0 || k) {
        int sum = k;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        s.pb(char('0' + (sum % 10)));
        k = sum / 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        int s[10] = {0};
        for (int i=0,d;i<n;i++){ 
            cin >> d; 
            s[d]++; 
        }
        string a, b;
        for(int d = 1; d <= 9; d++) 
            if(s[d]) { 
                a.pb('0' + d); 
                s[d]--; 
                break; 
            }
        
        for(int d = 1; d <= 9; d++) 
            if(s[d]) { 
                b.pb('0' + d); 
                s[d]--; 
                break;
            }
        
        bool ok = true; 
        for(int d = 0; d <= 9; d++){
            while(s[d]--) {
                if(ok) 
                    a.pb('0' + d);
                else      
                    b.pb('0' + d);
                ok = !ok;
            }
        }
        cout << tinh(a, b) << "\n";
    }
    return 0;
}