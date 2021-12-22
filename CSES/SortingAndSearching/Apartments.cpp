#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    int desired[n];
    for (int i = 0; i < n; i++) {
        cin >> desired[i];
    }
    int sizes[m];
    for (int i = 0; i < m; i++) {
        cin >> sizes[i];
    }

    sort(desired, desired + n);
    sort(sizes, sizes + m);

    ll ans = 0;    // no. of satisfied applicants
    ll a = 0, b = 0;    // index in desired[] and sizes[]

    while (a < n && b < m) {
        if (abs(desired[a] - sizes[b]) <= k) {
            ans++;
            a++;
            b++;
        }
        else if (desired[a] - sizes[b] > k) {
            b++;
        }
        else {
            a++;
        }
    }

    cout << ans << '\n';
    return 0;
}
