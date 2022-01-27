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

const long long INF = 1e18;
const int N = 1e5 + 1;
int n, m;
vector<vector<pair<int, long long>>> gf(N), gr(N);
long long ans = INF;

vector<long long> dijkstra(int x, const vector<vector<pair<int, long long>>> &g) {
    vector<long long> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);
    dist[x] = 0;
    priority_queue<pair<long long, int>> q;
    q.push({0, x});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto [b, w] : g[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    return dist;
}

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    gf.resize(n + 1);
    gr.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        gf[a].push_back({b, w});
        gr[b].push_back({a, w});
    }

    vector<long long> distf = dijkstra(1, gf);
    vector<long long> distr = dijkstra(n, gr);

    dbgarr(distf, n + 1);
    dbgarr(distr, n + 1);

    for (int a = 1; a <= n; ++a) {  // use the coupon on path from city a
        for (auto [b, w] : gf[a]) {  // to city b
            if (distf[a] == INF || distr[b] == INF) continue;
            else {
                ans = min(ans, distf[a] + w / 2 + distr[b]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
