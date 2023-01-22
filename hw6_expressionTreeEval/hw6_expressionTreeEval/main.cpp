#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long tree;

typedef struct node{
    string s;
    // left child and right child
    struct node *L,*R;
}node;

node *a[2000000];

// check if it is operand
bool isOperand(string s){
    if(s == "+" || s == "-" || s == "*" || s == "/"){
        return true;
    }
    return false;
}

tree change(string s){
    if(s == "-1"){
        return -1;
    }
    tree sum = 0;
    for(tree i = 0; i < s.size(); i++){
        sum = sum*10 + s[i]-'0';
    }
    return sum;
}

tree getNum(node *root){
    if(root == NULL){
        return 0;
    }
    if(isOperand(root->s)){
        tree left = getNum(root->L);
        tree right = getNum(root->R);
        if(root->s == "+"){
            return (left + right);
        }
        if(root->s == "-"){
            return (left - right);
        }
        if(root->s == "*"){
            return (left * right);
        }
        if(root->s == "/"){
            return (left / right);
        }
    }
    else{
        tree num = change(root->s);
        return num;
    }
    return 0;
}

int main()
{
    // the height of the tree
    tree n;
    cin >> n;
    // total node of the tree
    tree total_node = pow(2,n)-1;
    
    for(tree i = 1; i <= total_node; i++){
        a[i] = new node();
        a[i]->L = a[i]->R = NULL;
        cin >> a[i]->s;
    }
    for(tree i = 1; i <= total_node; i++){
        // left child
        if(i*2 <= total_node && a[i*2]->s != "-1"){
            a[i]->L = a[i*2];
        }
        // right child
        if(i*2+1 <= total_node && a[i*2+1]->s != "-1"){
            a[i]->R = a[i*2+1];
        }
    }
    cout << getNum(a[1]) << endl;
}
