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
    string a, b;
    cin >> a >> b;
    string sa = a;
    sort(sa.begin(), sa.end());
    if (sa[0] == '0') {
        int nz = 1;
        while (nz < sa.size() && sa[nz] == '0') {
            nz++;
        }
        if (nz < sa.size()) {
            swap(sa[0], sa[nz]);
        }
    }
    string sc;
    int i = 0, j = 0;
    while (i < sa.size() && j < b.size()) {
        if (sa[i] < b[j]) {
            sc += sa[i++];
        } else if (sa[i] > b[j]) {
            sc += b[j++];
        } else {
            if (i + 1 < sa.size() && j + 1 < b.size() && sa[i + 1] < b[j + 1]) {
                sc += sa[i++];
            } else {
                sc += b[j++];
            }
        }
    }
    while (i < sa.size()) sc += sa[i++];
    while (j < b.size()) sc += b[j++];
    sort(a.rbegin(), a.rend());
    string lc;
    i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            lc += a[i++];
        } else if (a[i] < b[j]) {
            lc += b[j++];
        } else {
            if (i + 1 < a.size() && j + 1 < b.size() && a[i + 1] > b[j + 1]) {
                lc += a[i++];
            } else {
                lc += b[j++];
            }
        }
    }
    while (i < a.size()) lc += a[i++];
    while (j < b.size()) lc += b[j++];
    cout << sc << endl;
    cout << lc << endl;
    return 0;
}