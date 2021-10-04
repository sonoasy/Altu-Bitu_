#include <iostream>
#include<vector>
using namespace std;

int v[101][101];//보드의 크기 최대로 초기화

struct info {
	int x;
	char cc;
};
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
	int x; // 게임 시작후 x초 뒤
	char cc; //L이면 왼쪽으로, D면 오른쪽으로 90도 방향 회전
	int i = 0;
	while (l--) {
		cin >> x >> cc;
		dir[i++] = { x,cc };
	}


	//게임이 몇초뒤에 끝나는지 출력




	

}
