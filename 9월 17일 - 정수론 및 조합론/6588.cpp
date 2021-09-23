#include <iostream>
#include <vector>
#include <cmath> //sqrt 사용
#include<string>
//백준 6588번
#define MAX 1000000
using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<bool>is_prime(MAX + 1, true);

	//n입력받을떄마다 제외하지 말고 while밖에서 소수 처리하기
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (is_prime[i]) {
			//맨 처음 소수는 제외하기
			for (int j = i * i; j <= MAX; j += i) {
				if (!is_prime[j])
					continue;

				is_prime[j] = false;

			}


		}

	}
	int n = 1;


	while (n != 0) {
		cin >> n;
		if (n == 0)break;

		//두 홀수 소수의 합으로 나타내기


		int flag = 0;
		//여러개면 b-a가 가장 큰것을 출력, 
		for (int i = 3; i <= (n / 2); i += 2) { //홀수이므로 홀수만 체크
			if (is_prime[i] && is_prime[n - i] && (n - i) % 2 == 1) {
				cout << n << " = " << i << " + " << n - i << '\n';
				flag = 1;
				break;
			}

		}
		if (!flag) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}

	}




}
