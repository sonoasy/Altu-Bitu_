#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10001

using namespace std;
vector<int> a;
int dp[MAX] = { 0 };
int answer = 0;
int main() {
	//백준 11399번
	int n;
	cin >> n;
	//각 사람이 인출하는데 걸리는 시간
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a.push_back(m);
	}

	//빨리 끝나는 사람이 먼저 인출
	sort(a.begin(), a.end());
	dp[0] = a[0];
	answer += dp[0];
	for (int i = 1; i < n; i++) {
		//정렬 되었으므로 앞에사람 대기시간+ 자신의 시간 - 각자의 대기시간 
		dp[i] = dp[i - 1] + a[i];
		answer+=dp[i];
	}

	
	cout << answer;

}
