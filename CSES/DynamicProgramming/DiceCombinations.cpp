#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6, M = 1e9 + 7;
int dp[N + 1] = {0};
int n;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    // 1 2 3 4 5 6
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;  // 1 + 1 or 2
 
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; i - j >= 0 && j <= 6; ++j) {
            dp[i] += dp[i - j];
            dp[i] %= M;
        }
    }
  
    cout << dp[n] << '\n';
 
    return 0;
}
