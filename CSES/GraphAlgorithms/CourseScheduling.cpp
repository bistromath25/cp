#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> g[100001];
int indeg[100001];

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    vector<int> topo;
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    int cnt = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (const int &cc : g[c]) {
            indeg[cc]--;
            if (indeg[cc] == 0) q.push(cc);
        }
        topo.push_back(c);
        cnt++;
    }

    if (cnt != N) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        cout << topo[i] << ' ';
    }
    cout << '\n';

    return 0;
}
