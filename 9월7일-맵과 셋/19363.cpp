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

int flag1;    //기초 대사량 변화 고려 안할때 결과 출력하기 위한 지표
int flag2;    //기초 대사량 변화 고려 할때 결과 출력하기 위한 지표

int weight1, loss1; //기초 대사량 변화 고려 안할때 결과 출력
int weight2, loss2; //기초 대사량 변화 고려 할때 결과 출력
string check;  //기초 대사량 변화 고려 할때 요요 여부

//기초 대사량 변화 고려 안함
void defaultactive(int ddietenergy, int ddietactive, int days) {
	flag1 = 0;

	while (days--) {

		//빠지는 체중량
		long long loss;
		loss = ddietenergy - (ddietactive + normalloss);
		//체중변화
		beforeweight1 -= abs(loss);
		if (beforeweight1 <= 0) {
			flag1 = 1;
			break;
		}
	}

	weight1 = beforeweight1;
	loss1 = normalloss;


}
//기초 대사량 변화 고려함
void includeactive(int idietenergy, int idietactive, int days) {
	flag2 = 0;
	//다이어트 기간동안 
	while (days--) {

		//빠지는 체중량
		long long loss = idietenergy - (idietactive + normalloss);
		beforeweight2 -= abs(loss);
		//체중변화
		if (abs(loss) > T) {
			if (loss < 0) {
				//음수 나눗셈-> 양수로 바꿔서 나누고 몫에 -1곱하기
			    loss = round((abs((long long)loss) / 2)) * (-1);
			
			}
			else {
				loss = loss / 2;
			}
			normalloss += loss;

		}


		if (beforeweight2 <= 0 || normalloss <= 0) {
			flag2 = 1;
			break;
		}

	}

	//요요 여부
	long long yoyo = beforenergy - (abs(normalloss));
	
	if (yoyo > 0) {
		check = "YOYO";
	}
	else {
		check = "NO";
	}
	weight2 = beforeweight2;
	loss2 = normalloss;
	
	

}




int main() {
	//백준 19363번
	

	cin >> beforeweight1 >> beforenergy >> T;
	normalloss = beforenergy;
	beforeweight2 = beforeweight1;
	cin >> days >> dietenergy >> dietactive;

	defaultactive(dietenergy, dietactive, days);
	includeactive(dietenergy, dietactive, days);

	if (flag1 == 1) {
		cout << "Danger Diet" << '\n';

	}
	else {
		cout << weight1 << ' ' << loss1 << '\n';
	}

	if (flag2 == 1) {
		cout << "Danger Diet";

	}
	else {
		cout << weight2 << ' ' << loss2 << ' ' << check;
	}


	
	
}
