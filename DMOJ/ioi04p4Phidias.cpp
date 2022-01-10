#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600;
int W, H, N;
int dp[MAXN + 1][MAXN + 1];  // dp[i][j] = min area wasted with a plate of width i, height j
int w[MAXN + 1], h[MAXN + 1];  // width and height of individual plates

int main() {

    cin >> W >> H >> N;

    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> h[i];
    }

    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            dp[i][j] = i * j;
        }
    }

    for (int i = 0; i < N; ++i) {
        dp[w[i]][h[i]] = 0;
    }

    for (int i = 1; i <= W; ++i) {
        for (int j = 1; j <= H; ++j) {
            for (int x = 1; x <= i; ++x) {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for (int y = 1; y <= j; ++y) {
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        }
    }

    cout << dp[W][H] << '\n';
    return 0;
}
