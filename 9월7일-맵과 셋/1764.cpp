#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;



int main() {
	//백준 1764번
	int n, m;
	int count = 0;
	//이름에 대한 갯수 map
	map<string, int> lists;

	string k;
	cin >> n >> m;

	//n, 중복되는 이름 없음
	for (int i = 0; i < n; i++) {
		getline(cin, k);
		lists[k] = 1;      //중복되는 이름이 없으므로 각각 출현하면 갯수를 +1함

	}
	//m, 중복되는 이름 없음
	for (int i = 0; i < m; i++) {
		getline(cin, k);
		lists[k]++;
		//갯수가 1이상이면 중복이므로 체크
		if (lists[k] > 1) {
			count++;
		}
	}

	//n과 m에 공통으로 있는 이름 갯수와 명단 출력하기 
	//맵에서 갯수가 2이상인것이면 중복되는 이름
	cout << count<<'\n';
	for (auto it = lists.begin(); it != lists.end(); it++) {
		if (it->second > 1) {
			cout << it->first << '\n';
		}

	}
	





}
