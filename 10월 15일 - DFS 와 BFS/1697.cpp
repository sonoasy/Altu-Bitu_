#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 100001

using namespace std;

//먼저 제출한 최단경로 과제 13549번과 유사하여 해당 문제 과제를 참고하여 풀었습니다


vector<int> visited(MAX, 0); //지점에 도달한 시간

int find(int n, int k) {
	visited[n] = 1; //시작점 visited =0으로 하지말고 방문도 했으니까 1로 설정하기!!! 나중에 결과값 -1하기!!!
	queue<int>q;
	int finded = 0;

	q.push(n);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == k) {//동생이 있는 위치면
			finded = visited[curr]-1;
			break;
		}
		else {
			//동생이 있는 위치가 아니면 
			//순간이동하기
			int next = curr * 2;
			if (next >= 0 && next <= 100000 && visited[next] == 0) {
				visited[next] = visited[curr] + 1;
				q.push(next);

			}

			next = curr - 1; //뒤로 -1 가기
			if (next >= 0 && next <= 100000 && visited[next] == 0) {
				visited[next] = visited[curr] + 1;
				q.push(next);

			}

			next = curr + 1; //앞으로 +1 가기
			if (next >= 0 && next <= 100000 && visited[next] == 0) {
				visited[next] = visited[curr] + 1;
				q.push(next);

			}
		}



	}

	return finded;

}

int main() {

	//백준 1697번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;//수빈이가 있는 위치, 동생이 있는 위치
	//순간이동하면 1초후에 2*x , 1초 후에 x+1 이나 x-1위치로
	//동생을 찾는 빠른 시간이 몇 초 후인지

	cin >> n >> k;
	cout << find(n, k) << '\n';


}
