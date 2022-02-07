#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>visited;

int dx[4] = {0,0,1,-1}; //행
int dy[4] = {1,-1,0,0}; //열
int m, n; //행,열
void dfs(int x,int y) {


    int currx = x; //행
    int curry = y; //열
    
    if (x == n && y == m)visited[currx][curry] = 1;

    if (visited[currx][curry])return;
    
    
    visited[currx][curry] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = currx + dx[i];
        int nexty = curry + dy[i];

        if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n) {

            visited[nextx][nexty] = 1;
            dfs(nextx, nexty);
        }
    }
    
    return 



}


int main() {

    //백준 1520번 
    //DFS+ DP   //시간초과 방지하기 위해서 이미 방문한곳이면 안감, dp는 갯수 세기 위하여 

   
    cin >> m >> n;
    map.assign(m+1, vector<int>(n + 1, 0));
    visited.assign(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j];

        }
    }

    dfs(0,0);








    return 0;
}
