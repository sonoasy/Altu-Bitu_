#include <iostream>
#include<vector>
#include<deque>
using namespace std;

deque<int>doo, doo_ground;
deque<int>suu, suu_ground;
int n, m;
int cnt = 0;


//종을 치는 조건
void ring() {

	if (doo.empty()) {
		
		return;
	}
	if (suu.empty()) {
		
		return;
	}

	//수연: 그라운드 맨위에 있는 숫자 합이 5일때(어느쪽도 비지 않을때)
	if (!doo_ground.empty() && !suu_ground.empty()) {
		//도도,수연 각각 그라운드 맨위의 카드 합이 5이면 종을 침
		if (doo_ground.back() + suu_ground.back() == 5) {
			//상대방 그라운드에 있는 카드 더미를 뒤집어서 자신의 덱 아래로 넣기

			while (!doo_ground.empty()) {
				suu.push_front(doo_ground.front());
				doo_ground.pop_front();
			}
			//자신의 그라운드 더미도 뒤집어서 자신의 덱 밑으로
			while (!suu_ground.empty()) {
				suu.push_front(suu_ground.front());
				suu_ground.pop_front();
			}


		
		}

	}


	//도도: 그라운드 맨위에 있는 숫자가 5가 나타날때

	if ((!doo_ground.empty() && doo_ground.back() == 5) || (!suu_ground.empty() && suu_ground.back() == 5)) {
		//상대방 그라운드에 있는 카드 더미를 뒤집어서 자신의 덱 아래로 넣기

		while (!suu_ground.empty()) {
			doo.push_front(suu_ground.front());
			suu_ground.pop_front();
		}
		//자신의 그라운드 더미도 뒤집어서 자신의 덱 밑으로
		while (!doo_ground.empty()) {
			doo.push_front(doo_ground.front());
			doo_ground.pop_front();
		}

		
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
	while (m--) {
		//도도 덱에 카드가 있으면 도도 그라운드에 올려놓기
		if (!doo.empty()) {
			doo_ground.push_back(doo.back());
			doo.pop_back();
		
			//덱이 비었으면 상대방이 승리
			if (doo.empty()) { //수연이 승리
				break;

			}
		}

		//종울리수 있는지 확인
		ring();


		//수연 덱에 카드가 있으면 수연 그라운드에 올려놓기
		if (!suu.empty()) {
			suu_ground.push_back(suu.back());
			suu.pop_back();
			

			//덱이 비었으면
			if (suu.empty()) {//도도가 승리
				break;
			}
		}
		//종 울리수 있는지 확인
		ring();


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
