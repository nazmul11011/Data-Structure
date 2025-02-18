#include <bits/stdc++.h>
using namespace std;

#define V 9

void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t" << dist[i] << endl;
}

vector<int> dijkstra(vector<pair<int, int>> adj[], int src) {
    set<pair<int,int>> s;
    vector<int> dist(V, INT_MAX);

    s.insert({0,src});
    dist[src]=0;

    while(!s.empty()){
        auto it = *(s.begin());
        int node = it.second;
        int dis = it.first;
        s.erase(it);

        for(auto edge:adj[node]){
            int adjNode = edge.first;
            int edgWeight = edge.second;

            if(dis + edgWeight < dist[adjNode]){
                if(dist[adjNode] != INT_MAX)
                    s.erase({dist[adjNode], adjNode});
                    
                dist[adjNode] = dis + edgWeight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }

    // Print the solution
    printSolution(dist.data());
    return dist;
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    // Convert adjacency matrix to adjacency list
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                adj[i].push_back({j, graph[i][j]});
            }
        }
    }

    // Call Dijkstra's algorithm
    dijkstra(adj, 0);

    return 0;
}