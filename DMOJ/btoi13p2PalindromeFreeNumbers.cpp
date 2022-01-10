#include <bits/stdc++.h>
using namespace std;

int digits[19];
long long dp[10][10][20][2];
string s;

long long solve(int first, int second, int len, bool all) {
    if (len >= s.length()) {
        return 1;
    }

    else {
        if (dp[first][second][len][all] == -1) {
            long long t = 0;

            if (all) {
                for (int digit = 0; digit <= 9; ++digit) {
                    if (digit != first && digit != second) {
                        t += solve(second, digit, len + 1, true);
                    }
                }
            }

            else {
                int lim = s[len] - '0';
                for (int digit = 0; digit < lim; ++digit) {
                    if (digit != first && digit != second) {
                        t += solve(second, digit, len + 1, true);
                    }
                }
                if (lim != first && lim != second) {
                    t += solve(second, lim, len + 1, false);
                }
            }

            dp[first][second][len][all] = t;
        }

        return dp[first][second][len][all];
    }
}


long long solve(long long x) {
    if (x < 0) {
        return 0;
    }
    else {
        memset(dp, -1, sizeof(dp));
        s = to_string(x);

        int first = s[0] - '0';
        long long result = 1;

        for (int digit = 1; digit <= first; ++digit) {
            result += solve(digit, digit, 1, digit != first);
        }

        for (int i = 2; i <= s.length(); ++i) {
            for (int digit = 1; digit <= 9; ++digit) {
                result += solve(digit, digit, i, true);
            }
        }

        return result;
    }
}

int main() {
    long long a, b;
    cin >> a >> b;
    assert(a <= b);
    cout << solve(b) - solve(a - 1) << '\n';
    return 0;
}
