#include<iostream>
#include<vector>
#include<queue>
#define MAX 200001
using namespace  std;

//17회 이퍼 기출문제로 출제되어 17회 이퍼풀이와 함께 학습한 방식을 떠올리면서 코드를 작성하였습니다.

vector<int> arr[MAX];
int start[MAX]; //최초로 루머를 믿기 시작한 때
queue<int> q;
int num[MAX];


void bfs(int start[], vector<int>arr[], int n) {

	while (!q.empty()) {
		//현재 루머 믿는 사람
		int curr = q.front();
		q.pop();

		//주변 사람들 중에 루머를 퍼뜨릴 사람 탐색
		for (int i = 0; i < arr[curr].size(); i++) {
			//주변 사람들 한명 한명의 num에 대하여  
			int next = arr[curr][i];
			num[next]--; //지금 루머를 믿는 사람 카운트 

			//next로 선택된 사람이 루머를 믿지 않는 상황인데 num이 0이하가 된 상황이면
			if (start[next] < 0 && num[next] <= 0) {
				//현재 루머를 믿는 사람의 루머를 믿는 시작시간 +1
				start[next] = start[curr] + 1;
				//큐에 들어감
				q.push(next);
			}


		}



	}


}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; //사람의 수 
	int t;
	cin >> n;

	fill_n(start, n + 1, -1); //start 모두 -1로 초기화 

	for (int i = 1; i <= n; i++) {//n명의 사람들의 주변인 번호입력
		while (1) {
			cin >> t;
			if (t == 0) {//0이면 다음 사람정보 입력
				break;
			}
			arr[i].push_back(t); //i번 사람의 주변인 정보저장

		}

	}
	int m; //최초 유포자 수
	int e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> e;
		start[e] = 0; //최초 유포자가 믿기 시작한 시간은 0
		q.push(e); //입력받은 동시에 바로 큐에 넣기 

	}
	//주변인 중 1/2 이상이 루머를 믿으면 루머를 믿게 되는데 각 번호의 
	//사람당 믿게되는 주변인 중 루머를 믿는 사람수 num에 저장
	for (int i = 1; i <= n; i++) {
		 
		if (arr[i].size() % 2 == 0) { //주변인이 짝수명이면 1/2
			num[i] = arr[i].size() / 2;
		}
		else {
			num[i] = arr[i].size() / 2 + 1; //주변인이 홀수명이면 1/2+1
		}

	}
	//루머 퍼짐
	bfs(start, arr, n);

	//각 번호의 사람들이 루머를 믿기 시작한 때 출력
	for (int i = 1; i <= n; i++) {
		cout << start[i] << ' ';
	}










}
