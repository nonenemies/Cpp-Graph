#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxv 105

int n, start;
int m = 0;
vector<int> visited(maxv, 0);
vector<vector<int>> mat(maxv, vector<int> (maxv));
vector<pair<int,pair<int,int>>> edge_pair;
vector<pair<int,pair<int,int>>> current_edge_set;

void prim(){
    int dh = 0;
    while(current_edge_set.size() < n - 1){
        int check = 0;
        for(int pos = 0; pos < edge_pair.size(); ++pos){
            int u = edge_pair[pos].second.first;
            int v = edge_pair[pos].second.second;
            int w = edge_pair[pos].first;
            if((visited[u] && !visited[v]) || (!visited[u] && visited[v])){
                int old = visited[u] ? u : v;
                int neww = (!visited[u]) ? u : v;
                current_edge_set.pb({edge_pair[pos].first,{min(old, neww), max(old, neww)}});
                dh += w;
                visited[neww] = 1;
                edge_pair.erase(edge_pair.begin() + pos);
                check = 1;
                break;
            }
        }
        if(check == 0){
            cout << 0 << endl;
            return;
        }
    }
    cout << dh << endl;
    for(int i = 0; i < current_edge_set.size(); ++i){
        cout << current_edge_set[i].second.first << " " << current_edge_set[i].second.second << " " << current_edge_set[i].first << endl;
    }
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

void solve(){
    cin >> n >> start;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mat[i][j];
            if(mat[i][j] != 0 && i < j){
                edge_pair.pb({mat[i][j], {i, j}});
                ++m;
            }
        }
    }
    sort(edge_pair.begin(), edge_pair.end(), cmp);
    visited[start] = 1;
    prim();
}

int main(){
    //freopen("CK.INP", "r", stdin);
    //freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}