#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace  std;

int n, row, col; // row는 행 col은 열
int cnt = 0;
void go(int x, int y, int size) {

	//해당 열에 도착하면 종료
	if (x == col &&y == row ) {
		cout << cnt;
		return;
	}
	else {
		//col이 x좌표이고(가로) row가 y좌표임(세로)
		if (col >= x && col < x + size && row >= y && row < y + size ) {
			//size내 구역에 있다면 4등분해서 탐색
			go(x, y, size / 2);
			go(x + size / 2, y, size / 2);
			go(x,y + size / 2, size / 2);
			go(x + size / 2, y + size / 2, size / 2);
		}
		else {
			//없으면 칸수 더해줌
			cnt += (size * size);
		}

	}





}

int main() {

	//백준 1074번 
	

	cin >> n >> row >> col;
	int init_num = pow(2,n);
	//cout << init_num;
	go(0, 0, init_num);
	return 0;
}
