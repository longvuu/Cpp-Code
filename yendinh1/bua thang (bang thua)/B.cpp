/*
    @author longvuuuu
*/
#include <bits/stdc++.h>
using namespace std;
const int M = 505, N = 505;
const int LGM = 10, LGN = 10;
int a[M][N];
int st[LGM][M][LGN][N];
int n, m, q;

void pre() {
    for (int k = 0; k <= LGM; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            for (int l = 0; l <= LGN; l++) {
                for (int j = 0; j + (1 << l) - 1 < m; j++) {
                    if (k == 0) {
                        if (l == 0) {
                            st[0][i][0][j] = a[i][j];
                        }
                        else {
                            st[0][i][l][j] = min(st[0][i][l - 1][j], st[0][i][l - 1][j + (1 << (l - 1))]);
                        }
                    }
                    else {
                        st[k][i][l][j] = min(st[k - 1][i][l][j], st[k - 1][i + (1 << (k - 1))][l][j]);
                    }
                }
            }
        }
    }
}

int xuly(int x1, int y1, int x2, int y2) {
    int k = __lg(x2 - x1 + 1);
    int l = __lg(y2 - y1 + 1);
    return min({
        st[k][x1][l][y1],
        st[k][x1][l][y2 - (1 << l) + 1],
        st[k][x2 - (1 << k) + 1][l][y1],
        st[k][x2 - (1 << k) + 1][l][y2 - (1 << l) + 1]
    });
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    pre();
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        cout << xuly(x1, y1, x2, y2) << '\n';
    }
    return 0;
}