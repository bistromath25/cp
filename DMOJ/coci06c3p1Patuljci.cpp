#include <bits/stdc++.h>
using namespace std;

int main() {
    int tot = 0;
    vector<int> v;
    for (int i = 0, x; i < 9; ++i) {
        cin >> x;
        v.push_back(x);
        tot += x;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if ((tot - v[i] - v[j]) == 100) {
                for (int k = 0; k < 9; ++k) {
                    if (k != i && k != j) {
                        cout << v[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}
