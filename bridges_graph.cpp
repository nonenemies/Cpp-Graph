#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> a;
vector<int> visited;

void dfs(int u){
    visited[u] = 1;
    for(int v = 1; v <= n; ++v){
        if(a[u][v] && !visited[v]){
            dfs(v);
        }
    }
}

int countComponents(){
    visited.assign(n+1, 0);
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            ++cnt;
            dfs(i);
        }
    }
    return cnt;
}

void solve(){
    cin >> n;
    a.assign(n+1, vector<int>(n+1));
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
        }
    }
    int original = countComponents();
    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            if(a[i][j]){
                a[i][j] = a[j][i] = 0;
                int after = countComponents();
                if(after > original){
                    ans.push_back({i,j});
                }
                a[i][j] = a[j][i] = 1;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();++i){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main(){
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc; cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}