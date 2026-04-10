#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 505
#define maxval 1e9

int n;
unordered_map<string, int> d1, d2;
string defau = " 1238004765";

int bfs(string start){
    queue<string> q1, q2;

    q1.push(start);
    d1[start] = 0;

    q2.push(defau);
    d2[defau] = 0;

    while(!q1.empty() && !q2.empty()){
        //từ start đi
        int sz = q1.size();
        while(sz--){
            string s = q1.front(); q1.pop();
            int cur = d1[s];

            string tmp = s;
            int x[6] = {1, 2, 6, 9, 8, 4};
            int y[6] = {4, 1, 2, 6, 9, 8};
            for(int i = 0; i < 6; ++i)
                tmp[x[i]] = s[y[i]];
            
            //nếu gặp nhau lần đầu
            if(d2.count(tmp)) return cur + 1 + d2[tmp];

            if(!d1.count(tmp)){
                d1[tmp] = cur + 1;
                q1.push(tmp);
            }

            tmp = s;
            int x1[6] = {2, 3, 7, 10, 9, 5};
            int y1[6] = {5, 2, 3, 7, 10, 9};
            for(int i = 0; i < 6; ++i)
                tmp[x1[i]] = s[y1[i]];

            if(d2.count(tmp)) return cur + 1 + d2[tmp];

            if(!d1.count(tmp)){
                d1[tmp] = cur + 1;
                q1.push(tmp);
            }
        }
        
        //từ đích về
        sz = q2.size();
        while(sz--){
            string s = q2.front(); q2.pop();
            int cur = d2[s];

            string tmp = s;
            int x[6] = {1, 2, 6, 9, 8, 4};
            int y[6] = {2, 6, 9, 8, 4, 1};
            for(int i = 0; i < 6; ++i)
                tmp[x[i]] = s[y[i]];

            if(d1.count(tmp)) return cur + 1 + d1[tmp];

            if(!d2.count(tmp)){
                d2[tmp] = cur + 1;
                q2.push(tmp);
            }

            tmp = s;
            int x1[6] = {2, 3, 7, 10, 9, 5};
            int y1[6] = {3, 7, 10, 9, 5, 2};
            for(int i = 0; i < 6; ++i)
                tmp[x1[i]] = s[y1[i]];

            if(d1.count(tmp)) return cur + 1 + d1[tmp];

            if(!d2.count(tmp)){
                d2[tmp] = cur + 1;
                q2.push(tmp);
            }
        }
    }

    return -1;
}

void solve(){
    string source = " ";
    vector<int> start(11, 0);
    for(int i = 1;i <= 10;++i){
        cin >> start[i];
        source += to_string(start[i]);
    }
    cout << bfs(source);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tc;cin >> tc;while(tc--){solve();}
    solve();
    return 0;
}