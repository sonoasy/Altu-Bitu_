#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<char>> box;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = -1;

//행 열 탐색
void find(vector<vector<char>> box, int n) {
	int cnt;
	//모든 좌표에 대해서 탐색
	for (int k = 1; k <= n; k++) {//1-n행에 대하여 
		
		for (int i = 1; i <= n; i++) { //1열,2열,..n열로 시작할때 오른쪽 행 방향으로 갯수세기
			//행단위로 탐색
			cnt = 1;
			char check = box[k][i];
			for (int j = i + 1; j <= n; j++) {
				if (check == box[k][j]) {
					cnt++;

				}
				else {
					break;
				}
			}
			if (cnt > ans) {
				ans = cnt;
				
				cnt = 1; //초기화하기
			}
			else {
				cnt = 1;
			}
		}
	}
	int flag;
	for (int k = 1; k <= n; k++) {//1-n열에 대하여 
		
		for (int i = 1; i <= n; i++) { //1행,2행,..n행으로 시작할때 아래 방향으로 갯수세기
			//열단위로 탐색
			cnt = 1;
			char check2 = box[i][k];
			for (int j = i + 1; j <= n; j++) {
				if (check2 == box[j][k]) {
					cnt++;
					flag = k;
				}
				else {
					break;
				}
			}
			if (cnt > ans) {
				ans = cnt;
				cout << i << k;
				cout << check2;
				cnt = 1; //초기화하기
			}
			else {
				cnt = 1;
			}
		}
	}

}

int change(vector<vector<char>> &box,int n) { //상하좌우와 모두 바꿔보고 사탕 갯수 각 경우 당 비교하기
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char curr = box[i][j]; //현재 위치 
			
			for (int k = 0; k < 4; k++) { //상하좌우 에서 범위내에 있는 곳과 바꾸기
				int chx = i + dx[k];
				int chy = i + dy[k];

				if (chx >= 1 && chx <= n && chy >= 1 && chy <= n) {
					char chages = box[chx][chy];
					box[i][j] = chages;
					box[chx][chy] = curr;

					//해당 경우 먹을수 있는 사탕 최대 갯수 탐색
					find(box,n);
					//되돌리기
					box[i][j] = curr;
					box[chx][chy] = chages;

				}

			}

		}
	}



	return ans;
}



int main() {

	//백준 3085번

	int n;
	cin >> n;
	//빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y
	box.assign(n + 1, vector<char>('0'));
	
	//사탕 배열 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> box[i][j];
		}
	}
	cout<<change(box,n);










}
