#include <iostream>
#include <stack>

using namespace std;

// the level of operator
int level(char o){
    switch(o){
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        case ')': return 0;
        default: return -1;
    }
}

void change(string s){
    // op = operator
    stack<char> store, op;
    int len = s.size();
    
    for(int i = 0; i < len; i++){
        if(isdigit(s[i])){
            store.push(s[i]);
        }
        else if(s[i] == '('){
            op.push(s[i]);
        }
        else if(s[i] == ')'){
            char t = op.top();
            while(t != '('){
                op.pop();
                store.push(t);
                t = op.top();
            }
            // delete '('
            op.pop();
        }
        else if(level(s[i])>=1 && level(s[i])<=3){
            if(!op.empty()){
                char t = op.top();
                while(!op.empty() && level(s[i])<=level(t)){
                    if(level(s[i])==level(t) && s[i]=='^'){
                        break;
                    }
                    op.pop();
                    store.push(t);
                    if(!op.empty()){
                        t = op.top();
                    }
                }
            }
            op.push(s[i]);
        }
    }
    while(!op.empty()){
        char t = op.top();
        op.pop();
        store.push(t);
    }
    while(!store.empty()){
        char t = store.top();
        store.pop();
        op.push(t);
    }
    while(!op.empty()){
        char t = op.top();
        if(t != '(' && t != ')'){
            cout << t << ' ';
        }
        op.pop();
        store.push(t);
    }
    cout << endl;
}

void solve(){
    string input;
    getline(cin, input);
    string k = "";
    for(auto i: input){
        if(i != ' '){
            k = k + i;
        }
    }
    change(k);
}
int main(){
    string input;
    int num;
    cin >> num;
    getline(cin, input);
    while(num--){
        solve();
    }
    return 0;
}
