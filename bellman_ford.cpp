#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 105
#define maxval 1e9

int n, m, start;
vector<vector<int>> a(maxn, vector<int>(maxn, maxval));
vector<int> parent(maxn, -1);
vector<int> opt(maxn, maxval);

void bellman_ford(int start){
    opt[start] = 0;
    parent[start] = start;

    for(int k = 1; k <= n - 1; ++k){
        for(int u = 1; u <= n; ++u){
            if(opt[u] == maxval) continue;
            for(int v = 1; v <= n; ++v){
                if(a[u][v] == maxval) continue;
                if(opt[v] > opt[u] + a[u][v]){
                    opt[v] = opt[u] + a[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    bool negative_cycle = false;

    for(int u = 1; u <= n; ++u){
        if(opt[u] == maxval) continue;
        for(int v = 1; v <= n; ++v){
            if(a[u][v] == maxval) continue;
            if(opt[v] > opt[u] + a[u][v]){
                negative_cycle = true;
            }
        }
    }

    if(negative_cycle){
        cout << "Co chu trinh am";
        return;
    }

    for(int i = 1; i <= n; ++i){
        if(opt[i] == maxval){
            cout << "K/c " << start << " -> " << i << " = INF\n";
            continue;
        }

        cout << "K/c " << start << " -> " << i << " = " << opt[i] << ";        ";
        int cur = i;
        while(cur != start){
            cout << cur << " <- ";
            cur = parent[cur];
        }
        cout << start << '\n';
    }
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            a[i][j] = maxval;
        }
    }

    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    bellman_ford(1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}