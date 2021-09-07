#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100002

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {

	//y 증가하는 순, 같으면 x가 증가하는 순
	if (a.second == b.second) {
		return a.first < b.first;
	}
	
	//그외의 경우
	return a.second < b.second;
	
}

int main() {
	//백준 11651번
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int f, s;
		cin >> f >> s;
		v.push_back({ f,s });
	}
	//y좌표가 증가하는 순서-> 같으면 x좌표가 증가하는 순서(오름차순)
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

} 
