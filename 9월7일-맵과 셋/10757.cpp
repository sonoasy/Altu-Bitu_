#include <iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX 100000
using namespace std;

string a;
string b;

int main() {
	//백준 10757번
	
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	cin >> a >> b;

	//순서가 거꾸로 되있으니까 뒤집기
	reverse(a.begin(),a.end());   //일의자리수가 0인덱스부터 있음
	reverse(b.begin(), b.end());

	//자리수 큰게 a로 하기
	if (a.size() < b.size()) {
		swap(a, b);
	}
	//a크기만큼 b에 0으로 채우기
	for (int i = b.size(); i < a.size(); i++) {
		b += "0";
	}
	
	//답 저장
	string answer;

	//더해서 10이 넘어서 넘길 1 체크
	int flag = 0;
	for (int i = 0; i<a.size(); i++) {
		//큰자리수 끝에 맞춰서 
		int num = (a[i] - '0') +(b[i] - '0');
		
		if (flag == 1) {
			num += flag;
			flag = 0;
		}
		if (num >= 10) {
			num %= 10;
			flag = 1;
		}
		answer+=to_string(num);


	}
	
	//flag가 남았으면 추가해주기
	if (flag == 1) {
		answer+="1";
	}

	//다시 뒤집기
	reverse(answer.begin(),answer.end());

	cout << answer;


}
