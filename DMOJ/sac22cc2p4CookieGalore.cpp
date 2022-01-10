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

typedef pair<int, int> pii;

const int N = 1e3;
int n, m;
char grid[N][N];
int dist[N][N];
bool vis[N][N];
vector<pii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok_move(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void dijkstra(pii start) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vis[i][j] = false;
            dist[i][j] = 1e9;
        }
    }

    int x = start.first, y = start.second;
    if (grid[x][y] == 'C') {
        dist[x][y] = 1;
    }
    else {
        dist[x][y] = 0;
    }

    priority_queue<pair<int, pii>> q;
    q.push({dist[x][y], start});

    while (!q.empty()) {
        int cx = q.top().second.first, cy = q.top().second.second;
        q.pop();
        if (vis[cx][cy]) continue;
        vis[cx][cy] = true;
        debug(cx, cy, dist[cx][cy]);

        for (const pii &mv : moves) {
            int nx = cx + mv.first, ny = cy + mv.second;
            if (ok_move(nx, ny)) {
                int w = (grid[nx][ny] == 'C' ? 1 : 0);
                debug(cx, cy, dist[cx][cy]);
                debug(nx, ny, w);
                if (dist[cx][cy] + w < dist[nx][ny]) {
                    dbg(cout << "making improvements\n");
                    dist[nx][ny] = dist[cx][cy] + w;
                    q.push({-dist[nx][ny], {nx, ny}});
                }

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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    dijkstra({0, 0});

    dbgarr2d(vis, n, m);
    dbgarr2d(dist, n, m);

    cout << dist[n - 1][m - 1] << '\n';




    return 0;
}
