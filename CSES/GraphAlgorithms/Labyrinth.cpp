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


const int N = 1000;
int n, m;  // height and width
char grid[N][N] = {{'.'}};
int ax, ay, bx, by;  // coordinates of A and B
int vis[N][N] = {{0}};
char path[N][N] = {{'X'}};
vector<char> ans;

bool ok_move(int x, int y) {
    if (grid[x][y] == '#' || x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) return false;
    return true;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {

        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (grid[cx][cy] == 'B') return;

        if (ok_move(cx - 1, cy)) {
            // Up
            q.push({cx - 1, cy});
            vis[cx - 1][cy] = true;
            path[cx - 1][cy] = 'U';
        }
        if (ok_move(cx + 1, cy)) {
            // Down
            q.push({cx + 1, cy});
            vis[cx + 1][cy] = true;
            path[cx + 1][cy] = 'D';
        }
        if (ok_move(cx, cy - 1)) {
            // Left
            q.push({cx, cy - 1});
            vis[cx][cy - 1] = true;
            path[cx][cy - 1] = 'L';
        }
        if (ok_move(cx, cy + 1)) {
            // Right
            q.push({cx, cy + 1});
            vis[cx][cy + 1] = true;
            path[cx][cy + 1] = 'R';
        }
    }
}

int main() {
    #if DEBUG
    freopen("INPUT.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                ax = i;
                ay = j;
            }
            if (grid[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    dbgarr2d(grid, n, m);

    dbgprf("Coordinates of A and B:");
    debug(ax, ay, bx, by);

    bfs(ax, ay);

    dbgarr2d(path, n, m);

    if (!vis[bx][by]) {
        cout << "NO\n";
        return 0;
    }

    while (ax != bx || ay != by) {
        if (path[bx][by] == 'U') {
            ans.push_back('U');
            bx++;
        }
        else if (path[bx][by] == 'D') {
            ans.push_back('D');
            bx--;
        }
        else if (path[bx][by] == 'L') {
            ans.push_back('L');
            by++;
        }
        else if (path[bx][by] == 'R') {
            ans.push_back('R');
            by--;
        }
        debug(ax, ay, bx, by);
    }

    dbgarr(ans, ans.size());
    reverse(ans.begin(), ans.end());
    dbgarr(ans, ans.size());

    cout << "YES\n" << (int) ans.size() << '\n';
    for (const char &c : ans) {
        cout << c;
    }
    cout << '\n';


    return 0;
}
