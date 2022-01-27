struct DSU {
    vector<int> p, sz;
    void init(int N) {
        p.resize(N + 1);
        sz.resize(N + 1);
        for (int i = 0; i <= N; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
};
