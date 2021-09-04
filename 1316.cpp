#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int cnt = 0;

int main() {
	//백준 1316번
	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
	
		cin >> s;
		int flag = 1;
		//단어내 모든 문자에 대해 조사
		for (int j = 0; j < s.size(); j++) {
			if (s[j] != s[j + 1]) { //그 다음과 달라서 연속이 아닌데 이후 같은 문자가 나오면 탈락
				for (int k = j + 2; k <= s.size()-1; k++) {
					if (s[j] == s[k]) {
						flag = 0;
						break;
					}
				}


			}
			if (flag == 0) {
				break;
			}

		}
		if (flag == 1) {
			cnt++;
		}

	}
	cout << cnt;

	return 0;
	
}
