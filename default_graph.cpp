#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxv 105

int n, m;
vector<int> adj[maxv];
vector<int> visited(maxv, 0);
vector<vector<int>> mat(maxv, vector<int> (maxv));

void dfs(int u){
    cout << u << " ";
    visited[u] = 1;
    for(int i = 0;i < adj[u].size();++i){
        if(!visited[adj[u][i]]){
            dfs(adj[u][i]);
        }
    }
}

void deg(){
    for(int i = 1;i <= n;++i){
        int cnt = 0;
        for(int j = 1;j <= n;++j){
            if(mat[i][j] == 1){
                cnt++;
            }
        }
        cout << cnt << " ";
    }
}

void edges(){
    vector<pair<int,int>> ans;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(mat[i][j]==1){
                mat[j][i] = 0;
                ans.pb({i,j});
            }
        }
    }
    cout << n << " " << ans.size() << endl;

    // for(int j = 0;j < ans.size();++j){
    //     cout << ans[j].first << " " << ans[j].second << endl;        
    // }

    //incidence_matrix
    for(int i = 1;i <= n;++i){
        for(int j = 0;j < ans.size();++j){
            if(i == ans[j].first || i == ans[j].second){
                cout << 1 << " ";
            }else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void adj_list(){
    cout << n << endl;
    vector<int> tmp;
    for(int i = 1;i <= n;++i){
        tmp.clear();
        for(int j = 1;j <= n;++j){
            if(mat[i][j]==1){
                tmp.pb(j);
            }
        }
        cout << tmp.size() << " ";
        for(int j = 0;j < tmp.size();++j){
            cout << tmp[j] << " ";
        }
        cout << endl;
    }
}

void matrix(){
    cout << n << endl;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void input_with_edges(){
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        int u, v;
        cin >> u >> v;
        mat[u][v] = mat[v][u] = 1;
    }
}

void input_with_adjlist(){
    cin >> n;
    for(int i = 1;i <= n;++i){
        int val;
        cin >> val;
        for(int j = 1;j <= val;++j){
            int a;
            cin >> a;
            mat[i][a] = 1;
            mat[a][i] = 1;
        }
    }
}

void solve(){
    int t;
    cin >> t;
    if(t==1){
        input_with_adjlist();
        deg();
    }
    else{
        input_with_adjlist();
        edges();
    } 
}

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}