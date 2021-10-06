#include <iostream>
#include<vector>
using namespace std;

struct info {
	int r; //빨간색으로 칠할때 비용
	int g; //초록색으로 칠할때 비용
	int b; //파란색으로 칠할때 비용

};

int main() {
	//백준 1149번
	vector<int>coin;

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<info>v(n + 1, { 0,0,0 });

	//n개의 집에 대하여 r,g,b 3가지 색에 대한 비용을 입력받음

	for (int i = 1; i <= n; i++) {
		cin >> v[i].r >> v[i].g >> v[i].b;

	}

	//1번집의 색은 2번 집의 색과 같지 않아야함
	//n번 집의 색은 n-1번 집의 색과 같지 않아야 함
	//i(2<=i<n-1)번 집의 색은 i-1,i+1번 집의 색과 같지 않아야 함
	//앞뒤로 있는 집은 서로 색이 같으면 안됨


	//n번째 집에서 r,g,b로 칠했을때 최솟값
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));

	
	for (int i =1; i <= n; i++) {

		//앞집과 다른색으로 배정
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i].r;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i].g;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i].b;


	}

	int res = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << res;







}
