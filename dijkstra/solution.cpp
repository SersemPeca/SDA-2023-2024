#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 1 << 18; // 2^17

int n, m; // nodes and edges
vector<pair<int, int>> graph[MAX_SIZE];


int dist[MAX_SIZE];

void dijkstra(int start) {
    fill(dist, dist + n, INT_MAX);
    dist[start] = 0;

    set<pair<int, int>> s;
    s.insert({0, start});

    while (s.size() > 0) {
        int u = (*s.begin()).second;
        s.erase(s.begin());

        for (auto v : graph[u]) {
            if (dist[v.first] > dist[u] + v.second) {
                s.erase({dist[v.first], v.first});
                dist[v.first] = dist[u] + v.second;
                s.insert({dist[v.first], v.first});
            }
        }
    }
}

int main() {
    return 0;
}
