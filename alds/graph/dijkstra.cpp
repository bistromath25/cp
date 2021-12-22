#include <bits/stdc++.h>
using namespace std;

/* Single Source Shortest Path (SSSP) in a graph with no negative edge weights */

const int N = 1e5 + 5;  // number of vertices
const long long LLINF = 1e18;  // maximum distance between two vertices
int n, m;  // number of vertices, edges

vector<pair<int, long long>> g[N];  // the edges are stores as pairs (destination, weight)

long long dist[N];  // distance array
bool vis[N];  // keep track of visited vertices

void dijkstra(int x) {  // x is the starting (source) vertex
    for (int i = 1; i <= n; ++i) {
        dist[i] = LLINF;
    }
    dist[x] = 0;

    // use a priority queue to sort the edge weights
    // negate the edge weights to get the smallest ones first
    priority_queue<pair<long long, int>> q;
    q.push({0, x});

    while (!q.empty()) {
        long long a = q.top().second;
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (const pair<int, long long> &e : g[a]) {  // for each destination
            int b = e.first;
            long long w = e.second;
            if (dist[a] + w < dist[b]) {  // if possible use a shorter path
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});  // investigate this vertex, negate the edge weight
            }
        }
    }

}

int main() {

    cin >> n >> m;  // read input
    for (int i = 0; i < n; ++i) {
        long long a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    dijkstra(1);  // run dijkstra's starting at vertex 1

    // print the dist array
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}

