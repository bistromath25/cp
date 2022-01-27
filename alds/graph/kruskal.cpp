/* Kruskal MST with disjoint set using union by size */

vector<int> parent, sz;

void make_set(int x) {
    parent[x] = x;
    sz[x] = 0;
}

int find_set(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

void merge_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
}

struct Edge {
    int a, b, w;
    bool operator < (Edge const& e) {
        return w < e.w;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> mst;
parent.resize(n);
sz.resize(n);

// initialize parent array
for (int i = 0; i < n; i++) {
    make_set(i);
}

// sort edges
sort(edges.begin(), edges.end());

// make MST
for (Edge e : edges) {
    if (find_set(e.a) != find_set(e.b)) {
        cost += e.w;  // joined these nodes, add edge cost
        result.push_back(e);  // result = vector<Edge> holding the final MST
        merge_sets(e.a, e.b);
    }
}
