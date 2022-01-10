#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

char grid[10][10];
int r, c;
pii A, B, C;
bool vis[10][10];
vector<pii> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok_move(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) return false;
    else if (grid[x][y] == '#') return false;
    else return true;
}

int bfs(pii s, pii e) {
    memset(vis, 0, sizeof(vis));
    queue<pair<pii, int>> q;
    int d = INT_MAX;
    q.push({s, 0});
    pair<pii, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        int cx = cur.first.first, cy = cur.first.second, cd = cur.second;
        if (cx == e.first && cy == e.second) {
            d = min(d, cd);
            vis[cx][cy] = true;
            continue;
        }
        if (vis[cx][cy]) continue;
        vis[cx][cy] = true;

        for (const pii &mv : moves) {
            int nx = cx + mv.first, ny = cy + mv.second;
            if (ok_move(nx, ny)) {
                q.push({{nx, ny}, cd + 1});
            }
        }
    }

    return d;
}


int main() {

    for (int t = 1; t <= 5; ++t) {
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'A') A = {i, j};
                else if (grid[i][j] == 'B') B = {i, j};
                else if (grid[i][j] == 'C') C = {i, j};
            }
        }

        cout << bfs(A, B) + bfs(B, C) + bfs(C, A) << '\n';
    }

    return 0;
}
