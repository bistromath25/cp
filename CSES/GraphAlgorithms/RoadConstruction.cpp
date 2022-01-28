#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int N, M;

int max_sz = -1, comp_cnt = 0;
int parent[MAXN + 1], sz[MAXN + 1];

void make_set(int x) {
    parent[x] = x;
    sz[x] = 1;
    comp_cnt++;
}

int find_set(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_set(parent[x]);
}

void merge_sets(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    max_sz = max(max_sz, sz[x]);
    comp_cnt--;
}



int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        make_set(i);
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        merge_sets(a, b);

        cout << comp_cnt << ' ' << max_sz << '\n';
    }

    return 0;
}
