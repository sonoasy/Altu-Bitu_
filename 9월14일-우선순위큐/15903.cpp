#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace  std;


int main() {

	//백준 15903번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;  //카드개수,카드 합체 번수
	priority_queue<int,vector<int>,greater<int>> q;

	cin >> n >> k;
    //각각 카드 상태
	int s;
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> s;
		q.push(s);
	}
	for (int i = 0; i < n; i++) {
		int w = q.top();
		v.push_back(w);
		q.pop();
	}
	while (k--) {
		int a = v[0] + v[1];
		v[0] = a;
		v[1] = a;

	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum;
	



}
