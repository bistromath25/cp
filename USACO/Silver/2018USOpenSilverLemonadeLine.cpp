#include <bits/stdc++.h>
using namespace std;

int N;
int w[100001];

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    cin >> N;
    w[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
    }

    sort(w + 1, w + N + 1);
    reverse(w + 1, w + N + 1);  // "biggest" cows first

    int i = 1;
    for (i = 1; w[i] >= i - 1 && i <= N; ++i) {
        //cout << i << ' ' << w[i] << '\n';
    }
    cout << i - 1 << '\n';

    return 0;
}
