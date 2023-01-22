#include<iostream>
#include <vector>

using namespace std;

typedef struct node{
    int val;
    struct node *left, *right;
}node;

vector<node*> p;

// VLR
void preOrder(node *root){
    if(root != NULL){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// LVR
void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

// LRV
void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

node *createNode(int val){
    node *now = new node();
    now->val = val;
    now->left = now->right = NULL;
    return now;
}

int main(){
    // the number of test cases
    int test;
    cin >> test;
    while(test--){
        p.clear();
        
        // number of node
        int num;
        cin >> num;
        
        // store value of each node in tree
        for(int i = 0; i < num; i++){
            // value of each node
            int x;
            cin >> x;
            p.push_back(createNode(x));
        }
        
        // test if they have child
        for(int i = 0; i < num; i++){
            if((i*2 + 1) < num){
                p[i]->left = p[i*2+1];
            }
            if((i*2 + 2) < num){
                p[i]->right = p[i*2+2];
            }
        }
        
        preOrder(p[0]);
        cout << endl;
        inOrder(p[0]);
        cout << endl;
        postOrder(p[0]);
        cout << endl;
    }
}

