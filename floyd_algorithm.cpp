#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e15;
const int NIL = 0;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> d(n + 1, vector<long long>(n + 1));
    vector<vector<int>> next_node(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long weight;
            cin >> weight;
            
            if (i == j) {
                d[i][j] = 0;
                next_node[i][j] = j;
            } else if (weight != 0) {
                d[i][j] = weight;
                next_node[i][j] = j;
            } else {
                d[i][j] = INF;
                next_node[i][j] = NIL;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        next_node[i][j] = next_node[i][k];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (next_node[i][j] == NIL && i != j) continue;

            cout << " K/c " << i << " -> " << j << " = " << d[i][j] << ";   " << i;
            
            int u = i;
            int v = j;
            while (u != v) {
                u = next_node[u][v];
                cout << " -->   " << u;
            }
            cout << endl;
        }
        if (i <= n) cout << endl;
    }

    return 0;
}