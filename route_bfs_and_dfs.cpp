#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define maxn 1005

int n, m, start, fin;
int cnt = 0;
int visited[maxn];
int parent[maxn];
vector<vector<int>> a(maxn, vector<int>(maxn, 0));
vector<int> adj[maxn];

void dfs(int u, int d){
    if(d > 2) return;
    if(d == 2 && u == fin) {
        cnt++;
        return;
    }
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v, d + 1);
        }
    }
    visited[u] = 0;
}

void dfs_route(int u){
    stack<int> st;
    st.push(u);
    visited[u] = 1;
    while(!st.empty()){
        int s = st.top();
        st.pop();
        for(int i = 0;i < adj[s].size();++i){
            if(!visited[adj[s][i]]){
                visited[adj[s][i]] = 1;
                st.push(s);
                st.push(adj[s][i]);
                parent[adj[s][i]] = s;
                break;
            }
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
                parent[adj[s][i]] = s;
            }
        }
    }
}

void route(int u, int v){
    if(u == v){
        cout << u;
        return;
    }
    bfs(u);
    if(!visited[v]){
        cout << -1;
        return;
    }
    vector<int> ans;
    ans.pb(v);
    int s = parent[v];
    while(s != u){
        ans.pb(s);
        s = parent[s];
    }
    ans.pb(u);
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << " ";
    }
}

void check(){
    dfs(start, 0);
    cout << cnt;
    return;
}

void solve(){
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    cin >> n >> m >> start >> fin;
    for(int i = 1;i <= n;++i){
        adj[i].clear();
    }
    for(int i = 1;i <= m;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    route(start, fin);
    cout << endl;
}

int main(){
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;cin >> tc;while(tc--){solve();}
    //solve();
    return 0;
}