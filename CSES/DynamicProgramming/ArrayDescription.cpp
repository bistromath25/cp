#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 100, MOD = 1e9 + 7;
int N, M;
vector<int> x(MAXN);
int dp[MAXN + 1][MAXM + 1];  // dp[i][j] = no. ways to fill array up to index i if x[i] = j

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;
    x.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    memset(dp, 0, sizeof(dp));
    if (x[0] == 0) {
        for (int i = 0; i <= M; ++i) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < N; ++i) {
        if (x[i] == 0) {
            for (int j = 1; j <= M; ++j) {
                for (const int &k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= M) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        else {
            for (const int &k : {x[i] - 1, x[i], x[i] + 1}) {
                if (k >= 1 && k <= M) {
                    dp[i][x[i]] += dp[i - 1][k];
                    dp[i][x[i]] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        ans += dp[N - 1][i];
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}
