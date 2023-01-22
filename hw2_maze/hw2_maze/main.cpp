#include <iostream>
#include <stack>
using namespace std;

const int maxn = 105;

// 方向數組
int direction_x[] = {1, 0, -1, 0};
int direction_y[] = {0, 1, 0, -1};
int maze[maxn][maxn];

// 檢查是否已經走過
bool visited[maxn][maxn];

// 檢查有沒有成功抵達出口
bool success;

int row, column;

struct node {
    int x, y;
};

stack<node> history, ans;

bool check(int x, int y) {
    return (x >= 0 && x < row && y >= 0 && y < column);
}

void dfs(int x, int y) {
    if(x == row - 1 && y == column - 1) {
        success = true;
        // 將原本放置在history中的位置放入ans中（因為需要從開始路徑到終點的順序）
        while (!history.empty()) {
            ans.push(history.top());
            history.pop();
        }
        // 當轉移好之後就一一輸出
        while (!ans.empty()) {
            cout << "(" << ans.top().x << ","<<ans.top().y << ") ";
            history.push(ans.top());
            ans.pop();
        }
        return;
    }
    // find path
    // total four direction
    for(int i = 0; i < 4; ++i) {
        int new_x = x + direction_x[i];
        int new_y = y + direction_y[i];
      
        if(check(new_x, new_y) && !visited[new_x][new_y] && maze[new_x][new_y] == 0) {
            visited[new_x][new_y] = true;
            history.push((node){new_x, new_y});
            dfs(new_x, new_y);
            visited[new_x][new_y] = false;
            history.pop();
        }
    }
}

int main() {
    cin >> row >> column;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++){
            cin >> maze[i][j];
        }
    }
    // 先定義還沒成功
    success = false;
    visited[0][0] = true;
    history.push((node){0, 0});
    dfs(0, 0);
    
    if(!success){
        cout << "Can't reach the exit!";
    }
    return 0;
}
