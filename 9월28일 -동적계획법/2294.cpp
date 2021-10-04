#include <iostream>
#include<vector>
#define MAX 100001
using namespace std;

int main() {
	//백준 2294번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//가치합이 k가 되도록, 동전은 여러번 사용 가능

	int n, k;
	cin >> n >> k;
	vector<int>coin(101, 0);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	vector<int>dp(MAX, MAX);
	//합이 0이되는 경우는 0
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		//동전을 포함하는 경우 
		//동전을 여러번 사용해도 되므로 갱신이 될수 있을때마다 최솟값으로 갱신 
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}

	}
	//처음 초기화값과 달라지는게 없으면 -1출력
	if (dp[k] == MAX) {
		cout << -1;
	}
	else {
		cout << dp[k] << endl;
	}



}
