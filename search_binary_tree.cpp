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

Node* insert(Node* node, int X){
    if(node == NULL)
        return new Node(X);
    if(node->key == X)
        return node;

    if(node->key < X)
        node->right = insert(node->right, X);
    else
        node->left = insert(node->left, X);
    
    return node;
}

void leaf(Node* T){
    if(T == NULL) return;
    if(T->left == NULL && T->right == NULL){
        cout << T->key << " ";
        return;
    }
    leaf(T->left);
    leaf(T->right);
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        Node* root = NULL;
        int n;
        cin >> n;
        while(n--){
            int x;
            cin >> x;
            root = insert(root, x);     
        }
        leaf(root);
        cout << endl;
    }
}