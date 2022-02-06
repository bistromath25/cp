#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[1000001] = {0};

int main() {

    #ifdef SLOW
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        int s = sqrt(x);
        for (int j = 1; j <= s; ++j) {
            if (x % j == 0) {
                cnt[j]++;
                if (j * j != x) {
                    cnt[x / j]++;
                }
            }
        }
    }

    for (int i = 1000000; i >= 1; --i) {
        if (cnt[i] >= 2) {
            cout << i << '\n';
            return 0;
        }
    }

    assert(false);
    return 0;
    #endif

    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cnt[x]++;
    }

    for (int i = 1000000; i >= 1; --i) {
        int div = 0;
        for (int j = i; j <= 1000000; j += i) {
            div += cnt[j];
        }
        if (div > 1) {
            cout << i << '\n';
            return 0;
        }
    }

    assert(false);

    return 0;
}
