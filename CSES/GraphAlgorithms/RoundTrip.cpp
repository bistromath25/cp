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


const int N = 1e5 + 10;
int n, m;
int start, finish;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> parent(N, 0);
vector<int> ans;

bool dfs(int x, int p) {
    vis[x] = true;
    parent[x] = p;
    for (const int &y : g[x]) {
        if (y == p) continue;
        if (vis[y]) {
            start = y;
            finish = x;
            return true;
        }
        if (!vis[y]) {
            if (dfs(y, x)) {
                return true;
            }
        }
    }
    return false;
}

bool solve() {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1)) return true;
        }
    }
    return false;
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

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (!solve()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }


    int x = finish;
    ans.push_back(x);
    while (x != start) {
        ans.push_back(parent[x]);
        x = parent[x];
    }

    reverse(ans.begin(), ans.end());
    dbgarr(ans, (int) ans.size());

    cout << (int) ans.size() + 1 << '\n';

    for (const int &x : ans) {
        cout << x << ' ';
    }
    cout << ans[0] << '\n';

    return 0;
}
