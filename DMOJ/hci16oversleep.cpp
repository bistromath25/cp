#define DEBUG 1

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

const int N = 1000;
int n, m;
char grid[N][N];
bool vis[N][N];
pair<int, int> start, finish;

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok_move(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (grid[x][y] == 'X') return false;
    return true;
}

int bfs(pair<int, int> start, pair<int, int> finish) {
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    int d = INT_MAX;
    pair<pair<int, int>, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        int cx = cur.first.first, cy = cur.first.second, cd = cur.second;
        if (cx == finish.first && cy == finish.second) {
            d = min(d, cd);
            vis[cx][cy] = true;
            continue;
        }
        if (vis[cx][cy]) continue;
        vis[cx][cy] = true;

        for (const pair<int, int> &mv : moves) {
            int nx = cx + mv.first, ny = cy + mv.second;
            if (ok_move(nx, ny)) {
                q.push({{nx, ny}, cd + 1});
            }
        }
    }

    if (d == INT_MAX) return -1;
    else return d;
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
            if (grid[i][j] == 's') start = {i, j};
            else if (grid[i][j] == 'e') finish = {i, j};
        }
    }


    int d = bfs(start, finish);

    dbgarr2d(vis, n, m);

    if (d == -1) cout << "-1\n";
    else cout << d - 1 << '\n';
    return 0;
}
