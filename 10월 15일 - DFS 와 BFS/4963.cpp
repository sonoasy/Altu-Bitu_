#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dx가 열, dy가 행
int dx[8] = { -1,1,0,0,-1,1,-1,1 }; //동,서,남,북, 대각선왼위,대각선오위,대각선왼아,대각선오아
int dy[8] = { 0,0,1,-1,-1,-1,1,1 };
int w, h; //너비, 높이
int visited[52][52] = { 0 };
int num = 0;
vector<vector<int>>map(51, vector<int>(51, 0));
void check(int y, int x) {//dfs
	
	int	cury = y; //행
	int curx = x;//열
	


	for (int i = 0; i < 8; i++) {
		int nextx = curx + dx[i];
		int nexty = cury + dy[i];

		if (nextx >= 0 && nextx <w && nexty >= 0 && nexty < h) {
			if (map[nexty][nextx] == 1 && visited[nexty][nextx] == 0) {
				visited[nexty][nextx] = 1;
				//cout << "nextx:" << nextx<<'\n';
				//cout << "nexty:" << nexty<< '\n';
				check(nexty, nextx); //nexty,nextx 순서 조심하기!!
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
		if (w == 0 || h == 0)break; //0 0 입력되면 끝내기
		//각 테스트 케이스에 대하여 지도 정보 입력 1은 땅,0은 바다
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0; //초기화하기
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j]; //map에 저장 
			}
		}
		int cnt = 0; //각 테스트케이스의 섬의 갯수 세기 
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {//
					//cout << i << " " << j << '\n';
					visited[i][j] == 1;
					cnt++;// 섬 체크하기 시작하면 +1
					check(i, j);
					
					
				}

			}
		}
		//visited 초기화 
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				visited[i][j] = 0;
			}
		}
		

		cout << cnt << '\n';

	}

}
