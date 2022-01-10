#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000 + 10, MAXM = 100 + 10;
int N, M;
int A[MAXN], B[MAXM];
int dp[MAXN][MAXM][MAXM][2];

int solve(int idx, int l, int r, int took) {
    int &x = dp[idx][l][r][took];
    if (x != -1) {
        return x;
    }

    x = 0;

    if (idx == N + 1) {
        if (l <= r) {
            if (took) {
                return x = solve(idx, l + 1, r, 0);
            }
            else {
                return x = B[r] + solve(idx, l, r - 1, 1);
            }
        }
        else {
            return x;
        }
    }

    x = solve(idx + 1, l, r, 0);

    if (took) {
        if (l <= r) {
            x = max(x, A[idx] + solve(idx + 1, l + 1, r, 1));
        }
    }
    else {
        x = max(x, A[idx] + solve(idx + 1, l, r, 1));
        if (l <= r) {
            x = max(x, B[r] + solve(idx, l, r - 1, 1));
        }
    }

    return x;
}

int main() {
    freopen("input.in", "r", stdin);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    cin >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> B[i];
    }

    sort(B + 1, B + M + 1);
    memset(dp, -1, sizeof(dp));

    cout << solve(1, 1, M, 0) << '\n';

    return 0;
}
