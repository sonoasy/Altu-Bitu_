#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

char makestar[500][500];

//별 직사각형 만들기
void star(int x,int y,int n) { 

	if (n == 1) {
		makestar[x][y]='*';
		return;
	}
	//x는 행(세로), y가 열(가로)

	
	//맨 위 긴줄 저장
	for (int i = y; i < y+4 * n - 3; i++) {
		//행은 그대로 
		makestar[x][i] = '*';
	}
	//양쪽 세로줄 저장
	for (int i = x+1; i < x + 4 * n - 3; i++) {
			makestar[i][y] = '*';
			makestar[i][y + 4 * n - 4] = '*';

	}
	//맨 아래 긴줄 저장
	for (int i = y; i < y + 4 * n - 3; i++) {
		makestar[x +4 * n - 4][i] = '*';
	}


	star(x+2,y+2,n - 1);
	return;
}



int main() {
	//백준 10994번
	int n;

	cin >> n;
	//초기화하기 
	fill(&makestar[0][0], &makestar[4*n-3][4*n-3], ' ');
	
	int s = n;
	star(0,0,n);

	for (int i = 0; i <4*n-3; i++) {
		for (int j = 0; j < 4*n-3; j++) {
			cout << makestar[i][j];
		}
		//한줄 띄는거 여기서 처리
		cout << '\n';
	}



}
