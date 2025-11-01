/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
#define taskname "NGUYENTOKEP"
#define ll long long
#define fi first
#define MOD 1000000007
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 2;
vector<int> primes;
bool isPrime[N];
int res[N];
void sang()
{
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i < N; i++)
        if (isPrime[i])
            primes.pb(i);
}
void xuly()
{
    memset(res, -1, sizeof(res));
    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            long long tich = 1LL * primes[i] * primes[j];
            if (tich >= N)
                break;
            if (res[tich] < tich)
                res[tich] = (int)tich;
        }
    }
    for (int i = 1; i < N; i++)
        if (res[i] < res[i - 1])
            res[i] = res[i - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen((string(taskname) + ".inp").c_str(), "r") != NULL)
    {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    sang();
    xuly();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << res[n] << '\n';
    }
    return 0;
}
