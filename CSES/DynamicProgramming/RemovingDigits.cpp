#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int dp[N + 1];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1e9;
        int j = i;
        while (j) {
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
            j = j / 10;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
