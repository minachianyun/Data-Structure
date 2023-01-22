#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int u,v,w;
    edge(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const edge &b)const{
        return w>b.w;
    }
};

int find(vector<int> &f, int x){
    if(f[x] == x){
        return x;
    }
    f[x] = find(f, f[x]);
    return f[x];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vis(n,0);
    for(int i = 0; i < n; i++){
        vis[i] = i;
    }
    priority_queue<edge> q;
    int u,v,w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edge *t = new edge(u,v,w);
        q.push(*t);
    }
    long long sum = 0;
    int k = 0;
    while(k < n-1){
        edge a = q.top();
        q.pop();
        u = find(vis,a.u);
        v = find(vis,a.v);
        if(u == v)continue;
        sum = sum + a.w;
        vis[u] = v;
        k++;
    }
    cout << sum << endl;
}

