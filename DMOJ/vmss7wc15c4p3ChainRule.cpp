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
#define dbg(x) {cout << "[" << (#x) << ": "; __dbg(x); cout << "]\n";}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {__dbg(a[__i__][__j__]); cout << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

const int N = 1e5 + 1;
const long long LLINF = 1e18;
int n, m;
vector<pair<int, long long>> g[N];
long long ans = 0;  // longest path


long long dist[N], dist2[N];
bool vis[N], vis2[N];

void dijkstra(int x) {
    for (int i = 0; i < n; ++i) {
        dist[i] = LLINF;
    }
    dist[x] = 0;

    priority_queue<pair<long long, int>> q;
    q.push({0, x});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (const pair<int, long long> &e : g[a]) {
            int b = e.first;
            long long w = e.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

void dijkstra2(int x) {
    for (int i = 0; i < n; ++i) {
        dist2[i] = LLINF;
    }
    dist2[x] = 0;

    priority_queue<pair<long long, int>> q;
    q.push({0, x});
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (vis2[a]) continue;
        vis2[a] = true;
        for (const pair<int, long long> &e : g[a]) {
            int b = e.first;
            long long w = e.second;
            if (dist2[a] + w < dist2[b]) {
                dist2[b] = dist2[a] + w;
                q.push({-dist2[b], b});
            }
        }
    }
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
    for (int i = 0, a, b, t; i < m; ++i) {
        cin >> a >> b >> t;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }

    dijkstra(0);  // find the shortest paths starting from 0
    dijkstra2(n - 1);  // find the shortest paths starting from n-1

    for (int i = 0; i < n; ++i) {
        ans = max(ans, dist[i] + dist2[i]);
    }

    cout << ans << '\n';

    return 0;
}
