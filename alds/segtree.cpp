#include <bits/stdc++.h>
using namespace std;

/**
 * Segment Tree supporting queries and updates in O(log(N))
 * f is any associate combiner function
 * ZERO is any initial value such that f(ZERO, b) = b
 */

struct SegTree {
    const long long ZERO = 0;
    long long f(long long a, long long b) {
        return a + b;
    }
    int n;
    vector<long long> segtree;
    void init(int _n) {
        n = _n;
        segtree.assign(2 * n, ZERO);
    }
    void pull(int p) {
        segtree[p] = f(segtree[2 * p], segtree[2 * p + 1]);
    }
    void update(int p, long long v) {
        segtree[p += n] = v;
        for (p /= 2; p; p /= 2) {
            pull(p);
        }
    }
    long long query(int a, int b) {
        long long ra = ZERO, rb = ZERO;
        for (a += n, b += n + 1; a < b; a /= 2, b /= 2) {
            if (a & 1) {
                ra = f(ra, segtree[a++]);
            }
            if (b & 1) {
                rb = f(segtree[--b], rb);
            }
        }
        return f(ra, rb);
    }
};
