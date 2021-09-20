#include<iostream>
#include<string>
using namespace  std;

int box[21] = { 0 };
int main() {

	//백준 11723번

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//add 추가 remove 제거 chcek 있는지 확인 1,0 toggle 있으면 제거 없으면 추가 all->1..20 empty 공집합으로

	int n;
	int m;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "add") {
			cin >> m;
			if (box[m] == 0) {
				box[m] = 1;
			}

		}
		else if (s == "remove") {
			cin >> m;
			if (box[m] == 1) {
				box[m] = 0;
			}


		}
		else if (s == "check") {
			cin >> m;
			if (box[m] == 1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}

		}
		else if (s == "toggle") {
			cin >> m;
			if (box[m] == 1) {
				box[m] = 0;
			}
			else if (box[m] == 0) {
				box[m] = 1;
			}
			

		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) {
				box[i] = 1;
			}


		}
		else if (s == "empty") {
			fill_n(box, 21, 0);


		}





	}




}
