/**
 * Floyd-Warshall algorithm, determines all pairs shortest path
 * Graph edges stored as adjacency matrix
 * Reduce the distance by using intermediate nodes
 * Time complexity: O(n^3) - only use if the number of vertices is small
 */

// initialize dist array using edge values from adj matrix
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (i == j) {
            dist[i][j] = 0;
        }
        else if (adj[i][j]) {
            dist[i][j] = adj[i][j];
        }
        else {
            dist[i][j] = INF;
        }
    }
}

// compute shortest distances
for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // check if distance i -> k -> j is shorter than i -> j
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

