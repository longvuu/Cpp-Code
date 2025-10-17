/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "MORSE"
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int mod=1000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    string s;
    int n;
    cin>>s>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) 
        cin>>a[i];
    vector<string> b;
    map<char,string> c;
    c['A'] = ".-";   c['B'] = "-..."; c['C'] = "-.-."; c['D'] = "-..";  c['E'] = ".";   c['F'] = "..-.";
    c['G'] = "--.";  c['H'] = "...."; c['I'] = "..";   c['J'] = ".---"; c['K'] = "-.-";  c['L'] = ".-..";
    c['M'] = "--";   c['N'] = "-.";   c['O'] = "---";  c['P'] = ".--."; c['Q'] = "--.-"; c['R'] = ".-.";
    c['S'] = "...";  c['T'] = "-";    c['U'] = "..-";  c['V'] = "...-"; c['W'] = ".--"; c['X'] = "-..-";
    c['Y'] = "-.--"; c['Z'] = "--..";
    for(int i=0;i<a.size();i++)
    {
        string w=a[i],m="";
        for(int j=0;j<w.size();j++) 
            m+=c[w[j]];
        b.push_back(m);
    }

    vector<int> dp(s.size()+1,0);
    dp[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            string st=b[j];
            int l=st.size();
            if(i>=l && s.substr(i-l,l)==st) 
                dp[i]=(dp[i]+dp[i-l])%mod;
        }
    }
    cout<<dp[s.size()];
    return 0;
}