#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dx가 열, dy가 행
int dx[8] = {-1,1,0,0,-1,1,-1,1}; //동,서,남,북, 대각선왼위,대각선오위,대각선왼아,대각선오아
int dy[8] = {0,0,1,-1,-1,-1,1,1};
int w, h; //너비, 높이
int visited[52][52] = { 0 };
int num = 0;

void check(vector<vector<int>> map,int y,int x) {//dfs

	int curx = x;
	int	cury = y;

	for (int i = 0; i < 8; i++) {
		int nextx = curx + dx[i];
		int nexty = cury + dy[i];
		
		if (nextx >= 0 && nextx < w && nexty >= 0 && nexty < h) {
			if (map[nexty][nextx] == 1 && visited[nexty][nextx]==0) {
				visited[nexty][nextx] = 1;
				//cout << "nextx:" << nextx<<'\n';
				//cout << "nexty:" << nexty<< '\n';
				check(map, nextx, nexty);
			}
		}

	}

}




int main() {

	//백준 4963번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	while (1) {
		
		cin >> w >> h;
		if (w == 0 || h == 0)break;
		//각 테스트 케이스에 대하여 지도 정보 입력 1은 땅,0은 바다
		vector<vector<int>>map(h, vector<int>(w, 0));
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j]==1 && visited[i][j] == 0) {
					visited[i][j]=1;
					//cout << i << " " << j << '\n';
	            	check(map,i,j);
					
					cnt++;
				}

			}
		}
		//visited 초기화 
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = 0;
			}
		}
		cout << cnt<<'\n';
	
	}
	
}
                         
