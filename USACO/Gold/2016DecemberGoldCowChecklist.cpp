#include <bits/stdc++.h>
using namespace std;

#define int long long

const long long INF = 1e18;
const int MAXN = 1001;
int H, G;
vector<pair<int, int>> hcows(MAXN), gcows(MAXN);  // locations of cows
int dp[2][MAXN][MAXN];
// dp[0][i][j] = min cost to visit i hcows and j gcows ending with an hcow
// dp[1][i][j] = min cost to visit i hcows and j gcows ending with an gcow

int energy(const pair<int, int> &a, const pair<int, int> &b) {  // energy for moving between two points/cows
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

signed main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    cin >> H >> G;
    hcows.resize(H);
    gcows.resize(G);
    for (int i = 0; i < H; ++i) {
        cin >> hcows[i].first >> hcows[i].second;
    }
    for (int i = 0; i < G; ++i) {
        cin >> gcows[i].first >> gcows[i].second;
    }

    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= G; ++j) {
            dp[0][i][j] = INF;  // initialize dp
            dp[1][i][j] = INF;
        }
    }

    dp[0][1][0] = 0;  // farmer starts at the first holstein cow, cost is 0

    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= G; ++j) {
            if (i && j) {
                int e = energy(hcows[i - 1], gcows[j - 1]);
                // go from gcows[j - 1] to hcows[i - 1]
                dp[0][i][j] = min(dp[0][i][j], dp[1][i - 1][j] + e);
                // go from hcows[i - 1] tp gcows[j - 1]
                dp[1][i][j] = min(dp[1][i][j], dp[0][i][j - 1] + e);
            }

            if (i > 1) {
                int e = energy(hcows[i - 2], hcows[i - 1]);
                // go from hcows[i - 2] to hcows[i - 1]
                dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j] + e);
            }

            if (j > 1) {
                int e = energy(gcows[j - 2], gcows[j - 1]);
                // go from gcows[j - 2] to gcows[j - 1]
                dp[1][i][j] = min(dp[1][i][j], dp[1][i][j - 1] + e);
            }
        }
    }

    cout << dp[0][H][G] << '\n';

    return 0;
}
