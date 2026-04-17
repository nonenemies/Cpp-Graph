#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[105][105];
bool blocked[105][105][4];
bool visited[105][105][4];

struct Node {
    int x, y, step;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int get_dir(char c) {
    if (c == '^') return 0;
    if (c == '>') return 1;
    if (c == 'v') return 2;
    if (c == '<') return 3;
    return -1;
}

void precompute() {
    memset(blocked, 0, sizeof(blocked));
    for (int t = 0; t < 4; ++t) {

        // tường hoặc lazer
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#' || get_dir(grid[i][j]) != -1) {
                    blocked[i][j][t] = true;
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int base_dir = get_dir(grid[i][j]);
                if (base_dir != -1) {
                    int curr_dir = (base_dir + t) % 4;
                    int nx = i + dx[curr_dir];
                    int ny = j + dy[curr_dir];
                    while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == '#' || get_dir(grid[nx][ny]) != -1) break;
                        blocked[nx][ny][t] = true;
                        nx += dx[curr_dir];
                        ny += dy[curr_dir];
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    int sx, sy, gx, gy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') { sx = i; sy = j; }
            if (grid[i][j] == 'G') { gx = i; gy = j; }
        }
    }
    precompute();

    memset(visited, 0, sizeof(visited));

    queue<Node> q;
    q.push({sx, sy, 0});
    visited[sx][sy][0] = true;
    
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();
        if (curr.x == gx && curr.y == gy) {
            cout << curr.step << endl;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int next_step = curr.step + 1;
            int next_t = next_step % 4;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !blocked[nx][ny][next_t] && !visited[nx][ny][next_t]) {
                visited[nx][ny][next_t] = true;
                q.push({nx, ny, next_step});
            }
        }
    }
    cout << "impossible" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        solve();
    }
    return 0;
}