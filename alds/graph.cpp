template<class Edge>
class Graph {
private:
    int V;
    vector<Edge> *adj;  // adjacency list representation
public:
    Graph() {
        V = 2e5;
        adj = new vector<Edge>[V];
    }
    Graph(int _V) {
        V = _V;
        adj = new vector<Edge>[V];
    }
    int size() {
        return V;
    }
    void resize(int _V) {
        V = _V;
        adj = new vector<Edge>[V];
    }
    void add(int v, Edge e) {
        if (find(adj[v].begin(), adj[v].end(), e) == adj[v].end()) {
            adj[v].push_back(e);
        }
        adj[v].push_back(e);
    }
    void del(int v, Edge e) {
        adj[v].erase(remove(adj[v].begin(), adj[v].end(), e), adj[v].end());
    }
    vector<Edge>& operator [](int v) {
        return adj[v];
    }

    void print();

    // more functions here...
};

template<class edge>
void Graph<edge>::print() {
    for (int i = 0; i < n; ++i) {
        if ((int) adj[i].size() > 0) {
            cout << i << ": ";
            for (const int &j : adj[i]) {
                cout << j << ' ';  // overload operator<< if needed
            }
            cout << '\n';
        }
    }
}
