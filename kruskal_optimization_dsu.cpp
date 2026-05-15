#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxv 200005

int n, m, start;

vector<int> adj[maxv];

vector<pair<int,pair<int,int>>> edge_pair;
vector<pair<int,pair<int,int>>> current_edge_set;

vector<int> parent(maxv, -1);

int findset(int u){
    if(u != parent[u]){
        parent[u] = findset(parent[u]);
    }
    return parent[u];
}

int valid(int u, int v){
    return findset(u) != findset(v);
}

void init(){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
        adj[i].clear();
    }
}

void Union(int u, int v){
    int a = findset(u);
    int b = findset(v);
    if(a == b) return;
    parent[b] = a;
}

bool cmp(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

void kruskal(){
    ll dh = 0;
    int pos = 0;
    while(current_edge_set.size() < n - 1 && pos < edge_pair.size()){
        int u = edge_pair[pos].second.first;
        int v = edge_pair[pos].second.second;
        int val = edge_pair[pos].first;
        if(valid(u, v) == 1){
            Union(u, v);
            current_edge_set.pb({val, {u, v}});
            adj[u].pb(v);
            adj[v].pb(u);
            dh += val;
        }
        ++pos;
    }
    cout << dh << endl;
}

void solve(){
    cin >> n >> m;

    edge_pair.clear();
    current_edge_set.clear();
    init();

    for(int i = 1; i <= m; ++i){
        int u, v, val;
        cin >> u >> v >> val;
        edge_pair.pb({val,{u,v}});
    }
    sort(edge_pair.begin(), edge_pair.end(), cmp);
    kruskal();
}

int main(){
    //freopen("CK.INP", "r", stdin);
    //freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}