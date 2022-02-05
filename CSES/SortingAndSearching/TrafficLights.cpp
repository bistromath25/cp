#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> x >> n;
    set<int> lights;
    multiset<int> dists;
    lights.insert(0);
    lights.insert(x);
    dists.insert(x);
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        auto a = lights.upper_bound(p);
        auto b = a;
        --b;
        dists.erase(dists.find(*a - *b));
        dists.insert(p - *b);
        dists.insert(*a - p);
        lights.insert(p);
        auto ans = dists.end();
        cout << *(--ans) << ' ';
    }
    cout << '\n';
    return 0;
}
