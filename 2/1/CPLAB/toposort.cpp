#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    for (auto& neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, topoStack);
        }
    }
    topoStack.push(node);
}

vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n + 1);
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    vector<bool> visited(n + 1, false);
    stack<int> topoStack;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, topoStack);
        }
    }

    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }
    return topoOrder;
}

int main() {
    int n, m; // n = nodes, m = edges
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> result = topologicalSort(n, edges);
    for (auto node : result) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}