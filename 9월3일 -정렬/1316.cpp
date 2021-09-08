#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int cnt = 0;

bool check[26] = { false };

void checkgroup(string s) { //그룹함수인지 확인하기
	int flag = 1;
	//check 초기화하기
	fill_n(check, 26, false);
	check[s[0] - 'a'] = true; //처음은 일단 체크
	//단어내 모든 문자에 대해 조사
	for (int j = 1; j < s.size(); j++) {
		//출현했는데 연속이 아닌데 처음 출현하는것도 아니면 탈락
		if (check[s[j] - 'a'] == true && s[j] != s[j - 1]) {
			flag = 0;
			break;
		}
		else {

			check[s[j] - 'a'] = true;
		}
	}
	if (flag == 1) {

		cnt++;
	}

}

int main() {
	//백준 1316번
	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {

		cin >> s; //문자 입력
		checkgroup(s);
		
	}
	cout << cnt;

	return 0;

}
