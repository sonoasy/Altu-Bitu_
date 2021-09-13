#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX 100000
using namespace std;


int main() {
	//백준 10757번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a;
	string b;


	cin >> a >> b;

	//답 저장
	string answer;

	//더해서 10이 넘어서 넘길 1 체크
	int flag = 0;
	int check;
	//인덱스 끝부터 시작하기
	int idxa = a.size() - 1;
	int idxb = b.size() - 1;
	int suma, sumb;
	//둘중 하나는 글자인 숫자가 있을떄까지 계속하기
	while (idxa >= 0 || idxb >= 0) {
		//큰자리수 끝에 맞춰서 

		
		if (idxa >= 0) {
			suma = (a[idxa] - '0');
		}
		if (idxb >= 0) {
			sumb = (b[idxb] - '0');
		}
		

		//만약 한쪽이 공백이어서 음수가 되면 0으로 바꾸기
		if (suma < 0 ||idxa<0) {
			suma = 0;
		}
		if (sumb < 0 || idxb < 0) {
			sumb = 0;
		}

		int num = suma + sumb;

		//올라온 1이 있으면 더해주기
		if (flag == 1) {
			num += flag;
			flag = 0;
		}
		//합이 10이 넘으면 넘길 1 저장하기
		if (num >= 10) {
			num %= 10;
			flag = 1;
		}
		//string으로 바꿔서 저장하기
		answer += to_string(num);
		
		idxa--;
		idxb--;
		

	}

	//flag가 남았으면 추가해주기
	if (flag == 1) {
		answer += "1";
	}

	//다시 뒤집기
	reverse(answer.begin(), answer.end());

	cout << answer;


}
