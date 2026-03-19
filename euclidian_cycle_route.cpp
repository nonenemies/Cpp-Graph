#include <bits/stdc++.h>

using namespace std;

int n, start;
int a[105][105];

void euclide_cycle(int u){
    stack<int> st;
    vector<int> ans;
    st.push(u);
    while(!st.empty()){
        int s = st.top();
        bool has_edge = false;
        for (int i = 1; i <= n; ++i){
            if (a[s][i] == 1){
                st.push(i);
                a[s][i] = 0;
                a[i][s] = 0;
                has_edge = true;
                break;
            }
        }
        if(!has_edge){
            ans.push_back(s);
            st.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> n >> start){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                cin >> a[i][j];
            }
        }
        euclide_cycle(start);
    }
    return 0;
}