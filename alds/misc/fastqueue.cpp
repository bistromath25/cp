#include <bits/stdc++.h>
using namespace std;

template<typename T, int Size>
struct fastqueue {
    T a[Size];
    int l = 0, r = 0;
    int front() { return a[l]; }
    void pop() { l++; }
    void push(T x) { a[r++] = x; }
    bool empty() { return l == r; }
    void clear() { l = 0; r = 0; }
};

int main() {
    int n;
    cin >> n;
    fastqueue<int, 100> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }
    cout << q.empty() << '\n';
    for (int i = 0; i < n; ++i) {
        cout << q.front() << '\n';
        q.pop();
    }

    cout << q.empty() << '\n';

    return 0;
}
