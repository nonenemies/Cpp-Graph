#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 105
#define maxval 1e9

int n, start;
vector<int> adj[maxn];
vector<vector<int>> a(maxn, vector<int>(maxn, 0));
vector<int> visited(maxn, 0);
vector<int> parent(maxn, 0);
vector<int> opt(maxn, maxval);

void dijkstra(int start){
    vector<int> ans;
    ans.push_back(start);

    opt[start] = 0;
    visited[start] = 1;
    parent[start] = start;

    for(int i = 1;i <= n;++i){
        if(i != start){
            if(a[start][i] != maxval){
                opt[i] = a[start][i];
            }
            parent[i] = start;
        }
    }

    while(true){
        int check = 0;
        for(int i = 1;i <= n;++i){
            if(!visited[i]){
                check = 1;
            }
        }
        
        if(check == 0){
            break;
        }

        int min_pos = -1;
        int min_opt = 2e9;
        for(int i = 1;i <= n;++i){
            if(!visited[i] && opt[i] < min_opt){
                min_pos = i;
                min_opt = opt[i];
            }
        }

        visited[min_pos] = 1;

        for(int i = 1;i <= n;++i){
            if(!visited[i] && a[min_pos][i] != maxval && min_pos != i){
                if(opt[i] > opt[min_pos] + a[min_pos][i]){
                    opt[i] = opt[min_pos] + a[min_pos][i];
                    parent[i] = min_pos;
                }
            }
        }
    }

    vector<int> tmp = parent;
    for(int i = 1;i <= n;++i){
        if(opt[i] == maxval){
            cout << "K/c " << start << " -> " << i << " = " << "INF" << endl;
            continue;
        }
        cout << "K/c " << start << " -> " << i << " = " << opt[i] << ";        ";
        int cur = i;
        while(cur != start){
            cout << cur << " <- ";
            cur = parent[cur];
        }
        if(i == start){
            cout << start << " <- " << start << endl;
        }else{
            cout << start << endl;
        }
    }
}

void solve(){
    cin >> n >> start;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cin >> a[i][j];
            if(a[i][j] == 0 && i != j){
                a[i][j] = maxval;
            }
        }
    }
    dijkstra(start);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}