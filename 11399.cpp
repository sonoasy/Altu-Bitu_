#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10001

using namespace std;
vector<int> a;
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer += a[j];
		}
	}
	cout << answer;

}
