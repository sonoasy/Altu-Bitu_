#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<map>

using namespace  std;

map<string, int> check;
vector<string>v;
int n, m; //길이가 m이상인거부터 외움
string s;

bool compare(string a, string b) {


	if (a.size() == b.size()&&check[a] == check[b]) {  //여기서 순서바꾸면 시간초과 뜸
		return a < b;
	}
	else if (check[a] == check[b]) {
		return a.size() > b.size();
	}


	return check[a] > check[b];



}


int main() {

	//백준 20920번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//자주 나오는 단어-> 단어길이 길수록->알파벳 순


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.size() < m)continue;

		//길이가 m이상인것만

		if (check.find(s) == check.end()) {
			check[s] = 0;
			//처음 출현할떄만 
			v.push_back(s);
		}
		check[s]++;

	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}



}
