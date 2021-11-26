#include <bits/stdc++.h>
using namespace std;

template<class T>
class DisjointSet {
private:
    unordered_map<T, int> parent, tree_size;
public:
    void init(vector<T> const& v) {
        for (T x : v) {
            make_set(x);
        }
    }
    void make_set(T x) {
        parent[x] = x;
        tree_size[x] = 0;
    }
    T find_set(T x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    void merge_sets(T x, T y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            if (tree_size[x] > tree_size[y]) {
                parent[y] = x;
            }
            else if (tree_size[x] < tree_size[y]) {
                parent[x] = y;
            }
            else {
                parent[x] = y;
                tree_size[y]++;
            }
        }
    }
};

template<class T>
void print_sets(vector<T> const &v, DisjointSet<T> &ds) {
    for (int x : v) {
        cout << ds.find_set(x) << ' ';
    }
    cout << '\n';
}

DisjointSet<int> DS;

int main() {

    vector<int> v = {1, 2, 3, 4, 5};

    DS.init(v);

    DS.merge_sets(1, 2);
    DS.merge_sets(1, 5);

    print_sets(v, DS);

    return 0;
}
