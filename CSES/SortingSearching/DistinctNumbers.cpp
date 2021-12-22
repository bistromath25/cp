#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    set<long long> nums;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        nums.insert(x);
    }
    cout << nums.size() << '\n';
    return 0;
}
