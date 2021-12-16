#define DEBUG 1

#include <bits/stdc++.h>
using namespace std;

#pragma message("Compiling at: " __TIMESTAMP__ ". Executing File: " __FILE__)

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

char grid[51][51];
bool vis[51][51];
int l, w;

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok_move(int x, int y) {
    if (x < 0 || x >= l || y < 0 || y >= w || grid[x][y] == 'X') return false;
    return true;
}

int bfs(pair<int, int> start, pair<int, int> finish) {
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    int d = 1e9;
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        int cx = cur.first.first, cy = cur.first.second, cd = cur.second;
        if (vis[cx][cy]) continue;
        if (grid[cx][cy] == 'W') {
            d = min(d, cd);
            continue;
        }
        vis[cx][cy] = true;
        for (const pair<int, int> &mv : moves) {
            int nx = cx + mv.first, ny = cy + mv.second;
            if (ok_move(nx, ny)) {
                q.push({{nx, ny}, cd + 1});
            }
        }
    }
    return d;
}

void solve() {
    cin >> w >> l;
    pair<int, int> start, finish;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') start = {i, j};
            else if (grid[i][j] == 'W') finish = {i, j};
            vis[i][j] = false;
        }
    }

    int ans = bfs(start, finish);
    if (ans >= 60) cout << "#notworth\n";
    else cout << ans << '\n';
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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

