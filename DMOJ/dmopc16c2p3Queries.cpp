#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int>> q;
        int a = 0, b = 0;
        for (int i = 0, x, y; i < M; ++i) {
            cin >> x >> y;
            a = max(a, x);
            b = max(b, y);
        }

        if (a + b > N) {
            cout << "-1\n";
        }
        else {
            for (int i = 0; i < a; ++i) {
                cout << 'a';
            }
            for (int i = 0; i < b; ++i) {
                cout << 'b';
            }
            cout << '\n';
        }
    }

    return 0;
}
