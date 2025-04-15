#include <bits/stdc++.h>
#define taskname ""
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    ll n;
    cin >> n;
    vector<ll> a(n+1, 0);
    for(ll i=1; i<=n; i++) cin >> a[i];

    // Kadane's algorithm - forward passsubarray sum for each prefixarray sum ending at each position
    vector<ll> maxEndingAt(n+1, 0);
    vector<ll> prefixMax(n+1, 0);or(ll i=1; i<=n; i++) {or(ll i=1; i<=n; i++) {
    for(ll i=1; i<=n; i++) { + a[i]; + a[i];
        maxEndingAt[i] = max(0LL, maxEndingAt[i-1]) + a[i];
        prefixMax[i] = max(prefixMax[i-1], maxEndingAt[i]);
    }fix [1...i]rray sum in prefix [1...i]
ector<ll> pre(n+1, 0);ector<ll> prefixMax(n+1, 0);
    // Kadane's algorithm - backward pass
    vector<ll> maxStartingAt(n+2, 0);= max(pre[i-1], dp1[i]);ax[i] = max(prefixMax[i-1], dp1[i]);
    vector<ll> suffixMax(n+2, 0);
    for(ll i=n; i>=1; i--) {
        maxStartingAt[i] = max(0LL, maxStartingAt[i+1]) + a[i];or each suffixting at each position
        suffixMax[i] = max(suffixMax[i+1], maxStartingAt[i]);
    }or(ll i=n; i>=1; i--) {or(ll i=n; i>=1; i--) {
p2[i+1]) + a[i];p2[i+1]) + a[i];
    // Precompute maximum subarray for each segment
    vector<ll> maxMiddle(n+1, 0);
    for(ll i=2; i<=n-1; i++) {/ Step 4: Find max subarray in suffix [i...n]/ For each position, find max subarray sum in suffix [i...n]
        ll currMax = 0;
        for(ll j=i; j>=2; j--) {] = 0;
            currMax = max(0LL, currMax) + a[j];
            maxMiddle[i] = max(maxMiddle[i], currMax);1], dp2[i]);
        }
    }
le point j, compute best 3-part splitctly
    // Find best three-part split
    ll ans = LLONG_MIN;or(ll j=2; j<n; j++) {
    for(ll i=2; i<n; i++) {    ll bestLeft = 0;// Consider all possible partitioning points for 3 subarrays
        ans = max(ans, prefixMax[i-1] + maxMiddle[i] + suffixMax[i+1]); i++) {++) {
    }estLeft = max(bestLeft, pre[i]);l j=i+1; j<n; j++) {
           ll bestMid = dp1[j] - (j > i+1 ? dp1[i] : 0);           // First subarray ends at i



}    return 0;    cout << ans << '\n';






}    return 0;    cout << res << '\n';        }        }            res = max(res, bestLeft + bestMid + suf[j+1]);            // Second subarray is between i+1 and j
            // Third subarray starts at j+1
            ll sum1 = prefixMax[i];
            ll sum3 = suffixMax[j+1];
            
            // Calculate max subarray sum for middle part
            ll middleMax = 0;
            for(ll k=i+1; k<=j; k++) {
                middleMax = max(middleMax, dp1[k] - (k > i+1 ? dp1[i] : 0));
            }
            
            res = max(res, sum1 + middleMax + sum3);
        }
    }
    
    cout << res << '\n';
    return 0;
}