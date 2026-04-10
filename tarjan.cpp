#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 10001
#define maxval 1e9

int n, m;
vector<int> adj[maxn];
vector<int> low(maxn);
vector<int> num(maxn);
vector<int> tail(maxn);

vector<bool> isCut(maxn, false);
int bridges = 0;
int timeDFS = 0;

void DFS(int u, int pre){
    num[u] = low[u] = ++timeDFS;
    int children = 0;
    for(auto v : adj[u]) if(v != pre){
        if(!num[v]){
            DFS(v, u);
            ++children;
            low[u] = min(low[u], low[v]);

            if(low[v] > num[u]){
                ++bridges;
            }

            if(pre != -1 && low[v] >= num[u]){
                isCut[u] = true;
            }
        }else{
            low[u] = min(low[u], num[v]);
        }
    }
    //tail[u] = timeDFS;
    if(pre == -1 && children > 1){
        isCut[u] = true;
    }
}

void solve(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1; i <= n; ++i){
        if(!num[i]){
            DFS(i, -1);
        }
    }

    int cut_vertex =  0;
    for(int i = 1; i <= n; ++i){
        if(isCut[i]){
            ++cut_vertex;
        } 
    }
    cout << cut_vertex << " " << bridges;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}