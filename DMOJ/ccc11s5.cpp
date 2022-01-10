#include <bits/stdc++.h>
using namespace std;

#define eprintf(args...) fprintf(stdout, args)

const int N = 25, NN = 1 << N;
int n, s = 0;
bool vis[NN];

int main() {
    freopen("input.in", "r", stdin);

    cin >> n;
    s = 0;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s <<= 1;
        s |= x;
    }

    // cout << x << '\n';

    vis[s] = true;

    queue<pair<int, int>> q;
    q.push({s, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == 0) {
            cout << cur.second << '\n';
            // solved = true;
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            if (!((cur.first >> i) & 1)) {
                int x = cur.first | (1 << i);
                int cnt = 0;

                for (int j = 0; j < n; ++j) {
                    if ((x >> j) & 1) cnt++;
                    else {
                        if (cnt >= 4) {
                            for (int k = j - cnt; k < j; ++k) {
                                x &= ~(1 << k);
                            }
                        }
                        cnt = 0;
                    }
                }

                if (cnt >= 4) {
                    for (int j = n - cnt; j < n; ++j) {
                        x &= ~(1 << j);
                    }
                }

                if (!vis[x]) {
                    vis[x] = true;
                    q.push({x, cur.second + 1});
                }
            }
        }
    }

    return 0;
}
