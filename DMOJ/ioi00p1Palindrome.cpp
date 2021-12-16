#include <bits/stdc++.h>
using namespace std;

int solve(string s, int n) {
    if (n == 1) return 0;
    int a, b, gap;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (gap = 1; gap < n; ++gap) {
        for (a = 0, b = gap; b < n; ++a, ++b) {
            if (s[a] == s[b]) {
                dp[a][b] = dp[a + 1][b - 1];
            }
            else {
                dp[a][b] = min(dp[a][b - 1], dp[a + 1][b]) + 1;
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    freopen("input.in", "r", stdin);
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s, n) << '\n';
    return 0;
}
