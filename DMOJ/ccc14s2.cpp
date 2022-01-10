#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.in", "r", stdin);

    int N;
    cin >> N;
    vector<string> n1(N), n2(N);
    map<string, string> m1, m2;

    for (int i = 0; i < N; ++i) {
        cin >> n1[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> n2[i];
    }

    for (int i = 0; i < N; ++i) {
        m1[n1[i]] = n2[i];
    }

    for (int i = 0; i < N; ++i) {
        if (m1[n1[i]] != n2[i] || m1[n2[i]] != n1[i]) {
            cout << "bad\n";
            return 0;
        }
        else if (n1[i] == n2[i]) {
            cout << "bad\n";
            return 0;
        }
        else continue;
    }

    cout << "good\n";

    return 0;
}
