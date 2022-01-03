#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> locations;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin >> N >> Q;
    locations.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> locations[i];
    }

    sort(locations.begin(), locations.end());

    for (int i = 0, A, B; i < Q; ++i) {
        cin >> A >> B;
        cout << (upper_bound(locations.begin(), locations.end(), B) - locations.begin()) - (upper_bound(locations.begin(), locations.end(), A - 1) - locations.begin()) << '\n';
    }

    return 0;
}
