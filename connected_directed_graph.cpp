#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 105

vector<int> adj[maxn];
vector<vector<int>> a(maxn, vector<int>(maxn, 0));
vector<int> in(maxn, 0), out(maxn, 0);
vector<int> visited(maxn, 0);

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void check(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                adj[i].pb(j);
            }
        }
    }

    //liên thông mạnh ?
    int check = 1;
    for(int i = 1;i <= n;++i){
        dfs(i);
        for(int j = 1;j <= n;++j){
            if(!visited[j]){
                check = 0;
                break;
            }
        }
        visited.assign(n + 1, 0);
    }
    if(check == 1){
        cout << 1;
        return;
    }

    //liên thông yếu ?
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                adj[i].pb(j);
            }
        }
    }
    dfs(1);
    for(int i = 1;i <= n;++i){
        if(!visited[i]){
            cout << 0 << endl;
            return;
        }
    }
    cout << 2 << endl;
    return;
}

void solve(){
    check();
}

int main(){
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}