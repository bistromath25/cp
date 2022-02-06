#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

int main() {

    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1, j; i <= n; i = j) {
        ll q = n / i;
        j = n / q + 1;
        ll x = j - i, y = i + j - 1;
        if (x % 2 == 0) {
            x /= 2;
        }
        else {
            y /= 2;
        }
        x %= M;
        y %= M;
        ans = (ans + q % M * x % M * y % M) % M;
    }

    cout << ans << '\n';

    return 0;
}
