/* Graph class storing edges in adjacency list representation */

template<class Edge>
class Graph {
private:
    int V;  // number of vertices
    vector<Edge> *adj;  // adjacency list
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
    void add(int v, Edge e) {  // add the edge only if it's not already in the graph
        if (find(adj[v].begin(), adj[v].end(), e) == adj[v].end()) {  // probably not the most efficient idea
            adj[v].push_back(e);
        }
    }
    void del(int v, Edge e) {  // erase all instances of this edge
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
