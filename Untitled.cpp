#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<int> adj[1002];
vector<int> visited(1002, 0);

void dfs(int u){
    visited[u] = 1;
    for(int i = 0;i < adj[u].size();++i){
        if(!visited[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
}

void reset(){
    for(int i = 1;i <= 1000;++i){
        adj[i].clear();
    }
    visited.assign(1002, 0);
}

void check(){
    int n, k;
    cin >> n >> k;

    for(int i = 1;i <= k;++i){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1); 
    
    for(int i = 1;i <= n;++i){
        if(!visited[i]){
            cout << 0 << endl;
            return;
        }
    }

    int cnt = 0;
    for(int i = 1;i <= n;++i){
        if(adj[i].size() % 2 == 1){
            ++cnt;
        }
    }
    if(cnt == 0){
        cout << 1 << endl;
    }else if(cnt == 2){
        cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
}

int a[105][105];
void find(){
    int n, m, u;
    cin >> n >> m >> u;
    for(int i = 1;i <= m;++i){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    stack<int> st;
    vector<int> ans;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        bool has_edge = false;
        for (int i = 1; i <= n; ++i){
            if (a[s][i] == 1){
                st.push(i);
                a[s][i] = 0;
                a[i][s] = 0;
                has_edge = true;
                break;
            }
        }
        if(!has_edge){
            ans.push_back(s);
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    if(n==1) check();
    else find();
}

int main(){
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}