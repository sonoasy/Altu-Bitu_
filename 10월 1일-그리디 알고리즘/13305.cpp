#include <iostream>

using namespace  std;

long long dist[100001];
long long price[100001];


int main() {

        //백준 1448번
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; //도시 갯수
	cin >> n; 
	//도시 사이 거리
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];

	}
	//각 도시에서 가격
	for (int i = 0; i < n; i++) {
		cin >>price[i];

	}

	//첫번째 도시에서의 가격으로 초기화하고 도시를 지나면서 더 작은 값이 있으면 그값을 min으로 설정
	int min =price[0];
	long long sum = 0;
	for (int i = 0; i < n - 1; i++) {

		if (price[i] < min) {
			min = price[i];
		}
		sum += min * dist[i];


	}

	cout << sum;


}
