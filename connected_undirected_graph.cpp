#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 105

vector<int> adj[maxn];
vector<vector<int>> a(maxn, vector<int>(maxn, 0));
vector<int> in(maxn, 0), out(maxn, 0);
vector<int> visited(maxn, 0);
vector<set<int>> ans;


void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    set<int> tmp;
    while(!q.empty()){
        int s = q.front();
        tmp.insert(s);
        q.pop();
        for(int i = 0;i < adj[s].size();++i){
            if(!visited[adj[s][i]]){
                q.push(adj[s][i]);
                visited[adj[s][i]] = 1;
            }
        }
    }
    ans.push_back(tmp);
}

void dfs(int u){
    stack<int> st;
    st.push(u);
    visited[u] = 1;
    set<int> tmp;
    while(!st.empty()){
        int s = st.top();
        tmp.insert(s);
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
    ans.push_back(tmp);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                adj[i].pb(j);
            }
        }
    }

    for(int i = 1;i <= n;++i){
        if(!visited[i]){
            dfs(i);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();++i){
        for(auto v : ans[i]){
            cout << v << " ";
        }
        cout << endl;
    }
}

int main(){
    //freopen("TK.INP", "r", stdin);
    //freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}