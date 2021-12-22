#include <bits/stdc++.h>
using namespace std;

int M, N, ans = 0;
string names[101];
int times[101], dp[101], group[101];

int main() {

    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        string name;
        int t;
        cin >> name >> t;
        v.push_back({name, t});
    }

    for (int i = 0; i <= N; ++i) {
        dp[i] = 1e9;
        group[i] = -1;
    }

    dp[0] = 0;
    group[0] = 0;

    for (int i = 0; i <= N; ++i) {
        int t = 0;
        for (int m = 1; m <= M && i + m - 1 < N; ++m) {
            t = max(t, times[i + m - 1]);
            if (dp[i] + t < dp[i + m]) {
                dp[i + m] = dp[i] + t;
                group[i + m] = m;
            }
        }
    }

    cout << dp[N] << '\n';

    int ans[101];
    int k = N, x = 0;
    while (group[k] != 0) {
        ans[x++] = group[k];
        k -= group[k];
    }

    int c = 0;
    for (int i = x - 1; i >= 0; --i) {
        for (int j = 0; j < ans[i]; ++j) {
            cout << name[c++] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
