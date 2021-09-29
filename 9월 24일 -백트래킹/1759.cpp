#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int flag[30] = { 0 }; //모음 확인
int l, c;// 비번 l개의 문자, c는 알파벳 후보
char ans[30]; //비밀번호 후보 문자 저장할 배열
int check[30] = { 0 }; //각 후보 문자가 쓰였는지 확인
vector<char> str; //문자 후보


void go(int num,int idx,int cnt1,int cnt2) { //num은 지금까지 결정된 암호문자 개수, idx는 벡터 str중에서 탐색할 인덱스, cnt1 은 모음갯수, cnt2는 자음 갯수
	if (num == l) {
		if (cnt1 >= 1 && cnt2 >= 2) { //모음 갯수 1개 이상, 자음 갯수 2개 이상일때만 출력
	
			for (int i = 0; i < l; i++) {
				cout<<ans[i];
			}
			cout << '\n';

			return;
		}
		
		
	}

	for (int i = idx; i < c; i++) {
    //해당 문자 str[i]가 쓰이지 않고
		if (check[str[i] - 'a'] == 0) {
			check[str[i]-'a'] = 1;
			ans[num] = str[i]; //저장
      //모음이라면 cnt1인자 +1
			if (flag[str[i] - 'a'] == 1) {
        //중복문자를 피하기 위해서 idx에 해당되는 인자를 i+1로 인덱스를 오름차순으로 하나씩 탐색하도록 함
				go(num + 1, i + 1,cnt1+1,cnt2);
				check[str[i] - 'a'] = 0;
			}
			else {//자음이라면 cnt2 인자+1
				go(num + 1, i+ 1,cnt1,cnt2+1);
				check[str[i] - 'a'] = 0;
			}
			
		}
		
	}






}



int main() {
	//백준 1759번

	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//적어도 하나의 모음, 두개의 자음으로 구성

	cin >> l >> c;
	
	char s;
	for (int i = 0; i < c; i++) {
		cin >> s;
		str.push_back(s);
		if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {

			flag[s - 'a'] = 1;

		}

	}
  //사전 순이므로 정렬
	sort(str.begin(), str.end());
	go(0,0,0,0);

	




}
