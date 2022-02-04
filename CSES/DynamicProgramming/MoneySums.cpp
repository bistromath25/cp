#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100, MAXSUM = 1e5;
int N, maxsum;
int coins[MAXN];
bool dp[MAXN + 1][MAXSUM + 1];  // dp[i][x] = true if it's possible to make sum x with first i coins

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N;
    maxsum = 1000 * N;
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int i = 1; i <= N; ++i) {
        for (int sum = 0; sum <= maxsum; ++sum) {
            dp[i][sum] = dp[i - 1][sum];
            int rem = sum - coins[i - 1];
            if (rem >= 0 && dp[i - 1][rem]) {
                dp[i][sum] = true;
            }
        }
    }

    vector<int> ans;
    for (int sum = 1; sum <= maxsum; ++sum) {
        if (dp[N][sum]) ans.push_back(sum);
    }

    cout << ans.size() << '\n';
    for (const int &a : ans) {
        cout << a << ' ';
    }
    cout << '\n';

    return 0;
}
