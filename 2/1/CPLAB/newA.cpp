#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& topostack){
    visited[node]=true;
    for(auto &neighbor: graph[node]){
        if(!visited[neighbor]) dfs(neighbor, graph, visited, topostack);
    }
    topostack.push(node);
}

vector<int> topologicalsort(int n, vector<pair<int,int>>& edges){
    vector<vector<int>> graph(n+1);
    for(auto &edge:edges) graph[edge.first].push_back(edge.second);

    vector<bool> visited(n+1, false);
    stack<int> topostack;

    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i,graph,visited,topostack);
    }

    vector<int> topOrder;
    while(!topostack.empty()){
        topOrder.push_back(topostack.top());
        topostack.pop();
    }
    return topOrder;
}

int main() {
    int n,m;
    cin >> n >>m;

    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++) cin >> edges[i].first >> edges[i].second;

    vector<int> result = topologicalsort(n,edges);
    for(auto node:result) cout << node << " ";

    cout << '\n';

    return 0;
}