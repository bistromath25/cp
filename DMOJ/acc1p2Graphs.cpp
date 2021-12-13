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

const int N = 1e5 + 1;
int n, m, q;
vector<int> g[N];

int parent[N], sz[N];

void make_set(int x) {
    parent[x] = x;
    sz[x] = 1;
}

int find_set(int x) {
    if (x == parent[x]) return x;
    return find_set(parent[x]);
}

void merge_sets(int x, int y) {
    int px = find_set(x), py = find_set(y);
    if (px != py) {
        if (sz[px] > sz[py]) {
            parent[py] = px;
            sz[px] += sz[py];
        }
        else {
            parent[px] = py;
            sz[py] += sz[px];
        }
    }
}

int dista[N], distb[N];

int bfs(int a, int b) {  // bfs from both a and b to find dist
    if (a == b) return 0;

    queue<pair<int, int>> q;
    q.push({a, 0});  // 0 -> starting from a
    q.push({b, 1});  // 1 -> starting from b

    memset(dista, -1, sizeof(dista));  // dista[x] = dist from a to x
    memset(distb, -1, sizeof(distb));  // distb[x] = dist from b to x
    dista[a] = 0;
    distb[b] = 0;

    int x, t;
    while (!q.empty()) {
        x = q.front().first, t = q.front().second;
        q.pop();
        for (const int &y : g[x]) {
            if (t == 1) {
                if (distb[y] != -1) continue;  // already computed this dist
            }
            else {
                if (dista[y] != -1) continue;
            }

            if (t == 1) {
                distb[y] = distb[x] + 1;
                if (dista[y] != -1) {  // dist y already found, meet at y
                    return dista[y] + distb[y];  // return dist from a to y plus dist b to y
                }
            }
            else {
                dista[y] = dista[x] + 1;
                if (distb[y] != -1) {
                    return distb[y] + dista[y];
                }
            }

            q.push({y, t});  // push y into the queue
        }
    }

    return -1;  // no path found
}

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

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }

    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        merge_sets(a, b);
    }

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        if (find_set(a) != find_set(b)) {
            cout << "-1\n";
        }
        else {
            cout << bfs(a, b) << '\n';
        }
    }

    return 0;
}
