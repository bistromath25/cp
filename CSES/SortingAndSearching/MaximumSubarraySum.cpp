#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#define ll long long
#define ld long double
#define newl '\n'

using namespace std;

long long max_sum(long long a[], long long n) {
    /// Kadane's algorithm
    long long current_max = INT_MIN;
    long long max_ending_here = 0;

    for (long long i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];

        if (current_max < max_ending_here) {
            current_max = max_ending_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }

    }
    return current_max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << max_sum(a, n);
    return 0;
}
