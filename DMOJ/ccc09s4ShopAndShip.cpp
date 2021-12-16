#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
const long long LLINF = 1e18;
int n, t, k, dest;
long long grid[N][N];
long long p[N];

long long ans = LLINF;

long long dist[N];
bool used[N];

int mind(long long dist[], bool used[]) {
    long long mn = LLINF;
    int idx = 0;
    for (int v = 0; v < n; ++v) {
        if (!used[v] && dist[v] <= mn) {
            mn = dist[v];
            idx = v;
        }
    }
    return idx;
}

void dijkstra(int x) {
    for (int i = 0; i < N; ++i) {
        dist[i] = LLINF;
    }
    dist[x] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = mind(dist, used);
        used[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!used[v] && grid[u][v] && dist[u] != LLINF && dist[u] + grid[u][v] < dist[v]) {
                dist[v] = dist[u] + grid[u][v];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = LLINF;
        }
    }
    for (int i = 0, x, y, c; i < t; ++i) {
        cin >> x >> y >> c;
        grid[x - 1][y - 1] = c;
        grid[y - 1][x - 1] = c;
    }
    cin >> k;
    for (int i = 0, x, px; i < k; ++i) {
        cin >> x >> px;
        p[x - 1] = px;
    }
    cin >> dest;
    dest--;

    dijkstra(dest);

    for (int i = 0; i < n; ++i) {
        if (p[i] > 0) {
            ans = min(ans, dist[i] + p[i]);
        }
    }

    cout << ans << '\n';
    return 0;
}
