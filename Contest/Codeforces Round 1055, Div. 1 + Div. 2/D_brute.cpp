#include <bits/stdc++.h>
using namespace std;

// Canonical key from multiset of ints (sorted non-decreasing)
static string keyFrom(const vector<int>& v){
    string k; k.reserve(v.size()*3);
    for(int x: v){ k.append(to_string(x)); k.push_back(','); }
    return k;
}

unordered_map<string,int> memo;

int solve(vector<int> a){
    bool all1 = true; for(int x: a) if(x!=1){ all1=false; break; }
    if(all1) return 0;
    sort(a.begin(), a.end());
    string k = keyFrom(a);
    if(memo.count(k)) return memo[k];
    int n = a.size();
    int best = INT_MAX;
    // Poby picks an index with a[i] >=2
    for(int i=0;i<n;i++) if(a[i]>=2){
        int old = a[i];
        a[i] = old/2; // floor
        bool afterAll1 = true; for(int x: a) if(x!=1){ afterAll1=false; break; }
        int val;
        if(afterAll1){
            val = 1; // this move ends game
        } else {
            // Rekkles chooses index with >=2 to add 1; if none >=2, he has no legal move but game not ended? Impossible because afterAll1 false means exists >=2.
            int worst = 0; // maximize Poby moves additional (not counting current Poby move)
            bool any=false;
            for(int j=0;j<n;j++) if(a[j]>=2){
                any=true;
                int oldR = a[j];
                a[j] = oldR + 1; // Rekkles increment
                worst = max(worst, solve(a));
                a[j] = oldR;
            }
            if(!any){
                // defensive; shouldn't happen
                worst = 0;
            }
            val = 1 + worst; // include this Poby move
        }
        a[i] = old;
        best = min(best, val);
    }
    if(best==INT_MAX) best = 0; // fallback
    return memo[k]=best;
}

// enumerate all arrays length<=5 with values in [2,8] and print diff from sum floor(log2)
static int flog(int x){ return 31-__builtin_clz(x); }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vals = {2,3,4,5,6,7,8};
    int maxLen = 5;
    vector<int> cur;
    long long total=0;
    function<void()> dfs = [&](){
        if(!cur.empty()){
            int v = solve(cur);
            int sumfl=0; for(int x:cur) sumfl += flog(x);
            int diff = v - sumfl;
            bool has2=false, has3=false; int cntP2m1=0; // count numbers of form 2^k -1
            for(int x:cur){ if(x==2) has2=true; if(x==3) has3=true; if((x & (x+1))==0) { /*x=2^k -1 has all lower bits 1 => (x+1) power of two*/ cntP2m1++; } }
            cout << "["; for(size_t i=0;i<cur.size();++i){ if(i) cout<<' '; cout<<cur[i]; } cout<<"] len="<<cur.size()
                 <<" v="<<v<<" sumfl="<<sumfl<<" diff="<<diff
                 <<" has2="<<has2<<" has3="<<has3<<" cnt(2^k-1)="<<cntP2m1
                 <<"\n";
        }
        if((int)cur.size()==maxLen) return;
        for(int x: vals){ cur.push_back(x); dfs(); cur.pop_back(); }
    };
    dfs();
    return 0;
}
