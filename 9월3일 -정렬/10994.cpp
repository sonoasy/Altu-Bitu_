#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//별 직사각형 만들기
void star(int n) { //첫째줄,마지막 줄이면 한 줄

	for (int j = n; j > 0; j--) {

		//긴 별줄 앞에 오는 작은 별
		for (int k = 0; k < 2 * (n - j); k++) {
			if (k % 2 == 0) {
				cout << '*';
			}
			else {
				cout << ' ';
			}

		}
		//긴 별줄
		for (int i = 2 * (n - j); i < 2 * (n + j) - 3; i++) {
			cout << '*';
		}
		//긴 별줄 뒤에 오는 작은 별
		for (int k = 2 * (n + j) - 3; k < 4 * n - 3; k++) {
			if (k % 2 == 0) {
				cout << '*';
			}
			else {
				cout << ' ';
			}

		}

		cout << '\n';
		//긴 별줄 다음에 한칸씩 띄워서 있는거
		if (j != 1) {
			//앞쪽 
			for (int k = 0; k < 4 * n - 3; k++) {
				if (k == 0 || k <= 2 * (n - j) || k == 4 * n - 4 || k >= (4 * n - 4 - 2 * (n - j))) {
					if (k % 2 == 0) {
						cout << '*';
					}
					else {
						cout << ' ';
					}
				}
				else {
					cout << ' ';
				}
			}
			cout << '\n';
		}
	}
	//반대로 만들기

	for (int j = 2; j <= n; j++) {
		//긴 별줄 다음에 한칸씩 띄워서 있는거
		if (j != 1) {
			//앞쪽 
			for (int k = 0; k < 4 * n - 3; k++) {
				if (k == 0 || k <= 2 * (n - j) || k == 4 * n - 4 || k >= (4 * n - 4 - 2 * (n - j))) {
					if (k % 2 == 0) {
						cout << '*';
					}
					else {
						cout << ' ';
					}
				}
				else {
					cout << ' ';
				}
			}
			cout << '\n';
		}

		//긴 별줄 앞에 오는 작은 별
		for (int k = 0; k < 2 * (n - j); k++) {
			if (k % 2 == 0) {
				cout << '*';
			}
			else {
				cout << ' ';
			}

		}
		//긴 별줄
		for (int i = 2 * (n - j); i < 2 * (n + j) - 3; i++) {
			cout << '*';
		}
		//긴 별줄 뒤에 오는 작은 별
		for (int k = 2 * (n + j) - 3; k < 4 * n - 3; k++) {
			if (k % 2 == 0) {
				cout << '*';
			}
			else {
				cout << ' ';
			}

		}

		cout << '\n';

	}
}



int main() {
	//백준 10994번
	int n;

	cin >> n;
	int s = n;
	star(n);




}
