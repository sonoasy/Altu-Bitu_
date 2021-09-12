#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;

//다이어트 전 체중, 다이어트 전 일일 에너지 섭취량/일일 기초대사량, 역치
long long beforeweight1, beforeweight2, beforenergy, T;
//다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 일일활동대사량
long long days, dietenergy, dietactive;
//기초 대사량
long long normalloss;

//기초 대사량 변화 고려 안함
void defaultactive(int ddietenergy, int ddietactive, int days) {
	int flag = 0;
	
	while (days--) {

		//빠지는 체중량
		long long loss;
		loss = ddietenergy - (ddietactive + normalloss);
		//체중변화
		beforeweight1 -= abs(loss);
		if (beforeweight1 <= 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		cout << "Danger Diet" << '\n';
		return;
	}
	//printf("%llu %llu\n", beforeweight2, normalloss);
	cout << beforeweight1 << ' ' << normalloss << '\n';

}
//기초 대사량 변화 고려함
void includeactive(int idietenergy, int idietactive, int days) {
	int flag = 0;
	//다이어트 기간동안 
	while (days--) {

		//빠지는 체중량
		long long loss = idietenergy - (idietactive + normalloss);
		beforeweight2 -= abs(loss);
		//체중변화
		if (abs(loss) > T) {
			if (loss < 0) {
				loss = (int)float((float)loss / 2);
			}
			else {
				loss = (int)float((float)loss / 2);
			}
			normalloss += loss;

		}


		if (beforeweight2 <= 0 || normalloss <= 0) {
			flag = 1;
			break;
		}

	}
	if (flag == 1) {
		cout << "Danger Diet";
		return;
	}
	//요요 여부
	long long yoyo = beforenergy - (abs(normalloss));
	string check;
	if (yoyo > 0) {
		check = "YOYO";
	}
	else {
		check = "NO";
	}
	cout << beforeweight2 << ' ' << normalloss << ' ' << check;
	//printf("%ll %ll %s",beforeweight2,normalloss,check);


}




int main() {
	//백준 19363번


	cin >> beforeweight1 >> beforenergy >> T;
	normalloss = beforenergy;
	beforeweight2 = beforeweight1;
	cin >> days >> dietenergy >> dietactive;

	defaultactive(dietenergy, dietactive, days);
	includeactive(dietenergy, dietactive, days);


}
