#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1e5, MAXK = 10;
int N, M, K;
vector<pair<int, int>> g[MAXN + 1];
vector<vector<long long>> dist;

void dijkstra(int x) {
    dist.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        dist[i].resize(K);
        for (int j = 0; j < K; ++j) {
            dist[i][j] = INF;
        }
    }

    dist[x][0] = 0;

    priority_queue<pair<long long, int>> q;
    q.push({0, x});

    while (!q.empty()) {
        int cur = q.top().second;
        long long curd = q.top().first;
        q.pop();
        if(dist[cur][K - 1] < curd) continue;

        for (const pair<int, long long> &e : g[cur]) {
            int nxt = e.first;
            long long w = e.second;
            if (dist[nxt][K - 1] > curd + w) {
                dist[nxt][K - 1] = curd + w;
                sort(dist[nxt].begin(), dist[nxt].end());
                q.push({-dist[nxt][K - 1], nxt});
            }
        }
    }
}

int main() {
    freopen("input.in", "r", stdin);

    cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    dijkstra(1);

    for (int i = 0; i < K; ++i) {
        cout << dist[N][i] << '\n';
    }

    return 0;
}
