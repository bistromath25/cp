#include <bits/stdc++.h>
using namespace std;

/**
 * Segment Tree supporting queries and updates in O(log(N))
 * f is any associative combiner function
 * ZERO is any initial value such that f(ZERO, b) = b
 */

template<class T>
struct SegTree {
    const T ZERO = 0;
    T f(T a, T b) {
        return a + b;
    }
    int n;
    vector<T> segtree;
    void init(int _n) {
        n = _n;
        segtree.assign(2 * n, ZERO);
    }
    void init(vector<T> v) {
        init((int) v.size());
        for (int i = 0; i < n; ++i) {
            segtree[n + i] = v[i];
        }
        build();
    }
    void build() {
        for (int i = n - 1; i > 0; --i) {
            segtree[i] = f(segtree[i << 1], segtree[(i << 1) | 1]);
        }
    }
    void pull(int p) {
        segtree[p] = f(segtree[2 * p], segtree[2 * p + 1]);
    }
    void update(int p, T v) {
        segtree[p += n] = v;
        for (p /= 2; p; p /= 2) {
            pull(p);
        }
    }
    T query(int a, int b) {
        T ra = ZERO, rb = ZERO;
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
