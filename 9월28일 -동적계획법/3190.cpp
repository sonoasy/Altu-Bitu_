#include <iostream>
#include<vector>
#include<deque>
using namespace std;

int v[101][101];//보드의 크기 최대로 초기화

//뱀이 있는 칸 위치 실시간으로 확인하기
bool snake[101][101];
//뱀
deque<pair<int, int>> snakebody;

struct info {
	int x;
	char cc;
};

//상하 좌우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


info dir[101]; //방향 바꾸는 정보 저장
int main() {
	//백준 3190번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	int k;
	//사과의 위치
	cin >> k;
	//행,열
	int r, c;
	while (k--) {
		cin >> r >> c;
		v[r][c] = 1;//사과가 있는 위치

	}
	//뱀의 방향 변환 횟수
	int l;
	cin >> l;
	int s; // 게임 시작후 x초 뒤
	char cc; //L이면 왼쪽으로, D면 오른쪽으로 90도 방향 회전
	int i = 0;
	while (l--) {
		cin >> s >> cc;
		dir[i++] = { s,cc };
	}

	//시간 
	int time = 0;
	//뱀이 이동하는 규칙
	//머리를 늘려 다음칸으로 위치, 사과가 있으면 사과 없어지고 꼬리는 움직이지 x
	//머리 늘려 다음칸을 갔을때 사과가 없으면 꼬리칸 비워서 길이 유지
	//벽또는 자기 자신과 부딪히면 게임 끝
	
	//처음 위치, 오른쪽을 향함
	int x = 1;
	int y = 1;
	int dirx = dx[3];
	int diry = dy[3];
	snakebody.push_back({ 1,1 });
	snake[x][y] = true;
	while (1) {

		//오른쪽 방향
		if (!snakebody.empty()) {
			x = snakebody.front().first;
			y = snakebody.front().second;
			int nextX = x + dirx;
			int nextY = y + diry;

			//벽으로 가로막히면 종료
			if (nextX > n || nextX<1 || nextY>n || nextY < 1)break;
			//몸통이 있었을때 종료(뱀 길이는 1)
			if (snake[nextX][nextY] == true)break;

			//위에 해당되지 않고 이동했을때 
			snake[nextX][nextY] = true;
			//방향바꾸는 시간대이면 방향 바꿔주기
			if (dir[time].cc == 'L') { //왼쪽으로 90도 회전
				dirx += dx[2];
				diry += dy[2];
			}
			else if (dir[time].cc == 'D') {//오른쪽으로 90도 회전
				dirx += dx[2];
				diry += dy[2];


			}


			//사과가 있으면
			if (v[nextX][nextY] == 1) {
				//사과를 없애고 
				v[nextX][nextY] = 0;


			}
			else {//사과가 없으면 
				//꼬리 없애기
				snake[x][y] == false;
				snakebody.pop_front();

			}


			time++;
		}
	
      

	}


	//게임이 몇초뒤에 끝나는지 출력

	cout << time;




}
