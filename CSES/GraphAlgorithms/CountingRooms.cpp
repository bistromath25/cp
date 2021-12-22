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
char room[N][N] = {{'.'}};
int roomtype[N][N] = {{0}};
int n, m;
bool visited[N][N] = {{false}};

bool validMove(int x, int y) {
    if (visited[x][y]) return false;
    if (room[x][y] == '#' || x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

/*
void bfs(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        visited[cx][cy] = true;
        roomtype[cx][cy] = cnt;
        q.pop();
        if (validMove(cx - 1, cy)) {
            q.push({cx - 1, cy});
        }
        if (validMove(cx + 1, cy)) {
            q.push({cx + 1, cy});
        }
        if (validMove(cx, cy - 1)) {
            q.push({cx, cy - 1});
        }
        if (validMove(cx, cy + 1)) {
            q.push({cx, cy + 1});
        }
        dbg(q.size());
    }
}
*/

void dfs(int x, int y, int cnt) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    roomtype[x][y] = cnt;
    if (validMove(x - 1, y)) {
        dfs(x - 1, y, cnt);
    }
    if (validMove(x + 1, y)) {
        dfs(x + 1, y, cnt);
    }
    if (validMove(x, y - 1)) {
        dfs(x, y - 1, cnt);
    }
    if (validMove(x, y + 1)) {
        dfs(x, y + 1, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && room[i][j] == '.') {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }

    dbgarr2d(room, n, m);
    dbgarr2d(roomtype, n, m);

    cout << cnt - 1 << '\n';
    return 0;
}
