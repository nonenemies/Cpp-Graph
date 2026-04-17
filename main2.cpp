#include<bits/stdc++.h>

using namespace std;

int n, m;

char mapping[101][101][5];
pair<int, int> start;
pair<int, int> target;

void init(){
    for(int i = 2;i <= 4;++i){
        // xoay
        for(int j = 0;j < n;++j){
            for(int k = 0;k < m;++k){
                if(mapping[j][k][i - 1] == '>'){
                    mapping[j][k][i] = 'v';
                }else if(mapping[j][k][i - 1] == 'v'){
                    mapping[j][k][i] = '<';
                }else if(mapping[j][k][i - 1] == '<'){
                    mapping[j][k][i] = '^';
                }else if(mapping[j][k][i - 1] == '^'){
                    mapping[j][k][i] = '>';
                }else{
                    mapping[j][k][i] = mapping[j][k][1];
                }
            }
        }

        // cập nhật map
        for(int j = 0;j < n;++j){
            for(int k = 0;k < m;++k){
                if(mapping[j][k][i] == '^'){
                    int pos = j - 1;
                    while(pos >= 0){
                        if(mapping[pos][k][i] == '#' || mapping[pos][k][i] == '^' ||
                        mapping[pos][k][i] == '>' || mapping[pos][k][i] == 'v' || mapping[pos][k][i] == '<'){
                            break;
                        }else{
                            mapping[pos][k][i] = '#';
                        }
                        pos--;
                    }
                }
                if(mapping[j][k][i] == '>'){
                    int pos = k + 1;
                    while(pos < m){
                        if(mapping[j][pos][i] == '#' || mapping[j][pos][i] == '^' ||
                        mapping[j][pos][i] == '>' || mapping[j][pos][i] == 'v' || mapping[j][pos][i] == '<'){
                            break;
                        }else{
                            mapping[j][pos][i] = '#';
                        }
                        pos++;
                    }
                }
                if(mapping[j][k][i] == 'v'){
                    int pos = j + 1;
                    while(pos < n){
                        if(mapping[pos][k][i] == '#' || mapping[pos][k][i] == '^' ||
                        mapping[pos][k][i] == '>' || mapping[pos][k][i] == 'v' || mapping[pos][k][i] == '<'){
                            break;
                        }else{
                            mapping[pos][k][i] = '#';
                        }
                        pos++;
                    }
                }
                if(mapping[j][k][i] == '<'){
                    int pos = k - 1;
                    while(pos >= 0){
                        if(mapping[j][pos][i] == '#' || mapping[j][pos][i] == '^' ||
                        mapping[j][pos][i] == '>' || mapping[j][pos][i] == 'v' || mapping[j][pos][i] == '<'){
                            break;
                        }else{
                            mapping[j][pos][i] = '#';
                        }
                        pos--;
                    }
                }
            }
        }
    }
}

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visited[101][101][5];
int check = 0;

int valid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return 1;
    }
    return 0;
}

void bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push({{start.first, start.second}, 1});
    visited[start.first][start.second][1] = true;
    int stage = 1;

    while(!q.empty()){
        int size = q.size();

        for(int k = 0; k < size;++k){
            pair<pair<int,int>, int> cur = q.front();
            q.pop();

            if(cur.first.first == target.first && cur.first.second == target.second){
                check = 1;
                cout << stage << endl;
                return;
            }

            cout << cur.first.first << " " << cur.first.second << " " << stage << endl;

            for(int i = 0;i < 4;++i){
                int new_x = cur.first.first + dx[i];
                int new_y = cur.first.second + dy[i];
                int new_stage = (stage + 1) % 4;
                
                if(valid(new_x, new_y) && !visited[new_x][new_y][new_stage]){
                    if(mapping[new_x][new_y][new_stage] == '.'){
                        visited[new_x][new_y][new_stage] = true;
                        q.push({{new_x, new_y}, stage});
                    }
                }
            }
        }
        stage += 1;
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            cin >> mapping[i][j][1];
            if(mapping[i][j][1] == 'S'){
                start.first = i;
                start.second = j;
            }
            if(mapping[i][j][1] == 'G'){
                target.first = i;
                target.second = j;
            }
        }
    }
    init();
    bfs();
    if(check == 0){
        cout << "impossible" << endl;
    }
}

int main(){
    int tc;cin >> tc;while(tc--){solve();}
}