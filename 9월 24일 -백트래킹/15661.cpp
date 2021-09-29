#include <iostream>
#include<vector>
using namespace std;
int n;
int arr[21][21];
int flag[21];
int mins = 10000000000;
void go(int num, int idx) { //num은 여태까지 정한 사람 숫자, idx는 이제 정할 팀원 번호


	//n명이 모여서 팀원 수는 다르더라도 1명 이상이어야 함 
	//스타트팀이 1~n-1명일 경우 각각 능력치 차이 구해서 그 중 최솟값 구하기
	if (num <= n - 1) {
		//스타트팀 명수 달라질때마다 다시 start,link값 다시 계산하기
		int start = 0, link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				//i, j 번호가 1일때만 그 둘의 스타트 팀의 능력치에 더해준다
				if (flag[i] == 1 && flag[j] == 1) {

					start += arr[i][j];

				}
				//i,j 번호가 체크 안되어 0일때만 link팀의 능력치에 더해준다 
				if (flag[i] == 0 && flag[j] == 0) {

					link += arr[i][j];


				}


			}
		}
		// 능력치 차이 최솟값 갱신
		int result = abs(start - link);
		if (mins > result) {
			mins = result;

		}


	}
	//오름차순으로 탐색해서 중복 없애기
	for (int i = idx; i < n; i++) {

		if (flag[i] == 0) {
			flag[i] = 1;
			//그 다음부터는 idx+1 부터 탐색하게 함
			go(num + 1, i + 1);
			flag[i] = 0;
		}


	}
	return;
}


int main() {
	//백준 15661번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//스타트팀, 링크 팀
	//스타트팀과 링크 팀 능력치 최소화하기

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];  //i-j 있을때 능력치

		}
	}


	//스타팀 먼저 선정
	go(0, 1);

	//최종 최솟값 출력
	cout << mins;


}
