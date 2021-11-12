#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace  std;
int cnt = 0;
int arr[26] = { 0 };

void check(string s,string start) {

	int find = 0;
	int flag = 0;
	int tmp[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		tmp[s[i] - 'A']++;
		if (tmp[s[i] - 'A'] > arr[s[i] - 'A'])flag++; //
		if (arr[s[i] - 'A'] == 1)continue;
		else find++;//start문장에 없는 단어 갯수		
	}
	if (s.size() == start.size()&&find<=1&&flag<=1) {//길이가 같고 같은 문자로 구성되어있으면
		
		cnt++;
		
		
	}
	else if(s.size()==start.size()-1 &&find<=1 && flag <= 1){ //문자 알파벳 구성은 같고 한 문자를 더해서 같아지는 경우
		cnt++;

	}
	else if (s.size() == start.size() + 1 && find <= 1 && flag <= 1) { //문자 알파벳 구성은 같고한 문자를 빼서 같아지는 경우 
		cnt++;
	}
	else { //길이가 같은데 문자구성이 2개 이상 다르거나 길이가 다른데 문자구성이 2개이상 다를경우
		return;

	}

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//같은 알파벳으로 구성되거나 한 던어에서 한 문자를 더하거나 빼거나 문자를 바꿔서 같아지면 비슷한 단어

	
	int n;
	cin >> n;
	n--;
	string start;
	string s;
	cin >> start;
	for (int i = 0; i < start.size(); i++) {
		arr[start[i] - 'A']++;
	}

	while (n--) {
		cin >> s;
		check(s,start);
		
	}
	
	cout << cnt;






}
