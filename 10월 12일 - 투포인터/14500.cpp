#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int num[501][501] = { 0 };
//dx 가 열, dy가 행
int dx[4] = {0,0,-1,1}; //상하좌우
int dy[4] = {-1,1,0,0};

int main() {

	//백준 14500번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//테트로미노가 있을수 있는 자리의 모든 숫자합의 최대값

	int n, m;//세로,가로 크기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num[i][j];
		}
	}
    //테트로미노
	//1.오른쪽으로 3칸 
	//2.오른쪽으로 1칸,아래로1칸,왼쪽으로 1칸
	//3.아래로 두칸,오른쪽으로 1칸  
	//4.아래로 한칸,오른쪽으로 1칸,아래로 1칸
	//5.오른쪽으로 1칸-(오른쪽으로 1칸/아래로 1칸)



	
}
                         
