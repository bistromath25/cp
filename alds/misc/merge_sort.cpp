#include <bits/stdc++.h>
using namespace std;

int merge_arrays(vector<int> &a, vector<int> &t, int l, int m, int r) {
    int i = l, j = m, k = l, inv = 0;
    while ((i <= m - 1) && (j <= r)) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        }
        else {
            t[k++] = a[j++];
            inv += m - i;
        }
    }
    while (i <= m - 1) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l; i <= r; ++i) a[i] = t[i];
    return inv;
}

int merge_sort(vector<int> &a, vector<int> &t, int l, int r) {
    int m;
    int inv = 0;
    if (r> l) {
        m = (r+ l) / 2;
        inv = merge_sort(a, t, l, m);
        inv += merge_sort(a, t, m + 1, r);
        inv += merge_arrays(a, t, l, m + 1, r);
    }
    return inv;
}

int msort(vector<int> &a) {
    vector<int> t((int) a.size());
    return merge_sort(a, t, 0, (int) a.size() - 1);
}


int main() {
    vector<int> aa = {1, 2, 3, 6, 5};

    cout << msort(aa) << '\n';

    for (auto x : aa) {
        cout << x << ' ';
    }

    return 0;
}
