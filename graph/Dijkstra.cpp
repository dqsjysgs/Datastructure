#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 1000000;
int main(void) {
    
    int graph[10][10], dis[10];
    bool vis[10];
    int n, m, ai, aj, d;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ai >> aj >> d;
        graph[ai][aj] = d;
    }
    
    for (int i = 1; i <= n; i++)
        dis[i] = graph[1][i];

    for (int i = 1; i <= n; i++)
        vis[i] = false;
    vis[1] = true;

    for (int i = 1; i <= n - 1; i++) {
        int u;
        int minn = INF;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }           
        }
        vis[u] = true;
        for (int k = 1; k <= n; k++) {
            if (graph[u][k] < INF && graph[u][k] + dis[u] < dis[k])
                dis[k] = dis[u] + graph[u][k];
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%3d", dis[i]);
    printf("\n");

    return 0;
}
