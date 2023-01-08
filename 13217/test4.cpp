#include <iostream>

using namespace std;

int T, V, Q,source,target;

int minDistance(int dist[], bool sptSet[])
{
    int min = 30000;
    int min_index = 0;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[],int tar)
{
        if (dist[tar] != 30000) {
            cout << dist[tar] << endl;
        }
        else {
            cout << "No Service" << endl;
        }     
}

void dijkstra(int** graph, int src,int tar)
{
    int* dist;
    dist = new int[V];

    bool* sptSet;
    sptSet = new bool[V];

    for (int i = 0; i < V; i++)
        dist[i] = 30000,sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != 30000
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist,tar);

    delete[] dist;
    delete[] sptSet;
}

int main()
{
    cin >> T;

    for (int j = 1; j <= T; j++) {
        cin >> V >> Q;

        int** Matrix = new int* [V];

        for (int i = 0; i < V; i++) {
            Matrix[i] = new int[V] {0};
        }

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cin >> Matrix[i][j];
            }
        }

        cout << "Testcase" << j << endl;
        for (int n = 0; n < Q; n++) {
            cin >> source >> target;
            cout << "Cost(" << source << "," << target << "):";
            dijkstra(Matrix, source , target);
        }

        for (int i = 0; i < V; i++) {
            delete[] Matrix[i];
        }

        delete[] Matrix;

    }

    return 0;
}