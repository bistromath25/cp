#include <bits/stdc++.h>
using namespace std;

// distribute `m` apples (balls) to `n` (identical) children (buckets)
// answer is the number of equations to
// x_1 + x_2 + x_3 + ... + x_n = m
// where x_i is nonnegative
// apply "stars and bars" theorem 2

const long long MOD = 1e9 + 7;
long long n, m;
long long fact[(int) (2e6 + 1)];

long long pow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) {
            (res *= a) %= MOD;
        }
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long int i) {
    if (i == 1) return 1;
    return (MOD - ((MOD / i) * inv(MOD % i)) % MOD + MOD) % MOD;
}

int main() {
    cin >> n >> m;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= (int) (2e6); ++i) {
        (fact[i] = fact[i - 1] * i) %= MOD;
    }
    long long ans = (fact[m + n - 1] * inv(fact[n - 1])) % MOD;
    ans *= inv(fact[m]);
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}
