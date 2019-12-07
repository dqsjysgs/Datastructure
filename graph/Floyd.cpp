#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 100000;
int main(void) {
    int graph[5][5];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    int n, m; 
    //n is the number of vertexs, m is the number of edges
    cin >> n >> m;

    //Enter edges
    int v1, v2, dis;
    for (int i = 1; i <= m; i++) {
        cin >> v1 >> v2 >> dis;
        graph[v1][v2] = dis;
    }
    
    //key code of Floyd algorithm
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    //print result
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
