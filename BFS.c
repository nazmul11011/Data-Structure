#include <stdio.h>
#include<stdbool.h>
#define MAX 100

int q[MAX];
int front = 0;
int rear = 0;
int adj[MAX][MAX];
bool visited[MAX];

void push(int data){
    q[rear++] = data;
}

int pop(){
    return q[front++];
}

bool isEmpty(){
    return front ==  rear;
}

void bfs(int nodes, int edges, int start){
    push(start);
    
    while(!isEmpty()){
        int u = pop();
        
        if(!visited[u]){
            visited[u] = true;
            printf("%d ", u);
            
            for(int v = 1; v <= nodes; v++){
                if(adj[u][v] && !visited[v]){
                    push(v);
                }
            }
        }
        
    }
}

int main() {
    int nodes, edges;
    scanf("%d%d", &nodes, &edges);
    int u, v;
    
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            adj[i][j] = 0;
        }
    }
    
    for(int i=0; i<edges; i++){
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    bfs(nodes, edges, 1);
    
    return 0;
}