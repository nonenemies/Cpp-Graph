#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 505
#define maxval 1e9

int n;
unordered_map<string, int> visited; 
string source = "";
string ending = "";

void bfs(string u){
    queue<pair<int,string>> q;
    q.push({0, u});
    visited[u] = 1;

    while(!q.empty()){
        int cur = q.front().first;
        string s = q.front().second;
        q.pop();

        cout << cur << " " << s << endl;

        if(s == ending){
            cout << cur;
            return;
        }

        string tmp;

        tmp = s;
        char a = s[1], b = s[2], c = s[4], d = s[5];
        tmp[1] = c; tmp[2] = a; tmp[4] = d; tmp[5] = b;

        if(!visited[tmp]){
            visited[tmp] = 1;
            q.push({cur + 1, tmp});
        }

        tmp = s;
        a = s[0]; b = s[1]; c = s[3]; d = s[4];
        tmp[0] = c; tmp[1] = a; tmp[3] = d; tmp[4] = b;

        if(!visited[tmp]){
            visited[tmp] = 1;
            q.push({cur + 1, tmp});
        }
    }
}

void solve(){
    vector<int> start(7, 0);
    vector<int> dest(7, 0);
    for(int i = 1;i <= 6;++i){
        cin >> start[i];
        source += to_string(start[i]);
    }
    for(int i = 1;i <= 6;++i){
        cin >> dest[i];
        ending += to_string(dest[i]);
    }
    bfs(source);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}