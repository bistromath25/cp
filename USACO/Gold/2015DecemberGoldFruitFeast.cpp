#include <bits/stdc++.h>
using namespace std;

const int T = 5e6;
int t, a, b;
int dp[2][T];
// dp[0][t] = true if can get t fullness without drinking
// dp[1][t] = true if can get t fullness with drinking

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin >> t >> a >> b;
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;  // can get 0 fullness by eating nothing
    dp[1][0] = true;

    for (int i = 0; i <= t; ++i) {
        if (i - a >= 0) {
            dp[0][i] |= dp[0][i - a];  // true || true = true, true || false = true
        }
        if (i - b >= 0) {
            dp[0][i] |= dp[0][i - b];
        }
        dp[1][i / 2] |= dp[0][i];
    }

    for (int i = 0; i <= t; ++i) {
        if (i - a >= 0) {
            dp[1][i] |= dp[1][i - a];
        }
        if (i - b >= 0) {
            dp[1][i] |= dp[1][i - b];
        }
    }

    for (int i = t; i >= 0; --i) {
        if (dp[1][i]) {  // always best to drink, since that decreases fullness by half
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
