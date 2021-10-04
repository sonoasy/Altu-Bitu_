#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MAX = 99999999999;
int res = MAX;
int n;

void check(int one_color, vector<vector<int>> &dp, vector<vector<int>>&v) {

	//첫번째 집이 k색으로 고정, 나머지는 큰 수로 고정
	for (int i = 0; i < 3; i++) {
		if (i == one_color) {
			dp[1][i] = v[1][i];
		}
		else {
			dp[1][i] = MAX;
		}
	}

	//n번째 집에서 r,g,b로 칠했을때 최솟값
	//마지막 집은 첫번쨰 집과 색이 달라야함


	for (int i = 2; i <= n; i++) {



		//앞집과 다른색으로 배정
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];


	}

	for (int i = 0; i < 3; i++) {
		//one_color를 k로 설정해서 어떤건지 정확히 모르므로 if로 체크하기
		if (i == one_color)continue; //one_color인건 값이 있더라도 넘어가기
		else {
			res = min(dp[n][i], res);
		}

	}


}
int main() {
	//백준 1149번
	vector<int>coin;

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	cin >> n;

	//n개의 집에 대하여 r,g,b 3가지 색에 대한 비용을 입력받음
	vector<vector<int>> v(n + 1, vector<int>(3, 0));


	for (int i = 1; i <= n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];

	}


	vector<vector<int>> dp(n + 1, vector<int>(3, 0));


	int one_color;
	
	//첫번째 집이 각각 r,g,b 일때 경우
	for (int k = 0; k < 3; k++) {
	
		check(k,dp,v);
	}


	cout << res;







}
