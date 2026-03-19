#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> adj[105];
int visited[105];

void dfs(int u){
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
                break;
            }
        }
    }
}

void cut_vertex(){
    int ans = 0;
    for(int i = 1;i <= n;++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    vector<int> fin;
    for(int i = 1;i <= n;++i){
        int cnt = 0;
        visited[i] = 1;
        for(int j = 1;j <= n;++j){
            if(!visited[j]){
                ++cnt;
                dfs(j);
            }
        }
        if(cnt > ans){
            fin.push_back(i);
        }
        memset(visited, 0, sizeof(visited));
    }
    cout << fin.size() << endl;
    for(int i = 0;i < fin.size();++i){
        cout << fin[i] << " ";
    }
}

void solve(){
    cin >> n;
    vector<vector<int>> mat(n + 1, vector<int> (n+1));
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> mat[i][j];
            if(mat[i][j]==1 && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    cut_vertex();
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}