#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;
    while (b) {
        if (b & 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1;
    }
    return result;
}

long long inv(long long a, long long m) {
    return binpow(a, m - 2, m);
}

int main() {
    freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    long long ans = 1, cur = 1;
    for (int i = 1; i <= N; ++i) {
        cur *= 2;
        ans += cur;
        cur %= MOD;
        ans %= MOD;
    }

    long long half = 1;
    for (int i = N + 1; i <= 2 * N; ++i) {
        cur = (2 * cur - 2 * half) % MOD;
        ans = (ans + cur) % MOD;

        half = (half * i) % MOD;
        half = (half * inv(i - N, MOD)) % MOD;
    }

    cout << (ans + MOD) % MOD << '\n';

    return 0;
}
