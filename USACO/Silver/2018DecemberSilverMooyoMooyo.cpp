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

const int N = 100;
char grid[N][10];
int n, k;
char cur_color = 'X';  // current component's color

set<pair<int, int>> vis;  // persistent set of visited coordinates
set<pair<int, int>> cur_vis;  // set of visited coordinates for current dfs, finds current component
set<pair<int, int>> to_remove;  // set of cells to remove
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool okMove(int x, int y) {
    // return false if move is out-of-bounds
    if (x < 0 || x >= N || y < 0 || y >= 10) return false;
    return true;
}

void dfs(int x, int y) {
    if (cur_vis.find({x, y}) != cur_vis.end()) return;
    cur_vis.insert({x, y});
    vis.insert({x, y});
    for (const pair<int, int> m : moves) {
        if (okMove(x + m.first, y + m.second) && grid[x + m.first][y + m.second] == cur_color) {
            dfs(x + m.first, y + m.second);
        }
    }
}

void delete_cells() {
    // replace all to_remove cells with 0
    for (const pair<int, int> &p : to_remove) {
        grid[p.first][p.second] = '0';
    }
}

void gravity() {
    // simulate the gravity process
    for (int i = 0; i < 10; ++i) {
        int top = n - 1, bottom = n - 1;
        while (top >= 0) {
            while (top >= 0 && grid[top][i] == '0') {
                top--;
            }

            if (top >= 0) {
                // move everything down
                grid[bottom--][i] = grid[top--][i];
            }
        }
        while (bottom >= 0) {
            grid[bottom--][i] = '0';
        }
    }
}

void print_grid() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    #endif

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> grid[i][j];
        }
    }

    dbgmsg("current grid:");
    dbgarr2d(grid, n, 10);


    bool can_delete = true;  // are there more groups of k colors to delete?

    while (can_delete) {
        can_delete = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (vis.find({i, j}) == vis.end() && grid[i][j] != '0') {
                    // set cur_color and dfs starting with (i, j)
                    cur_color = grid[i][j];
                    debug(i, j, cur_color);
                    dbgmsg("Starting DFS");
                    dfs(i, j);
                }

                if (cur_vis.size() >= k) {
                    can_delete = true;
                    for (const pair<int, int> &p : cur_vis) {
                        to_remove.insert(p);
                    }
                }

                cur_vis.clear();

            }
        }

        debug(vis.size());

        delete_cells();
        gravity();
        vis.clear();
        to_remove.clear();

        dbgmsg("current grid:");
        dbgarr2d(grid, n, 10);
    }

    //dbgmsg("\nfinal grid:");
    print_grid();

    return 0;
}

