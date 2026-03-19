#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> adj[105];
bool visited[105];
int path[105];

vector<vector<int>> ans;

void print_cycle(){
    vector<int> tmp;
    for(int i = 1; i <= n; i++){
        tmp.push_back(path[i]);
    }
    tmp.push_back(s);
    ans.push_back(tmp);
}

void Try(int pos){
    int u = path[pos - 1];
    for (int v : adj[u]){
        if (!visited[v]){
            path[pos] = v;
            visited[v] = true;
            if (pos == n) {
                for(int x : adj[v]){
                    if(x == s){
                        print_cycle();
                        break;
                    }
                }
            }else{
                Try(pos + 1);
            }
            visited[v] = false;
        }
    }
}

int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> s;
    int mat[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0 && mat[i][j] != 10000){
                adj[i].push_back(j);
            }
        }
    }
    path[1] = s;
    visited[s] = true;
    Try(2);
    if(ans.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0;i < ans.size();++i){
        for(auto v : ans[i]){
            cout << v << " ";
        }
        cout << endl;
    }
    cout << ans.size() << endl;
}