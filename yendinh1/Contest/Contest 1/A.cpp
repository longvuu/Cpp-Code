// code by phatdev
#include <bits/stdc++.h>
#define maxN int(1e5)
#define taskname ""
#define __PHATDEV signed main()

using ll = long long;
using namespace std;
using uc = unsigned char;
using str = string;
using sstream = stringstream;
template<typename T>
using ltp = function<void(T, T, function<void(T)>)>;
template<typename T>
using vi = vector<T>;
template<typename A, typename B>
using pp = pair<A, B>;
template<typename A, typename B>
using mp = map<A, B>;
template<typename A, typename B>
using ump = unordered_map<A, B>;
template<typename T>
void out(const T& arg) {
    cout << arg;
    return;
}
template<typename T, typename... Args>
void out(const T& arg, const Args&... args) {
    cout << arg;
    out(args...);
    return;
}

template<class T> class __MANAGER {
    private:
        T n;
        vi<int> d;
        ltp<T> rep = [&](T a, T b, function<void(T)> run){
            for(auto i = a; i<=b; ++i) run(i);
        };
        ltp<T> repd = [&](T a, T b, function<void(T)> run){
            for(auto i = a; i>=b; --i) run(i);
        };
        ll inf() const {return(1e18+18);};
        int mx[4]{1, -1, 0, 0};
        int my[4]{0, 0, 1, -1};
    public:
        template<typename U> U solve() {
            return ([&]() {
                cin >> n;
                if(n==0) {
                    out(0, '\n');
                    return;
                }
                if(n==1) {
                    out(1, '\n');
                    return;
                }

                repd(9, 2, [&](int i) {
                    while(n%i==0) {
                        d.push_back(i);
                        n/=i;
                    } 
                });

                if(n>1) {
                    out(-1, '\n');
                    return;
                }

                sort(d.begin(), d.end());
                for(int c: d) out(c);
                out('\n');

                return;
            })();    
        };
};

__PHATDEV {
    int t = 1;
    __MANAGER<ll> manager;
    cin.tie(nullptr) -> sync_with_stdio(false);
    //freopen(taskname".inp", "r", stdin);
    //freopen(taskname".out", "w", stdout);
    while(t--) manager.solve<void>();
    return (0^0);
}