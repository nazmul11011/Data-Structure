#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e5 + 10;
const ll INF = LLONG_MAX;  // Use LLONG_MAX for large distances

vector<pair<ll, ll>> g[N];  // Adjacency list for the graph
vector<ll> dist(N, INF);    // Distance array initialized to INF
ll n, m;                    // Number of nodes and edges

void dijkstra(ll src) {
    dist[src] = 0;  // Distance to the source is 0
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});  // Push the source node with distance 0

    while (!pq.empty()) {
        ll d = pq.top().first;      // Current distance
        ll node = pq.top().second;  // Current node
        pq.pop();

        // If the current distance is greater than the known distance, skip
        if (d > dist[node]) continue;

        // Traverse all adjacent nodes
        for (auto &child : g[node]) {
            ll nextNode = child.first;
            ll weight = child.second;

            // If a shorter path is found
            if (d + weight < dist[nextNode]) {
                dist[nextNode] = d + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);  // Speed up I/O
    cin.tie(NULL);

    cin >> n >> m;  // Read number of nodes and edges

    // Read edges and build the graph
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // If the graph is undirected, uncomment the next line:
        // g[v].push_back({u, w});
    }

    dijkstra(1);  // Run Dijkstra's algorithm starting from node 1

    // Output the distances
    for (ll i = 1; i <= n; i++) {
            cout << dist[i] << " ";
    }

    return 0;
}