#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxv 105

int n, m, start;
vector<int> adj[maxv];
vector<int> visited(maxv, 0);
vector<vector<int>> mat(maxv, vector<int> (maxv));
vector<pair<int,pair<int,int>>> edge_pair;
vector<pair<int,pair<int,int>>> current_edge_set;

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int valid(int u, int v){
    visited.assign(n + 1, 0);
    dfs(u);
    if(visited[v]) return 0;
    return 1;
}

void kruskal(){
    int dh = 0;
    int pos = 0;
    while(current_edge_set.size() < n - 1 && edge_pair.size() != 0 && pos < edge_pair.size()){
        if(valid(edge_pair[pos].second.first, edge_pair[pos].second.second) == 1){
            current_edge_set.pb({edge_pair[pos].first, {edge_pair[pos].second.first, edge_pair[pos].second.second}});
            adj[edge_pair[pos].second.first].pb(edge_pair[pos].second.second);
            adj[edge_pair[pos].second.second].pb(edge_pair[pos].second.first);
            dh += edge_pair[pos].first;
        }
        ++pos;
    }
    if(current_edge_set.size() < n - 1){
        return;
    }
    cout << dh << endl;
    for(int i = 0;i < current_edge_set.size();++i){
        cout << current_edge_set[i].second.first << " " << current_edge_set[i].second.second << " " << current_edge_set[i].first << endl;
    }
}

bool cmp(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        int u, v, val;
        cin >> u >> v >> val;
        mat[u][v] = val;
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> mat[i][j];
            if(mat[i][j] != 0 && i < j){
                edge_pair.pb({mat[i][j],{i,j}});
            }
        }
    }
    sort(edge_pair.begin(), edge_pair.end(), cmp);
    kruskal();
}

int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}