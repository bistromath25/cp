#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int solve(const vector<int> &v, vector<int> &s, int n, int sum, const int &target) {
    if (n == 0) {
        if (sum == target) return 1;
        else return 0;
    }

    int res = 0;
    res += solve(v, s, n - 1, sum, target);
    s.push_back(v[n - 1]);
    sum += v[n - 1];
    res += solve(v, s, n - 1, sum, target);
    return res;
}

int main() {
    freopen("input.in", "r", stdin);

    int n, t;
    cin >> n >> t;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> s;
    cout << solve(coins, s, n, 0, t) << '\n';
    return 0;
}
