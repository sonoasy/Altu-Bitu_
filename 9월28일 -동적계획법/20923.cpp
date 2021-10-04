#include <iostream>
#include<vector>
#include<deque>
using namespace std;

deque<int>doo,doo_ground;
deque<int>suu,suu_ground;
int n, m;
int cnt=0;


//종을 치는 조건
void ring() {
	//도도: 그라운드 맨위에 있는 숫자가 5가 나타날때
	if ((!doo_ground.empty() &&doo_ground.back() == 5) || (!suu_ground.empty()&&suu_ground.back() == 5)) {
		//상대방 그라운드에 있는 카드 더미를 뒤집어서 자신의 덱 아래로 넣기
		int len=suu_ground.size();
		for (int i = 0; i < len; i++) {
			doo.push_front(suu_ground[i]);
		}
		cnt++;
	}

	//수연: 그라운드 맨위에 있는 숫자 합이 5일때(어느쪽도 비지 않을때)
	if ((doo_ground.back() + suu_ground.back() == 5) && !doo_ground.empty() && !suu_ground.empty()) {
		//상대방 그라운드에 있는 카드 더미를 뒤집어서 자신의 덱 아래로 넣기
		int len2 = doo_ground.size();
		for (int i = 0; i < len2; i++) {
			suu.push_front(doo_ground[i]);
		}

		cnt++;
	}

	//덱이 비게 되면 다른 상대방이 승리
	if (doo.empty()) {
		cout << "su";
		return;
	}
	else if (suu.empty()) {
		cout << "do";
		return;
	}
}


int main() {
	//백준 20923번
	
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	
	cin >> n >> m;
	int d, s;
	while (n--) {
		cin >> d >> s;
		doo.push_back(d);
		suu.push_back(s);
	}

	//deque 맨뒤에서부터 그라운드에 올려놓음
	while (1) {
		//도도가 그라운드에 올려놓기
		if (!doo.empty()) {
			doo_ground.push_back(doo.back());
			doo.pop_back();
		}
	
		ring();

		//수연이가 그라운드에 올려놓기
		if (!suu.empty()) {
			suu_ground.push_back(doo.back());
			suu.pop_back();
		}
		ring();
	 
		//m번 진행했으면 종료
		if (cnt == m)break;
	    
	
	}
	if (doo.size() > suu.size()) {
		cout << "do";
	}
	else if (doo.size() == suu.size()) {
		cout << "dosu";
	}
	else {
		cout << "su";
	}





	

}
