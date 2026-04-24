#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int item){
        key = item;
        left = NULL;
        right = NULL;
    }
};

Node* Search(Node* T, int x){
    Node* p;
    if(T == NULL)  
        return NULL; 
    if(T->key == x){ 
        //cout << "YES" << endl;
        return T;
    }
    p = Search(T->left, x);    
    if (p == NULL)  
        p = Search(T->right, x);
        return p;
}

void Add_Left(Node* T, int x, int y){
    Node *p, *q;
    p = Search (T, x); 
    if (p == NULL){ 
        return; 
    }
    else if ((p -> left) != NULL)       
        return;   
    else{ 
        q = new Node(y);  
        p -> left = q;  
    }
}

void Add_Right(Node* T, int x, int y){
    Node *p, *q;
    p = Search (T, x); 
    if (p == NULL){ 
        return; 
    }
    else if ((p -> right) != NULL)       
        return;   
    else{ 
        q = new Node(y);  
        p -> right = q;  
    }
}

void preOrder(Node* T){
    if(T != NULL){
        cout << T->key << " ";
        preOrder(T -> left);
        preOrder(T -> right);
    }
}

void inOrder(Node* T){
    if(T != NULL){ 
        preOrder(T -> left);
        cout << T->key << " ";
        preorder(T -> right);
    }
}

void postOrder(Node* T) {
    if(T != NULL){ 
        preOrder(T -> left);
        preorder(T -> right);
        cout << T->key << " ";
    }
}

// void bfs(int u){
//     queue<int> q;
//     q.push(u);
//     visited[u] = 1;
//     while(!q.empty()){
//         int s = q.front();
//         cout << s << " ";
//         q.pop();
//         for(int i = 0;i < adj[s].size();++i){
//             if(!visited[adj[s][i]]){
//                 q.push(adj[s][i]);
//                 visited[adj[s][i]] = 1;
//             }
//         }
//     }
// }

void LevelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        cout << cur->key << " ";
        if(cur->left != NULL)
            q.push(cur->left);
        if(cur->right != NULL)
            q.push(cur->right);
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        Node* root = NULL;
        int m;
        cin >> m;
        while(m--){
            int x, y;
            char c;
            cin >> x >> y >> c;
            if(root == NULL){
                root = new Node(x);
            }
            if(c == 'L'){
                Add_Left(root, x, y);
            }else{
                Add_Right(root, x, y);
            }
        }
        //LevelOrder(root);
        cout << endl;
    }
    return 0;
}