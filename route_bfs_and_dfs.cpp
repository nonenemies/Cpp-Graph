#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define maxn 105

int n, start, fin;
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
    dfs_route(u);
    if(!visited[v]){
        cout << 0;
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
    int cas;
    cin >> cas;
    cin >> n >> start >> fin;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                adj[i].pb(j);
            }
        }
    }
    if(cas == 1){
        check();
    }else{
        route(start, fin);
    }
}

int main(){
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}