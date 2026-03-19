#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int n;
int visited[1002];
vector<int> adj[1002];
vector<vector<int>> mat(1001, vector<int> (1001));

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int s = q.front();
        cout << s << " ";
        q.pop();
        for(int i = 0;i < adj[s].size();++i){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
                visited[adj[s][i]] = 1;
            }
        }
    }
}

void reset(){
    for(int i = 1;i <= 1000;++i){
        adj[i].clear();
    }
    memset(visited, 0, sizeof(visited));
}

void solve(){
    reset();
    int k, start;
    cin >> n >> k >> start;
    // for(int i = 1;i <= n;++i){
    //     for(int j = 1;j <= n;++j){
    //         cin >> mat[i][j];
    //         if(mat[i][j]==1){
    //             adj[i].push_back(j);
    //             //adj[j].push_back(i);
    //         }
    //     }
    // }
    for(int i = 1;i <= k;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        //adj[v].pb(u);
    }
    bfs(start);
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;while(tc--){solve();}
    //solve();
    return 0;
}