/*
    @author longvuuuu
    @github kuronight29
*/
#include <bits/stdc++.h>
#define taskname "CAU3"
#define ll long long
#define fi first
#define se second
#define simp main
#define pb push_back
using namespace std;
bool thuong(char c) {
    return c >= 'a' && c <= 'z';
}
bool hoa(char c) {
    return c >= 'A' && c <= 'Z';
}
ll TRAU(string t, string st, ll n, ll m) {
    ll res = 0;
    sort(t.begin(), t.end()); 
    for (ll i = 0; i <= m - n; i++) {
        string s1 = st.substr(i, n); 
        sort(s1.begin(), s1.end());
        if (s1 == t) {
            res++;
        }
    }
    return res;
}
ll FULL(string t,string st, ll n, ll m) {
    vector<int> s1(52, 0);
    for (char c : t) {
        if (thuong(c))
            s1[c - 'a']++;
        else if (hoa(c)) 
            s1[c - 'A' + 26]++;
    }
    ll res = 0;
    vector<int> s2(52, 0);
    ll d = 0;
    for (ll j = 0; j < n; j++) {
        if (st[j] == '*') {
            d++;
        } else {
            if (thuong(st[j]))
                s2[st[j] - 'a']++;
            else if (hoa(st[j]))
                s2[st[j] - 'A' + 26]++;
        }
    }
    bool kt = true;
    ll k = 0;
    for (ll j = 0; j < 52; j++) {
        if (s2[j] > s1[j]) {
            kt = false;
            break;
        }
        k += (s1[j] - s2[j]);
    }
    if (kt && k == d) {
        res++;
    }
    for (ll i = 1; i <= m - n; i++) {
        if (st[i - 1] == '*') {
            d--;
        } else {
            if (thuong(st[i - 1]))
                s2[st[i - 1] - 'a']--;
            else if (hoa(st[i - 1]))
                s2[st[i - 1] - 'A' + 26]--;
        }
        if (st[i + n - 1] == '*') {
            d++;
        } else {
            if (thuong(st[i + n - 1]))
                s2[st[i + n - 1] - 'a']++;
            else if (hoa(st[i + n - 1]))
                s2[st[i + n - 1] - 'A' + 26]++;
        }
        kt = true;
        k = 0;
        for (ll j = 0; j < 52; j++) {
            if (s2[j] > s1[j]) {
                kt = false;
                break;
            }
            k += (s1[j] - s2[j]);
        }
        if (kt && k == d) {
            res++;
        }
    }

    return res;
}

int simp() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }

    ll n, m;
    cin >> n >> m;
    string t, st;
    cin >> t >> st;

    if (n < 1000)
        cout << TRAU(t, st, n, m) << endl; 
    else
        cout << FULL(t, st, n, m) << endl; 

    return 0;
}
