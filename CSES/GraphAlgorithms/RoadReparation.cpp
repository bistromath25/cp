#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
template<typename T>
void __dbg(const T &__x__) {cout << __x__;}
template<typename T1, typename T2>
void __dbg(const pair<T1, T2> &__x__) {cout << "(" << __x__.first << ", " << __x__.second << ")";}
vector<string> __split(string __s__) {__s__ += ", "; vector<string> __v__; while (!__s__.empty()) {__v__.push_back(__s__.substr(0, __s__.find(','))); __s__ = __s__.substr(__s__.find(',') + 2);} return __v__;}
void __debug_out(vector<string>::iterator __it__) {cout << "\n";}
template<typename T, typename... Args>
void __debug_out(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << *__it__ << ": "; __dbg(t); cout << "] "; __debug_out(++__it__, args...);}
#define dbg(args...) {args;}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {__dbg(a[__i__][__j__]); cout << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(args...)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

const int MAXN = 1e5;
int N, M;

struct road {
    int a, b;
    long long c;
    void read() {
        cin >> a >> b >> c;
    }
};

bool cmp(const road &a, const road &b) {
    return a.c < b.c;
}

vector<road> roads;

struct DSU {
    vector<int> p;
    void init(int N) { p = vector<int>(N + 1, -1); }
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

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif

    cin >> N >> M;
    roads.resize(M);

    for (int i = 0; i < M; ++i) {
        road r;
        r.read();
        roads.push_back(r);
    }

    sort(roads.begin(), roads.end(), cmp);

    DSU dsu;
    dsu.init(N + 1);
    dbgarr(dsu.p, dsu.p.size());

    set<int> s;
    long long cost = 0;
    int cnt = 0;
    for (const road &r : roads) {
        if (dsu.merge(r.a, r.b)) {
            cost += r.c;
            cnt++;
        }
    }

    dbgarr(dsu.p, dsu.p.size());

    if (cnt == N - 1) cout << cost << '\n';
    else cout << "IMPOSSIBLE\n";

    return 0;
}
