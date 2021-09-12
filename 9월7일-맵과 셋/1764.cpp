#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> a;
vector<string> b;

int main() {
	//백준 1764번
	int n, m;
	string k;
	cin >> n >> m;
	
	//듣도 못한 n
	for (int i = 0; i < n; i++) {
		getline(cin, k);
		a.push_back(k);
		
	}
	//보도 못한 m
	for (int i = 0; i < m; i++) {
		getline(cin, k);
		b.push_back(k);

	}
	

	vector<string> answer(a.size()+b.size());
	//듣도보도 못한 명단 구하기 
	auto iter = set_intersection(a.begin(), a.end(), b.begin(), b.end(), answer.begin());
	answer.erase(iter, answer.end());

	cout << answer.size() << '\n';
	for (string& it : answer) {
		cout << it << '\n';
	}



}
