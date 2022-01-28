#include <bits/stdc++.h>
using namespace std;

const int N = 100, X = 1e6;
const int MOD = 1e9 + 7;
vector<int> coins(N, 0);
vector<int> dp(X + 1, 0);  // dp[i] = number of ways to make sum i
int n, x, ans = 0;

int main() {
    cin >> n >> x;
    coins.resize(n);
    dp.resize(x);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    dp[0] = 1;  // 1 way to make sum x = 0
    for (int j = 0; j < n; ++j) {  // for all the coins
        for (int i = 1; i <= x; ++i) {  // for all possible values i from 1 to x
            if (i - coins[j] >= 0) {
                // if i - coin >= 0 then
                // add the number of ways
                // to make sum of i - coin
                dp[i] += dp[i - coins[j]];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x] << '\n';
    return 0;
}

