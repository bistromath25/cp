#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int N;
int dp[501][130000];  // dp[i][x] = number of ways to make sum x using subset of first i numbers

// dp[i][x] = dp[i - 1][x] + dp[x - 1][x - i];

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N;
    int target = N * (N + 1) / 2;  // current sum of first N natural numbers
    if (target % 2 == 1) {  // if the sum is odd, can't split into two equal groups
        cout << "0\n";
        return 0;
    }
    target /= 2;  // sum of each group

    dp[0][0] = 1;  // can make sum of 0 using first 0 numbers

    for (int i = 1; i < N; ++i) {
        for (int x = 0; x <= target; ++x) {  // consider each possible sum up till target
            dp[i][x] = dp[i - 1][x];
            if (x - i >= 0) {  // try to include i
                dp[i][x] += dp[i - 1][x - i];
                dp[i][x] %= mod;
            }
        }
    }

    cout << dp[N - 1][target] << '\n';

    return 0;
}
