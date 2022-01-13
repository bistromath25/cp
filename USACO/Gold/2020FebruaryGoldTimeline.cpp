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

const int MAXN = 1e5 + 1;
int N, M, C;
vector<int> dates(MAXN);
vector<pair<int, int>> g[MAXN];
vector<int> indeg(MAXN);  // in-degree of each vertex
bool adjusted[MAXN];


int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    #endif

    cin >> N >> M >> C;
    dates.resize(N + 1);
    indeg.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> dates[i];
        adjusted[i] = false;
    }

    dbgarr(dates, N + 1);

    for (int i = 1, a, b, x; i <= C; ++i) {
        cin >> a >> b >> x;
        g[a].push_back({b, x});
        indeg[b]++;
    }

    // process "least important" edges first
    queue<int> q;  // topological sort via Kahn's
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const pair<int, int> &e : g[cur]) {
            int nxt = e.first, d = e.second;
            if (dates[cur] + d > dates[nxt]) {
                dates[nxt] = dates[cur] + d;
            }
            indeg[nxt]--;
            if (indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << dates[i] << '\n';
    }

    return 0;
}
