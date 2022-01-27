/* Compact DSU struct for quick copy & paste */

struct DSU {
    vector<int> p;
    void init(int N) { p = vector<int>(N + 1, -1); }
    //void make(int x) { p[x] = x; }
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -p[find(x)]; }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
};
