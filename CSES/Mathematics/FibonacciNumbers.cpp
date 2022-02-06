#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

template <typename T, int MOD>
inline T fibonacci(T n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }

    int a = 0;
    int b = 1;

    long long i = 1LL;
    while ((i << 1) <= n) {
        i <<= 1;
    }

    for (i >>= 1; i; i >>= 1) {
        int na = (1LL * a * a + 1LL * b * b) % MOD;
        int nb = (int) ((2LL * a + b) * b % MOD);
        a = na;
        b = nb;

        if (n & i) {
            int c = a + b;
            if (c >= MOD) {
                c -= MOD;
            }
            a = b;
            b = c;
        }
    }

    return b;
}

int main() {
    //freopen("input.in", "r", stdin);
    long long n;
    cin >> n;
    cout << fibonacci<long long, MOD>(n) << '\n';
    return 0;
}
