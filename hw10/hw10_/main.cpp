#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void dijstra(vector<vector<long long>> &adj, int end, vector<long long> &dis){
    vector<bool> vis(adj.size(), false);
    for(int i = 0; i < adj.size(); i++){
        int pos = 0, min = INT_MAX;
        for(int j = 0; j < adj.size(); j++){
            if (!vis[j] && dis[j] < min){
                pos = j;
                min = dis[j];
            }
        }
        vis[pos] = true;
        for(int j = 0; j < adj.size(); j++){
            if (!vis[j] && adj[pos][j] + min < dis[j])
                dis[j] = adj[pos][j] + min;
        }
    }
    cout<<dis[end];
}
int main() {
    int n;
    cin >> n;
    int start, end;
    cin >> start >> end;
    vector<vector<long long>> adj(n, vector<long long>(n, INT_MAX));
    vector<long long> dis(n, INT_MAX);
    dis[start] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 0){
                adj[i][j] = INT_MAX;
            }
        }
    }
    dijstra(adj, end, dis);
}

