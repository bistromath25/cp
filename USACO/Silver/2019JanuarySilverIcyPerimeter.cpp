#include <bits/stdc++.h>
using namespace std;


/*
This problem can be solved using flood-fill ideas. To determine the maximum area, use DFS to visit
all currently unvisited squares on the grid. To determine the perimeter of the component, observe
that the perimeter is formed via "boundary" squares, or squares directly adjacent to the squares
of the component itself, and these boundary squares are those squares which are not "okMove".
*/

const int N = 1000;
int n;
char grid[N][N];
int area = 0, perimeter = 0;
int curArea = 0, curPerimeter = 0;
bool vis[N][N];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // U D L R

bool okMove(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (grid[x][y] == '.') return false;
    return true;
}

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    curArea++;  // update area
    for (const pair<int, int> m : moves) {
        if (okMove(x + m.first, y + m.second)) {
            if (!vis[x + m.first][y + m.second]) {
                dfs(x + m.first, y + m.second);
            }
        }
        else {
            // the move is not valid, therefore that square must be a boundary
            curPerimeter++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j] && grid[i][j] == '#') {
                dfs(i, j);
                if (curArea > area) {
                    area = curArea;
                    perimeter = curPerimeter;
                }
                else if (curArea == area) {
                    if (curPerimeter < perimeter) {
                        perimeter = curPerimeter;
                    }
                }

                curArea = 0;
                curPerimeter = 0;
            }
        }
    }

    cout << area << ' ' << perimeter << '\n';
    return 0;
}

