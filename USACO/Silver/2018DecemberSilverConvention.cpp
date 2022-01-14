#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, M, C;
vector<int> t(MAXN);

bool check(int x) {
    int b = 1;
    int start = t[0], idx = 0;
    for (int i = 1; i < N; ++i) {
        if (t[i] - start > x || i + 1 - idx > C) {
            b++;
            start = t[i];
            idx = i;
        }
    }
    if (b > M) return false;
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> N >> M >> C;
    t.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int l = 0, h = 1e9, m;
    while (l < h) {
        m = (l + h) / 2;
        if (l + 1 == h) {
            if (check(m)) cout << l << '\n';
            else cout << h << '\n';
            return 0;
        }
        if (check(m)) {
            h = m;
        }
        else {
            l = m;
        }
    }

    return 0;
}
