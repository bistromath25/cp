#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define DEBUG 0
#if DEBUG
#define print(n) cout << (#n) << ": " << (n) << endl
#define print_array(a, l) cout << (#a) << ": "; for (int __i__ = 0; __i__ < (l); ++__i__) {cout << a[__i__] << " ";} cout << endl
#define print_array_2d(a, r, c) cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << a[__i__][__j__] << " ";} cout << endl;}
#else
#define print(n) ;
#define print_array(a, l) ;
#define print_array_2d(a, r, c) ;
#endif

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> ans;
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        auto it = ans.upper_bound(k);
        if (it == ans.end()) {
            ans.insert(k);
        }
        else {
            ans.erase(it);
            ans.insert(k);
        }

    }

    cout << ans.size() << "\n";
    return 0;
}
