#include <bits/stdc++.h>
using namespace std;

string input = "  ";
vector<int> g[30];
vector<string> roads;
int cnt = 0;

// A and B still linked after bombing this road?
bool linked(string road) {
    int a = road[0] - 'A', b = road[1] - 'A';
    queue<int> q;
    q.push(0);
    bool vis[30] = {false};
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (vis[c]) continue;
        vis[c] = true;
        for (const int &d : g[c]) {
            if (c == a && d == b) continue;
            else if (c == b && d == a) continue;
            else q.push(d);
        }
    }

    return vis[1];
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> input;
    while (input != "**") {
        roads.push_back(input);
        int a = input[0] - 'A', b = input[1] - 'A';
        g[a].push_back(b);
        g[b].push_back(a);
        cin >> input;
    }

    for (const string road : roads) {
        if (!linked(road)) {
            cnt++;
            cout << road << '\n';
        }
    }

    cout << "There are " << cnt << " disconnecting roads.\n";

    return 0;
}
