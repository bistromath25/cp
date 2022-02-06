#include <bits/stdc++.h>
using namespace std;

/**
 * Fermat's little theorem:
 *   a^{p} = a (mod p)
 * a^{p-1} = 1 (mod p)
 * when p is prime
 */

const int MOD = 1e9 + 7;

int binpow(int a, int b, int m) {
    int c = 1;
    a = a % m;
    while (b) {
        if (b & 1) {
            c = ((long long) c * a) % m;
        }
        a = ((long long) a * a) % m;
        b = b >> 1;
    }
    return (int) c;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = binpow(b, c, MOD - 1);
        int y = binpow(a, x, MOD);
        cout << y << '\n';
    }
    return 0;
}
