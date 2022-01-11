#include <bits/stdc++.h>
using namespace std;

#define readfile(filename) freopen(filename, "r", stdin);
#define writefile(filename) freopen(filename, "w", stdout);


/*
Cows (farms) with the same color and a path between
them are part of the same connected component.
To determine if the friend will be happy or not,
check if the endpoints are different components or
if the endpoints are different colors.
*/

const int MAXN = 1e5 + 1;
int N, M;
string color;
vector<int> g[MAXN];
int comp[MAXN];  // component number
int cnt = 1;  // global counter for comp number

void dfs(int x) {  // no need to track parent, since comp[x] tells us if x's been visited or not
    if (comp[x] != 0) return;
    comp[x] = cnt;
    for (const int &nxt : g[x]) {
        if (color[x] == color[nxt]) {  // only move there if it's the same color
            dfs(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    readfile("milkvisits.in");
    writefile("milkvisits.out");

    cin >> N >> M >> color;
    color = 'X' + color;  // 1-indexed
    for (int i = 0, X, Y; i < N - 1; ++i) {
        cin >> X >> Y;
        g[X].push_back(Y);
        g[Y].push_back(X);
    }

    for (int i = 1; i <= N; ++i) {
        if (comp[i] == 0) {
            dfs(i);
            cnt++;
        }
    }

    for (int i = 0, A, B; i < M; ++i) {
        char C;
        cin >> A >> B >> C;
        if (comp[A] != comp[B]) {
            cout << 1;
        }
        else {
            if (C == color[A] || C == color[B]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
    }

    return 0;
}
