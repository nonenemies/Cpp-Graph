#include<bits/stdc++.h>

using namespace std;

int n, m;
int parent[100001];
int num[100001];

void init(){
    for(int i = 1;i <= n;++i){
        parent[i] = i;
        num[i] = 1;
    }
}

int findset(int u){
    if(u != parent[u]){
        parent[u] = findset(parent[u]);
    }
    return parent[u];
}

void Union(int u, int v){
    int a = findset(u);
    int b = findset(v);
    if(a == b) return;
    if(num[a] < num[b]){
        swap(a, b);
    }
    num[a] += num[b];
    parent[b] = a;
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        Union(u,v);
    }
    int maxim = 0;
    for (int i = 2;i <= n;++i) {
        if (findset(i)!=findset(1)) {
            int root = findset(i);
            maxim = max(maxim,num[root]);
        }
    }
    cout << num[findset(1)] + maxim;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}