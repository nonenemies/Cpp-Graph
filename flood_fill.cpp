#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 505
#define maxval 1e9

int n, m;
vector<vector<int>> a(maxn, vector<int>(maxn, 0));
vector<vector<int>> visited(maxn, vector<int>(maxn, 0));

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void fill(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m){
        return;
    } 
    if(visited[x][y]){
        return;
    } 
    if(a[x][y] == 0){
        return;
    } 

    visited[x][y] = 1;
    for(int i = 0; i < 8; i++){
        fill(x + dx[i], y + dy[i]);
    }
}

void solve(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            visited[i][j] = 0;
        }
    }

    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            if(a[i][j] == 1 && !visited[i][j]){
                ++cnt;
                fill(i, j);
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;cin >> tc;while(tc--){solve();}
    return 0;
}