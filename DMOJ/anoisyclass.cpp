#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
int n, m;
vector<int> g[N];

bool cycle = false;

int c = -1;
int ord[N], low[N];
stack<int> stk;
bool ins[N], vis[N];
vector<vector<int>> components;

void dfs(int x) {
    c++;
    stk.push(x);
    ins[x] = true;
    vis[x] = true;
    ord[x] = c;
    low[x] = c;
    for (const int &y : g[x]) {
        if (!vis[y]) {
            dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y]) {
            low[x] = min(low[x], ord[y]);
        }
    }
    if (low[x] == ord[x]) {
        int y = -1;
        vector<int> component;
        do {
            y = stk.top();
            stk.pop();
            ins[y] = false;
            component.push_back(y);
        } while (y != x);
        components.push_back(component);
    }
}

void tarjan() {
    components.clear();
    c = -1;
    for (int i = 1; i <= n; ++i) {
        ins[i] = false;
        vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    tarjan();

    if (components.size() == n) {
        cout << "Y\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}
