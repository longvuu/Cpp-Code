// https://lqdoj.edu.vn/problem/strcnt
/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        map<char,int>b;
        string s;int k;
        cin>>s>>k;
        int dem=0,ans=0;
        for (int l=0,r=0;r<s.size();r++)
        {
            if (b[s[r]]==0)
            {
                b[s[r]]=1;
            }
            else b[s[r]]++;
            while (b[s[r]] > k)
            {
                b[s[l]]--;
                if (b[s[r]]==k)
                {
                    dem--;
                }
                l++;
            }
            ans+=r-l+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}