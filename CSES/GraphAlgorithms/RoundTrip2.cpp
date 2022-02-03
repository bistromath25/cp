#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, M;
vector<int> g[MAXN + 1];
bool vis[MAXN + 1], ins[MAXN + 1];
vector<int> cycle;

bool dfs(int x) {
    vis[x] = true;
    ins[x] = true;

    for (const int &y : g[x]) {
        if (ins[y]) {
            cycle.push_back(x);  // start cycle
            ins[x] = false;
            ins[y] = false;
            return true;
        }
        else if (!vis[y]) {
            if (dfs(y)) {  // continue current cycle
                if (ins[x]) {
                    cycle.push_back(x);
                    ins[x] = false;
                    return true;
                }
                else {
                    cycle.push_back(x);
                    return false;
                }
            }
            if (!cycle.empty()) {  // found a cycle, exit
                return false;
            }
        }
    }

    ins[x] = false;
    return false;
}

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;
    for (int i = 1, a, b; i <= M; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= N; ++i) {
        if (!cycle.empty()) break;
        else dfs(i);
    }

    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        int c = cycle.size();
        cout << c + 1 << '\n';
        for (int i = 0; i < c; ++i) {
            cout << cycle[c - i - 1] << ' ';
        }
        cout << cycle[c - 1] << '\n';
    }

    return 0;
}
