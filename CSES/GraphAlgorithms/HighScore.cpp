#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int N = 2501, M = 5001;
int n, m;

struct Edge {  // edge struct
    int a, b;  // to, from
    long long w;  // edge weight
} edges[M];

vector<int> g1[N], g2[N];  // directed graphs containing forward edges and reverse edges
long long dist[N];  // dist[x] = distance from 1 to x
bool vis1[N], vis2[N];  // visited arrays for dfs

void dfs1(int x) {  // dfs moving along forward edges
    if (vis1[x]) return;
    vis1[x] = true;
    for (const int &y : g1[x]) {
        if (!vis1[y]) dfs1(y);
    }
}

void dfs2(int x) {  // dfs moving along reverse edges
    if (vis2[x]) return;
    vis2[x] = true;
    for (const int &y : g2[x]) {
        if (!vis2[y]) dfs2(y);
    }
}

bool bellman_ford(int x, int y) {  // true if no negative cycle along path from a to b, false otherwise
    dfs1(x);
    dfs2(y);

    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[x] = 0;

    bool ok = true;
    for (int i = 1; i <= n && ok; ++i) {
        ok = false;
        for (int e = 0; e < m; ++e) {  // for each edge
            int a = edges[e].a, b = edges[e].b;
            long long w = edges[e].w;
            if (dist[a] + w < dist[b]) {  // update dist if possible
                dist[b] = dist[a] + w;
                ok = true;  // ok should be false if there are no negative cycles, since no updates are being made

                if (i == n) {  // if already run n-1 times, and ok is true (from above)
                    if (vis1[b] && vis2[a]) {  // if visited a and b
                        return false;  // there is a negative cycle
                    }
                }
            }
        }
    }

    return true;  // no negative cycle
}

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].w = -edges[i].w;  // store negative weight, when running bellman-ford
        g1[edges[i].a].push_back(edges[i].b);  // the "negative cycle" will be the "arbitrarily large" score, ie inifinity
        g2[edges[i].b].push_back(edges[i].a);  // push edges into the directed graphs accordingly
    }

    bool b = bellman_ford(1, n);  // do bellman-ford

    if (!b) {
         cout << "-1\n";
    }
    else {
        cout << -dist[n] << '\n';  // remember to flip the sign
    }

    return 0;
}

