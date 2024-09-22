#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
int divisorSum[MAX];
int specialNumbers[MAX];

void precompute()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 2 * i; j < MAX; j += i)
        {
            divisorSum[j] += i;
        }
    }
    for (int i = 1; i < MAX; i++)
    {
        specialNumbers[i] = specialNumbers[i - 1] + (divisorSum[i] > i);
    }
}

int countSpecialNumbers(int L, int R)
{
    return specialNumbers[R] - specialNumbers[L - 1];
}

int main()
{
    precompute();
    int Q;
    cin >> Q;
    while (Q--)
    {
        int L, R, X;
        cin >> L >> R >> X;
        cout << countSpecialNumbers(L, R) << endl;
    }
    return 0;
}
