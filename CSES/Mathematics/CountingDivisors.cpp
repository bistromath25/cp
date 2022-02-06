#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int max_prime_factor[N];

void fill_max_prime_factor() {
    for (int i = 2; i <= N; ++i) {
        if (max_prime_factor[i] == 0) {
            for (int j = i; j <= N; j += i) {
                max_prime_factor[j] = i;
            }
        }
    }
}

int main() {
    fill_max_prime_factor();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int ans = 1;
        while (x != 1) {
            int p = max_prime_factor[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            ans *= cnt + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}

