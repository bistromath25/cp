#include <bits/stdc++.h>
using namespace std;

// longest path in a DAG via topological sorting and dp

const int MAXN = 1e5, INF = 1e9;
int N, M;
vector<int> gf[MAXN + 1], gr[MAXN + 1];
int dist[MAXN + 1];  // dist[x] = longest path from 1 ending at x, dp[x] = (max dist of previous paths leading to x) + 1
int indeg[MAXN + 1];
int parent[MAXN + 1];

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        dist[i] = -INF;
        parent[i] = -1;
        indeg[i] = 0;
    }

    for (int i = 1, a, b; i <= M; ++i) {
        cin >> a >> b;
        gf[a].push_back(b);
        gr[b].push_back(a);
        indeg[b]++;
    }

    queue<int> q;  // khan's algorithm
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {  // topo sort guarantees that parent vertices are computed before children vertices
        int x = q.front();
        q.pop();
        for (const int &y : gf[x]) {
            indeg[y]--;
            if (indeg[y] == 0) q.push(y);
        }

        int mx = -INF;
        int p = -1;
        for (const int &par : gr[x]) {
            if (dist[par] + 1 > mx) {
                mx = dist[par] + 1;
                p = par;
            }
        }

        dist[x] = mx;
        if (x == 1) dist[x] = 1;
        parent[x] = p;
    }


    vector<int> ans;
    int f = N;
    bool ok = (f == 0);

    while (f != -1 && dist[f] >= 0) {
        ans.push_back(f);
        f = parent[f];
        if (f == 1) {
            ok = true;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << dist[N] << '\n';
        int a = ans.size();
        for (int i = 0; i < a; ++i) {
            cout << ans[a - i - 1] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
