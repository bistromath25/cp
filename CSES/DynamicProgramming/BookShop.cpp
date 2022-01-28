#include <bits/stdc++.h>
using namespace std;

const int N = 1000, X = 1e5;
int n, x;
vector<int> prices(N, 0);
vector<int> pages(N, 0);
// dp[i][j] = max. number of pages for price at most j, only buying from among first i books
vector<vector<int>> dp(N, vector<int> (X, 0));

int main() {

    cin >> n >> x;
    dp.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        dp[i].resize(x + 1);
    }
    prices.resize(n);
    pages.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            int rem = j - prices[i - 1];
            if (rem >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][rem] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << '\n';
    return 0;
}

