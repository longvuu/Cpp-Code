/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MIN"
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
    int k;
    cin >> k;
    vector<int> s(26,0);
    for(int i =0;i<st.size();i++){
        if(st[i]>='A'&&st[i]<='Z') s[st[i]-'A']++;
        else if(st[i] >='a'&&st[i]<='z') s[st[i]-'a']++;
    }
    while(k>0){
        int m = -1;
        int x = 0;
        for(int j = 0; j < 26; j++){
            if(s[j] > x){
                x = s[j];
                m = j;
            }
        }
        if(x == 0) break;
        s[m]--;
        k--;
    }
    int res=0;
    for(int i =0;i<26;i++) res+=s[i]*s[i];
    cout << res;
    return 0;
}