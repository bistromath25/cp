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


const int MAXN = 200;
int N;

struct p {
    int x, y, r;
    void read() {
        cin >> x >> y >> r;
    }
};

vector<p> points;
vector<int> g[MAXN];

int dist(const p &a, const p &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int bfs(int x) {
    int cnt = 0;
    vector<bool> vis(N, false);
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cnt++;
        for (const int &nxt : g[cur]) {
            if (!vis[nxt]) {
                q.push(nxt);
            }
        }
    }
    return cnt;
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    #endif

    cin >> N;
    points.resize(N);
    for (int i = 0, x, y, p; i < N; ++i) {
        points[i].read();
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int d = dist(points[i], points[j]);
            if (d <= points[i].r * points[i].r) {
                g[i].push_back(j);
            }
            if (d <= points[j].r * points[j].r) {
                g[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, bfs(i));
    }

    cout << ans << '\n';

    return 0;
}
