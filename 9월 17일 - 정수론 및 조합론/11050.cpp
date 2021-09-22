#include<iostream>
#define MAX 11
using namespace std;

//백준 11050

int bin(int n, int k) {

	int s[MAX][MAX] = { 0 };
	int m;

	//nCk를 구하려면 1C0, 1C1, 2C0,2C1,2C2....nC0,...nCk 순차적으로 구하기
	//각 1부터 n까지
	for (int i = 1; i <= n; i++) {
	
		//각 1..n까지 이항계수를 구할때 k보다 큰 번째수는 탐색 안해도 됨
		//1..n 이 k보다 작으면 모두 구하기, k보다 같거나 크면 k까지만 구하기
		m = (i < k) ? i : k;


		for (int j = 0; j <= m; j++) {
			//0번쨰, i번쨰면 값이 1
			if (j == 0 || i == j) {
				s[i][j] = 1;
			}
			else {
			// 그외의 경우 n-1Cj-1 +n-1Cj =nCj
				s[i][j] = s[i - 1][j - 1] + s[i - 1][j];
			}

		}
	}

	return s[n][k];
}




int main() {

	int n, k;

	//nCk 구하기
	cin >> n >> k;

	cout << bin(n, k);



}


