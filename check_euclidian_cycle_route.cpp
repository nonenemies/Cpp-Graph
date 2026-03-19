#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 105

vector<set<int>> adj(maxn);
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
        int sz;
        cin >> sz;
        for(int j = 0; j < sz; j++) {
            int x; cin >> x;
            a[i][x] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j]) {
                out[i]++;
                in[j]++;
                adj[i].insert(j);
                adj[j].insert(i);
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

    int diff1 = 0;
    int diff2 = 0;

    for(int i = 1;i <= n;++i){
        if(out[i] - in[i] == 1){
            diff1++;
        }else if(in[i] - out[i] == 1){
            diff2++;
        }else if(in[i] == out[i]){
            continue;
        }else{
            cout << 0 << endl;
            return;
        }
    }
    if(diff1 == 0 && diff2 == 0){
        cout << 1 << endl;
    }else if(diff1 == 1 && diff2 == 1){
        cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
}

void find(){
    int n, u;
    cin >> n >> u;

    for(int i = 1;i <= n;++i){
        int val;
        cin >> val;
        while(val--){
            int j;
            cin >> j;
            a[i][j] = 1;
        }
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
                //a[i][s] = 0;
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
    int cas;
    cin >> cas;
    if(cas==1) check();
    else find();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}