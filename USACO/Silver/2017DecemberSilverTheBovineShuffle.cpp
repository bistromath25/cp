#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> to, pos;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    cin >> N;
    to.resize(N + 1);
    pos.resize(N + 1);

    for (int i = 1, x; i <= N; ++i) {
        cin >> x;
        to[x]++;
        pos[i] = x;
    }

    int ans = N;

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (to[i] == 0) {
            ans--;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        to[pos[cur]]--;

        if (to[pos[cur]] == 0) {
            ans--;
            q.push(pos[cur]);
        }
    }

    cout << ans << '\n';

    return 0;
}
