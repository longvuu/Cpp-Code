#include <bits/stdc++.h>
using namespace std;

const int MAX_P = 40;
const long long INF = 1e15;

struct Q {
    enum T { R, A } t;
    long long l, r, k;
    int v;

    Q(long long a, long long b, long long c) : t(R), l(a), r(b), k(c), v(0) {}
    Q(int x) : t(A), l(0), r(0), k(0), v(x) {}
};

long long cnt(long long len, const vector<long long>& p2) {
    return len <= 1 ? 1 : (len - 1 <= MAX_P ? p2[len - 1] : INF);
}

void go() {
    vector<long long> p2(MAX_P + 1, 1);
    for (int i = 1; i <= MAX_P; ++i) p2[i] = p2[i - 1] * 2;

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << (k == 1 ? "1\n" : "-1\n");
            continue;
        }

        long long tot = cnt(n, p2);
        if (k > tot) {
            cout << "-1\n";
            continue;
        }

        vector<Q> stk;
        stk.emplace_back(Q(1, n, k));
        vector<int> res;

        while (!stk.empty()) {
            Q cur = stk.back();
            stk.pop_back();

            if (cur.t == Q::A) {
                res.push_back(cur.v);
            } else {
                long long l = cur.l, r = cur.r, ck = cur.k;

                while (true) {
                    if (l == r) {
                        res.push_back(static_cast<int>(l));
                        break;
                    }

                    long long len = r - l;
                    long long h = cnt(len, p2);

                    if (ck <= h) {
                        res.push_back(static_cast<int>(l));
                        l++;
                    } else {
                        stk.emplace_back(static_cast<int>(l));
                        l++;
                        ck -= h;
                    }

                    if (l > r) break;
                    if (l == r) {
                        res.push_back(static_cast<int>(l));
                        break;
                    }
                }
            }
        }

        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    go();
    return 0;
}