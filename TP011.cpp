#include <iostream>
#include <vector>
//Exercice 2 TP01
using namespace std;

void dfs(int v, vector<vector<int>>& adjacency_matrix, vector<bool>& visited) {
    visited[v] = true;
    for (int u = 0; u < adjacency_matrix[v].size(); u++) {
        if (adjacency_matrix[v][u] == 1 && !visited[u]) {
            dfs(u, adjacency_matrix, visited);
        }
    }
}

int count_connected_components(int n, vector<vector<int>>& adjacency_matrix) {
    vector<bool> visited(n);
    int count = 0;
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            count++;
            dfs(v, adjacency_matrix, visited);
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjacency_matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjacency_matrix[i][j];
        }
    }
    cout << count_connected_components(n, adjacency_matrix) << endl;
    return 0;
}

