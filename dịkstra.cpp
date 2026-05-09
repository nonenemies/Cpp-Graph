#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 1005
#define maxval 1e15

int n, m, start;
vector<int> adj[maxn];
vector<vector<ll>> a(maxn, vector<ll>(maxn, 0));
vector<int> visited(maxn, 0);
vector<int> parent(maxn, 0);
vector<ll> opt(maxn, maxval);

void dijkstra(int start){
    opt[start] = 0;
    parent[start] = start;

    while(true){
        int min_pos = -1;
        ll min_opt = maxval;

        for(int i = 1; i <= n; ++i){
            if(!visited[i] && opt[i] < min_opt){
                min_opt = opt[i];
                min_pos = i;
            }
        }

        if(min_pos == -1) break;

        visited[min_pos] = 1;
        for(int i = 1; i <= n; ++i){
            if(a[min_pos][i] == maxval)
                continue;
            if(opt[i] > opt[min_pos] + a[min_pos][i]){
                opt[i] = opt[min_pos] + a[min_pos][i];
                parent[i] = min_pos;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << opt[i] << " ";
    }

    cout << endl;
}

void reset(){
    visited.assign(maxn, 0);
    parent.assign(maxn, 0);
    opt.assign(maxn, maxval);
}

void solve(){
    reset();
    cin >> n >> m >> start;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            a[i][j] = maxval;
        }
        a[i][i] = 0;
    }
    for(int i = 1;i <= m;++i){
        int u, v, w;
        cin >> u >> v >> w;
        if(w < a[u][v]){
            a[u][v] = w;
            a[v][u] = w;
        }
    }
    dijkstra(start);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;cin >> tc;while(tc--){solve();}
    return 0;
}