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

/*
Binary search for the "least wide wormhole" x.
To check if a certain x is valid:
Use a DSU to store components, merging two vertices (endpoints of a wormhole)
only if the width of that wormhole is greater than or equal to x.
Pass over the input array p, and for every value i with i != p[i] check if
the parent of i and p[i] is the same.
*/

const int MAXN = 1e5, MAXM = 1e5;
int N, M, maxwidth = 0;
vector<int> p(MAXN + 1);
struct wormhole {
    int a, b, w;
    void read() {
        cin >> a >> b >> w;
    }
} wormholes[MAXM + 1];

bool cmp(const wormhole &a, const wormhole &b) {
    return a.w < b.w;  // sort by width ascending, actually not needed
}

// DSU
int parent[MAXN + 1];
void make_set(int x) {
    parent[x] = x;
}
int find_set(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}
void merge_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x != y) {  // basic merge, no union by size/rank optimization
        parent[x] = y;
    }
}

bool ok(int width) {
    for (int i = 1; i <= N; ++i) make_set(i);
    for (int i = 1; i <= M; ++i) {
        if (wormholes[i].w >= width) {
            merge_sets(wormholes[i].a, wormholes[i].b);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (p[i] == i) continue;
        if (find_set(i) != find_set(p[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    #endif

    cin >> N >> M;
    p.resize(N + 1);
    bool sorted = true;
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
        if (sorted && i > 1 && p[i - 1] > p[i]) sorted = false;
    }
    if (sorted) {  // exit if already sorted
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= M; ++i) {
        wormholes[i].read();
        maxwidth = max(maxwidth, wormholes[i].w);  // keep track of the largest width seen
    }

    //sort(wormholes + 1, wormholes + M + 1, cmp);

    int low = 1, high = maxwidth, mid = 0;
    while (low < high) {
        mid = (low + high + 1) / 2;
        debug(low, mid, high);
        if (ok(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }

    cout << low << '\n';

    return 0;
}
