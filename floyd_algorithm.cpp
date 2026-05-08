#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e15;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> d(n + 1, vector<long long>(n + 1));
    //vector<vector<int>> next_node(n + 1, vector<int>(n + 1));

    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    for(int i = 1;i <= m;++i){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        //next_node[i][j] = next_node[i][k];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << d[u][v] << endl;
    }

    return 0;
}