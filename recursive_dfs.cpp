#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<int> adj[1002];
vector<int> visited(1002, 0);

void dfs(int u){
    cout << u << " ";
    visited[u] = 1;
    for(int i = 0;i < adj[u].size();++i){
        if(!visited[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
}

void solve(){
    int n, k, start;
    cin >> n >> k >> start;
    for(int i = 1;i <= 1000;++i){
        adj[i].clear();
    }
    visited.assign(1002,0);
    // vector<vector<int>> mat(n + 1, vector<int> (n+1));
    // for(int i = 1;i <= n;++i){
    //     for(int j = 1;j <= n;++j){
    //         cin >> mat[i][j];
    //         if(mat[i][j]==1 && i < j){
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }
    //     }
    // }
    for(int i = 1;i <= k;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        //adj[v].pb(u);
    }
    dfs(start);
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;cin >> tc;while(tc--){solve();}
    //solve();
    return 0;
}