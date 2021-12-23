/* Bellman-Ford Single Source Shortest Path (SSSP) in a graph with negative edge weights */

 struct Edge {
    int a, b, w;  // from, to, weight
 };

 int dist[n];

 void bellman_ford(int x) {
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;  // some really big initial value
    }
    dist[x] = 0;
    
    for (int i = 1; i <= n - 1; ++i) {  // run n - 1 times
        for (auto e : edges) {  // go through all the edges
            dist[e.b] = min(dist[e.b], dist[e.a] + e.w);  // attempt to reduce the distances
        }
    }
     
    for (auto e : edges) {  // check for negative cycle
        if (dist[e.a] != LLINF && dist[e.a] + e.b < dist[e.b]) {  // if this path can be further improved
            cout << "negative cycle\n";  // there must be a negative weight cycle
            return;
        }
    }
    
    cout << "no negative cycle\n";
}
