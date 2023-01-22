#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> p;

typedef struct node{
    // node val
    int val;
    // left child and right child
    struct node *l,*r;
}node;

// insert
node *insertNode(int val, node *root){
    if(root == NULL){
        root = new node();
        root->val = val;
        root->l = root->r = NULL;
        return root;
    }
    if(val < root->val){
        root->l = insertNode(val, root->l);
    }
    else{
        root->r = insertNode(val,root->r);
    }
    return root;
}
// check if the number exit in the tree
bool exist(int val,node *root){
    if(root == NULL){
        return false;
    }
    if(val == root->val){
        return true;
    }
    if(val < root->val){
        return exist(val, root->l);
    }
    else{
        return exist(val, root->r);
    }
}

int findMax(node *root){
    if(root->r == NULL){
        return root->val;
    }
    return findMax(root->r);
}

// search: apply preorder traveral to find the min value
void preOrder(node *root){
    if(root != NULL){
        p.push_back(root->val);
        preOrder(root->l);
        preOrder(root->r);
    }
}

// delete
node* deleteNode(int val,node *root){
    if(root == NULL){
        return NULL;
    }
    if(val == root->val){
        if(root->l == NULL && root->r == NULL){
            return NULL;
        }
        if(root->l == NULL){
            return root->r;
        }
        if(root->r == NULL){
            return root->l;
        }
        int num = findMax(root->l);
        root->l = deleteNode(num, root->l);
        root->val = num;
        return root;
    }
    if(val < root->val){
        root->l = deleteNode(val, root->l);
    }
    else{
        root->r = deleteNode(val, root->r);
    }
    return root;
}
// height
int height(node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->l), height(root->r))+1;
}
// level-order traversal
void traversal(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *now = q.front();
        q.pop();
        if(now == NULL)continue;
        cout << now->val << " ";
        q.push(now->l);
        q.push(now->r);
    }
    cout << endl;
}
int main(){
    string s;
    node *root = NULL;
    while(true){
        // 指令
        cin >> s;
        // insert
        if(s == "insert"){
            int x;
            // insert number
            cin >> x;
            root = insertNode(x, root);
        }
        // delete
        if(s == "delete"){
            int x;
            // delete number
            cin >> x;
            // check if the number exist in the tree
            if(!exist(x,root)){
                cout << "cannot delete" << endl;
                continue;
            }
            root = deleteNode(x,root);
        }
        // search
        if(s == "search"){
            int x;
            // search for the xth min number
            cin >> x;
            p.clear();
            // apply preorder traversal to find the xth min number
            preOrder(root);
            sort(p.begin(),p.end());
            cout << p[x-1] << endl;
        }
        // height
        if(s == "height"){
            cout << height(root) << endl;
        }
        // traversal
        if(s == "traversal"){
            // level-order traversal
            traversal(root);
            break;
        }
    }
}
