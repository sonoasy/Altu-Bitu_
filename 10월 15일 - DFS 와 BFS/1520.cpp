#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>visited;
vector<vector<int>>dp;

int dx[4] = {0,0,1,-1}; //행
int dy[4] = {1,-1,0,0}; //열
int m, n; //행,열

//dfs -> 1.일단 가고 함수 앞에서 visited 체크하기 2.체크하고 함수 실행하기 
 
int dfs(int y,int x) {


    int currx = x; //행
    int curry = y; //열
    
    //dfs로 끝까지 갔다가 값을 리턴하는 알고리즘을 어떻게 작성할지 모르겠음
    //값 갱신을 visited에 하나?-> 일단 따로 dp로 (헷갈림) -> dp하나로
    //어렵다 y,x 또 틀림
    //visited써서 체크하는 방법도 있지만 dp만 사용하는 방법?
 
    if (x == n-1 && y ==m-1)  return dp[curry][currx]=1;  //n-1,m-1 조심하기!!
    //if (visited[y][x])return dp[y][x];
    if (dp[y][x]!=-1)return dp[y][x]; //방문했으면
  
    
    dp[curry][currx] = 0; //0으로해서 더하려고
   

    for (int i = 0; i < 4; i++) {
        int nextx = currx + dx[i];
        int nexty = curry + dy[i];

        if (nextx >= 0 && nextx < n && nexty >= 0 && nexty <m) {
            if (map[nexty][nextx] < map[curry][currx] ) { //작으면 통과 
                dp[curry][currx] += dfs(nexty, nextx);
               
            }
           
        }
    }
    
    return dp[curry][currx];



}
/**
 * [DFS + DP활용 문제]
 * dfs만 활용하면 시간초과
 * 따라서 경로의 경우의 수를 저장하며 탐색해야 함
 *
 * [BFS가 안되는 이유]
 * 주변 노드부터 탐색하다 갈 수 있는 경로에 이미 방문 처리가 되어 탐색 못할 수 있음
 * 주변 노드부터 탐색하므로 여러 경우의 수를 한 번에 탐색해서, 도착지점을 찍기 전이기 때문에 dp 활용이 불가
 */
int main() {

    //백준 1520번 
    //DFS+ DP   //시간초과 방지하기 위해서 이미 방문한곳이면 안감, dp는 갯수 세기 위하여 
    //이미 방문한곳이면 dp값을 리턴하기 
     //끝까지 안가서 dp 0일수도!
    cin >> m >> n;
    map.assign(m+1, vector<int>(n + 1, 0));
    visited.assign(m + 1, vector<int>(n + 1, 0));
    dp.assign(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];

        }
    }

   cout<< dfs(0,0);




    return 0;
}
