#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    set<ll> nums;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        nums.insert(x);
    }
    cout << nums.size() << '\n';
    return 0;
}
