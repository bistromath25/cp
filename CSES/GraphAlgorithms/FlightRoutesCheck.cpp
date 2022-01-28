#include <bits/stdc++.h>
using namespace std;

/**
Given a directed graph (possibly with cycles) determine if it's
possible to travel between any pair of cities, or provide an
example if that's not the case.

Theorem:
If a certain vertex can reach all other vertices and can also be
reached by all other vertices, then every vertex in this graph
can be reached by all other vertices.

Proof:
Suppose can[x][y] is true if we can travel from x to y. Suppose also
that the given directed graph G has a reversed version G'. Then,
whenever can[1][x], for all x in both G and G', it's possible to
travel between all pairs of vertices.
Assume that can[1][x] is true for all x in both G and G', and that
there exists a pair of vertices {a, b} such that can[a][b] is false.
Since can[1][a] is true in G', then can[a][1] must be true in G.
Furthermore, can[1][b] must be true in G, thus it's possible to travel
from a to 1 to b, hence can[a][b] is true, a contradiction.
*/

const int MAXN = 1e5, MAXM = 2e5;
int N, M;
vector<int> gf[MAXN + 1], gb[MAXN + 1];  // forward, backward (original, reversed)
bool vis[MAXN + 1];

void dfs_gf(int x) {
    if (vis[x]) return;
    vis[x] = true;
    for (const int &y : gf[x]) {
        if (!vis[y]) dfs_gf(y);
    }
}

void dfs_gb(int x) {
    if (vis[x]) return;
    vis[x] = true;
    for (const int &y : gb[x]) {
        if (!vis[y]) dfs_gb(y);
    }
}

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;
    for (int i = 0, a, b; i < M; ++i) {
        cin >> a >> b;
        gf[a].push_back(b);
        gb[b].push_back(a);
    }

    dfs_gf(1);
    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << ' ' << i << '\n';
            return 0;
        }
    }

    memset(vis, 0, sizeof(vis));

    dfs_gb(1);
    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
