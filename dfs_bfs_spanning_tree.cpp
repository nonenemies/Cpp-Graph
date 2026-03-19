#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxv 105

int n, m, start;
vector<int> adj[maxv];
vector<int> visited(maxv, 0);
vector<vector<int>> mat(maxv, vector<int> (maxv));
vector<pair<int,int>> edge_pair;

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            edge_pair.pb({min(u,v), max(u,v)});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int i = 0;i < adj[s].size();++i){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
                visited[adj[s][i]] = 1;
                edge_pair.pb({min(s, adj[s][i]), max(s, adj[s][i])});
            }
        }
    }
}

void dfs_spanning_tree(){
    dfs(start);
    if(edge_pair.size() < n - 1){
        cout << 0 << endl;
    }else{
        cout << edge_pair.size() << endl;
        for(int i = 0;i < edge_pair.size();++i){
            cout << edge_pair[i].first << " " << edge_pair[i].second << endl;
        }
    }
}

void bfs_spanning_tree(){
    bfs(start);
    if(edge_pair.size() < n - 1){
        cout << 0 << endl;
    }else{
        cout << edge_pair.size() << endl;
        for(int i = 0;i < edge_pair.size();++i){
            cout << edge_pair[i].first << " " << edge_pair[i].second << endl;
        }
    }
}

void solve(){
    int tc;
    cin >> tc;
    cin >> n >> start;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                adj[i].pb(j);
                //adj[j].pb(i);
            }
        }
    }
    if(tc == 1){
        dfs_spanning_tree();
    }else{
        bfs_spanning_tree();
    }
}

int main(){
    //freopen("CT.INP", "r", stdin);
    //freopen("CT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}