#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m; //n개의 자연수 중에서 m개를 고른 수열, 같은수 여러번 가능
set<int>arr;

int check[1001] = { 0 };
int a[1001];
int flag[1001];
void go(int start) { //최종 결과 출력하는 a의 start번째 index 값 정하기 


	if (start == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;

	}

	for (auto it=arr.begin();it!=arr.end();it++) {
		a[start] = *it;
		go(start + 1);
	}



}

int main() {
	//백준 15665번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	cin >> n >> m;
	
	int e;
	for (int i = 0; i < n; i++) {
		//숫자 목록 입력
		cin >> e;
		arr.insert(e);

	}

	//오름차순으로 먼저 정렬
	//sort(arr.begin(), arr.end());

	//중복은 불가, 사전 순으로 증하는 순서

	go(0);


}
