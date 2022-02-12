#include <bits/stdc++.h>
using namespace std;

long long solve(long long A, long long B) {
    if (A == B) return 0;

    int steps = 0;
    if (A > B) {  // reduce A
        if (A % 2 == 1) {
            A++;
            steps++;
        }
        return solve(A / 2, B) + 1 + steps;
    }
    else if (A <= B / 2) {
        if (B % 2 == 1) {
            B--;  // "opposite" of increasing by 1
            steps++;
        }
        return solve(A, B / 2) + 1 + steps;
    }
    else {
        long long dist = B - A;  // no. steps by increasing A by 1 to B
        if (A % 2 == 1) {
            A++;
            steps++;
        }
        if (B % 2 == 1) {
            B--;
            steps++;
        }
        return min(dist, solve(A / 2, B / 2) + 2 + steps);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        cout << solve(A, B) << '\n';
    }
    return 0;
}
