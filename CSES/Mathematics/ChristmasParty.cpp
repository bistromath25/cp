#include <bits/stdc++.h>
using namespace std;

// count the number of permutations of 1..N where no element remains at its original position
// "derangements"
// D(n) = (n - 1)(D(n - 1) + D(n - 2))

int main() {
    long long N;
    cin >> N;
    vector<long long> dp(N + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (long long i = 3; i <= N; ++i) {
        (dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2])) %= (long long) (1e9 + 7);
    }
    cout << dp[N] << '\n';
    return 0;
}
