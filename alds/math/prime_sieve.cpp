#include <bits/stdc++.h>
using namespace std;

/* Find primes up to N in O(N*log(log(N))) */

inline vector<bool> eratosthenes_helper(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    if (n >= 4) {
        for (int j = 2 * 2; j <= n; j += 2) {
            primes[j] = false;
        }
    }
    int r = int(sqrt(n));
    for (int i = 3; i <= r; i += 2) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

inline vector<int> eratosthenes(int n) {  // prime numbers [0, n]
    vector<bool> p = eratosthenes_helper(n);
    vector<int> primes;
    if (n >= 2) primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (p[i]) primes.push_back(i);
    }
    return primes;
}

inline vector<bool> eratosthenes_helper(int a, int b) {
    int n = b - a + 1;
    vector<bool> primes(n, true);
    if (a <= 0 && 0 <= b) primes[0] = false;
    if (a <= 1 && 1 <= b) primes[1 - a] = false;
    int r = int(sqrt(b));
    vector<bool> p(r + 1, true);
    if (r >= 4) {
        for (int j = 4; j <= r; j += 2) {
            p[j] = false;
        }
        for (int j = max(4, a + (a & 1)); j <= b; j += 2) {
            primes[j - a] = false;
        }
    }
    for (int i = 3; i <= r; i += 2) {
        if (p[i]) {
            for (int j = i * i; j <= r; j += i) {
                p[j] = false;
            }
            for (int j = max(i * i, ((a + i - 1) / i) * i); j >= 0 && j <= b; j += i) {
                primes[j - a] = false;
            }
        }
    }

    return primes;
}

inline vector<int> eratosthenes(int a, int b) {  // prime numbers [a, b]
    vector<bool> p = eratosthenes_helper(a, b);
    vector<int> primes;
    for (int i = a; i <= b; i++) {
        if (p[i - a]) primes.push_back(i);
    }
    return primes;
}

int main() {

    auto p1 = eratosthenes(100);
    auto p2 = eratosthenes(2, 100);
    auto p3 = eratosthenes(90, 100);

    for (auto x : p1) {
        cout << x << ' ';
    }
    cout << '\n';

    for (auto x : p2) {
        cout << x << ' ';
    }
    cout << '\n';

    for (auto x : p3) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
