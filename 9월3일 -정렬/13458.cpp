#include<iostream>
#define MAX 1000002

using namespace std;

int num[MAX] = { 0 }; //각 시험장 응시자 수
long long answer = 0;
int main() {

	//백준 13458번
	int n;
	cin >> n;  //시험장 갯수
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	//총감독관, 부감독관 감시 가능 인원
	int b, c;
	cin >> b >> c;

	//감독관 최소 수 출력
	answer += n; //각 시험장에 총감독관 한명씩 배치
	for (int i = 0; i < n; i++) {
		num[i] -= b; //num[i]가 b보다 작을수 있음(총감독관 1명만 할당)
		if (num[i] > 0) { //아직 남은 감독인원이 있으면
			
			answer += num[i] / c;
			num[i] = num[i] % c;
			if (num[i] > 0) {
				answer++;

			}
			
		}

	}
	cout << answer;




}
