#include <iostream>
#include <vector>
#include <queue>
//Exercice1 TP01
using namespace std;

const int INF = 1e9;

int n, k;
vector<pair<int, int>> adj[101]; 
int dist[101];

void dijkstra(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto v : adj[u]) {
            if (dist[v.second] > dist[u] + v.first) {
                dist[v.second] = dist[u] + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].push_back({1, j});
                adj[j].push_back({1, i});
            }
        }
    }
    dijkstra(1);
}
