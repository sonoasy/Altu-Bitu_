#include<iostream>
#include<string>
#include<cctype>
using namespace  std;

int box[21] = { 0 };
int main() {

	//백준 3613번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//c++ -> java  java->c++ 입력이 어느쪽도 아니면 에러
	//입력이 두개다면 단어 한개짜리로 그대로 냅둠


	string s;
	cin >> s;

	//문자에 대문자와 _이 같이 있으면 error
	//c++-> java  _없애고 다음 문자를 대문자로바꾸기
	//java->c++  대문자만나면 _먼저 붙이고 소문자로 바꾸기 
	int flag1 = 0;
	int flag2 = 0;
	int upp = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it == '_') {
			flag1++;
		}
		if (isupper(*it)) {
			flag2++;
		}
	}
	if (flag1 > 0 && flag2 > 0) {
		cout << "Error!" << '\n';
	}
	else {
		string answer = "";
		if (flag1 > 0) { //c++ -> java

			for (int i = 0; i < s.size(); i++) {
				
				if (upp == 1) {
					char w = toupper(s[i]);
					answer += w;
					upp = 0;
					i++;

				}

				if (s[i] == '_') {
					upp = 1;
					continue;

				}
				else {
					answer += s[i];
				}
			}

			cout << answer;
		}
		else if (flag2 > 0) { //java->c++
			string answer2 = "";
			for (int i = 0; i < s.size(); i++) {

				
				if (isupper(s[i])) {
					answer2 += '_';
					char f = tolower(s[i]);
					answer2 += f;


				}
				else {
					answer2 += s[i];
				}
			}

			cout << answer2;
		}
		
	}


	



}
