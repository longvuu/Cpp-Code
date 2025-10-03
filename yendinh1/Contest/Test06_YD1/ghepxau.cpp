/*
    @author longvuuuu
    Sửa lại: Thuật toán trước bỏ sót trường hợp tâm nằm sâu bên trong X hoặc Y.
    Phân tích mới:
    A + B là palindrome (A substring X, B substring Y) <=> tồn tại t sao cho
       A = pre + Pal  (Pal là palindrome, có thể rỗng) và B = reverse(pre).
    => Tổng độ dài = |Pal| + 2*|pre|.
    Với Pal là một palindromic suffix của A (bắt đầu tại s, kết thúc tại r), pre = X[l..s-1].
    Đặt s > 0: cần reverse(X[l..s-1]) là substring của Y. Tối đa hóa |Pal| + 2*|pre|.
    Ta nhận được công thức (sau khi đổi biến) với Pal bắt đầu tại s:
        best = bestPalStartX[s] + 2 * LmatchXend[s-1]
    Trong đó LmatchXend[e] = độ dài lớn nhất substring của X kết thúc tại e nằm trong Y_rev.
    (Y_rev = reverse(Y)).
    Trường hợp Pal rỗng (even qua biên) chính là 2*L, L = LCS substr (X, Y_rev).
    Làm đối xứng cho phía Y: chọn palindrome prefix của B rồi nối reverse(suffix).

    Các bước:
      1. Manacher cho X và Y để lấy longest palindrome bắt đầu tại mỗi vị trí (bestStartX, bestStartY).
      2. Xây suffix automaton (SAM) cho Y_rev, quét X để lấy LmatchXend (longest match ending at mỗi e).
      3. Xây SAM cho X_rev, quét Y để lấy LmatchYend; từ đó suy ra matchStartYpos (longest match starting tại pos).
      4. Tính ứng viên:
            res = max( maxPal(X), maxPal(Y), 2*max(LmatchXend),
                        max_s>0 bestStartX[s] + 2*LmatchXend[s-1],
                        max_end prefixPal ở Y + 2*matchStartYpos[end+1] ).
*/
#include <bits/stdc++.h>
#define taskname "GHEPXAU"
#define ll long long
using namespace std;

struct SAM {
    struct Node { int next[26]; int link; int len; Node(){ fill(begin(next), end(next), -1); link=-1; len=0;} };
    vector<Node> st; int last;
    SAM(int maxLen=0){ st.reserve(2*maxLen+5); st.push_back(Node()); last=0; }
    void extend(char ch){
        int c = ch-'a';
        int cur = (int)st.size(); st.push_back(Node()); st[cur].len = st[last].len + 1;
        int p = last;
        while(p!=-1 && st[p].next[c]==-1){ st[p].next[c]=cur; p=st[p].link; }
        if(p==-1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if(st[p].len +1 == st[q].len) st[cur].link = q;
            else {
                int clone = (int)st.size(); st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                while(p!=-1 && st[p].next[c]==q){ st[p].next[c]=clone; p=st[p].link; }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};

// Manacher: trả về (maxPal, bestStart[length])
static int manacherStart(const string &s, vector<int> &bestStart){
    int n = (int)s.size();
    bestStart.assign(n, 1); // ít nhất độ dài 1
    int best=1;
    // odd
    vector<int> d1(n); int l=0,r=-1;
    for(int i=0;i<n;i++){
        int k = (i>r)?1:min(d1[l+r-i], r-i+1);
        while(i-k>=0 && i+k<n && s[i-k]==s[i+k]) k++;
        d1[i]=k;
        int len = 2*k-1; int start=i-(k-1); bestStart[start]=max(bestStart[start], len); best=max(best,len);
        if(i+k-1>r){ l=i-k+1; r=i+k-1; }
    }
    // even
    vector<int> d2(n); l=0; r=-1;
    for(int i=0;i<n;i++){
        int k = (i>r)?0:min(d2[l+r-i+1], r-i+1);
        while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]) k++;
        d2[i]=k;
        int len = 2*k; if(len){ int start=i-k; bestStart[start]=max(bestStart[start], len); best=max(best,len);}        
        if(i+k-1>r){ l=i-k; r=i+k-1; }
    }
    return best;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen((string(taskname)+".inp").c_str(), "r")!=NULL){
        freopen((string(taskname)+".inp").c_str(), "r", stdin);
        freopen((string(taskname)+".out").c_str(), "w", stdout);
    }
    string X,Y; if(!(cin>>X)) return 0; cin>>Y;
    int n = X.size(), m = Y.size();

    // 1) Palindromes inside X and Y
    vector<int> bestStartX, bestStartY;
    int best = 0;
    best = max(best, manacherStart(X, bestStartX));
    best = max(best, manacherStart(Y, bestStartY));

    // 2) SAM for Y_rev to get longest matches ending at each pos in X
    string Yrev = Y; reverse(Yrev.begin(), Yrev.end());
    SAM samY(m);
    for(char c: Yrev) samY.extend(c);
    vector<int> matchEndX(n,0);
    int v=0, lcur=0;
    for(int i=0;i<n;i++){
        int c = X[i]-'a';
        if(samY.st[v].next[c]!=-1){ v = samY.st[v].next[c]; lcur++; }
        else {
            while(v!=-1 && samY.st[v].next[c]==-1) v=samY.st[v].link;
            if(v==-1){ v=0; lcur=0; }
            else { lcur = samY.st[v].len +1; v = samY.st[v].next[c]; }
        }
        matchEndX[i]=lcur; // longest length ending at i
    }
    int maxEvenAcross = 0; for(int len: matchEndX) if(len>maxEvenAcross) maxEvenAcross=len; best = max(best, 2*maxEvenAcross);

    // Contribution from centers inside X (non-trivial): bestStartX[s] + 2*matchEndX[s-1]
    for(int s=1;s<n;s++){ // s>0
        if(matchEndX[s-1]>0){
            int cand = bestStartX[s] + 2*matchEndX[s-1];
            if(cand>best) best=cand;
        }
    }

    // 3) SAM for X_rev to get longest matches ending at each pos in Y, then derive starting matches.
    string Xrev = X; reverse(Xrev.begin(), Xrev.end());
    SAM samX(n); for(char c: Xrev) samX.extend(c);
    vector<int> matchEndY(m,0);
    v=0; lcur=0;
    for(int i=0;i<m;i++){
        int c = Y[i]-'a';
        if(samX.st[v].next[c]!=-1){ v = samX.st[v].next[c]; lcur++; }
        else {
            while(v!=-1 && samX.st[v].next[c]==-1) v = samX.st[v].link;
            if(v==-1){ v=0; lcur=0; }
            else { lcur = samX.st[v].len +1; v = samX.st[v].next[c]; }
        }
        matchEndY[i]=lcur;
    }
    // Build matchStartYpos[pos] = longest substring starting at pos appearing in X_rev
    vector<int> matchStartY(m,0);
    for(int end=0; end<m; ++end){
        int L = matchEndY[end];
        int start = end - L + 1;
        if(L>0 && start>=0) matchStartY[start] = max(matchStartY[start], L);
    }
    // Optionally propagate decreasing lengths (not needed for maximizing t because we use longest only)

    // Contribution from centers inside Y: prefix palindrome ending at s plus 2*matchStartY[s+1]
    for(int start=0; start<m; ++start){
        int palLen = bestStartY[start];
        int end = start + palLen -1;
        if(end+1 < m && matchStartY[end+1]>0){
            int cand = palLen + 2*matchStartY[end+1];
            if(cand>best) best = cand;
        }
    }

    cout << best << '\n';
    return 0;
}
