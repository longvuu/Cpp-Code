#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> d((N+1) * (N+1), 0);

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            int a;
            cin >> a;            
            d[i * (N+1) + j] = d[(i-1) * (N+1) + j] 

                                   + d[i * (N+1) + (j-1)] 
                                   - d[(i-1) * (N+1) + (j-1)] 
                                   + a;
        }
    }
    int low = 1, high = N, ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        bool ok = 1;
                for(int i = mid; i <= N && ok; ++i){
            for(int j = mid; j <= N && ok; ++j){
                ll tt = d[i * (N+1) + j] 
                                - d[(i - mid) * (N+1) + j] 
                                - d[i * (N+1) + (j - mid)] 
                                + d[(i - mid) * (N+1) + (j - mid)];

                if(tt < K){
                    ok = 0;
                }
            }
        }  
        if(ok){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans;
}
