#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<stack>
#define MAX 100

using namespace  std;

stack<char> tmp;
string result="";


void cal(string s) {
	for (int i = 0; i < s.size(); i++) {
		//스택에는 괄호나 연산자만 들어감,나오는건 연산자만 나옴

		//피연산자는 바로 추가
		if (s[i] >= 'A' && s[i] <= 'Z') {
			result += s[i];

		}
		if (s[i] == '(') {

			tmp.push(s[i]);

		}
		if (s[i] == ')') {
			//왼쪽 괄호 나올때까지 모든 연산자 추가하기
			while (!tmp.empty() && tmp.top() != '(') {

				result += tmp.top();
				tmp.pop();

			}
			//왼쪽 괄호 제거
			tmp.pop();

		}
		if (s[i] == '*' || s[i] == '/') {
			//자신들과 같은 우선순위 연산자만 빼고(앞에 있던 거니까) 자신을 추가하기
			while (!tmp.empty()&&(tmp.top() == '*' || tmp.top() == '/')) {
				
					result += tmp.top();
					tmp.pop();
				
			}
			//뒤에 자신과 같은 우선순위 연산자 올수 있으니까 일단 스택에 넣기
			tmp.push(s[i]);
		}
		if (s[i] == '+' || s[i] == '-') {
			//자신들과 같고 우위의 연산자 빼기
			while (!tmp.empty()&& tmp.top() != '(') {
				
					result += tmp.top();
					tmp.pop();
				
			}
			tmp.push(s[i]);
		}
		
	}
	while (!tmp.empty()) {
		result += tmp.top();
		tmp.pop();
	}
}



int main() {

	//백준 1918번

	//중위 표기식을 후위 표기식으로 바꾸기
	//우선순위
	// ( <<<<  + - <<<< * /
	string s;
	cin >> s;
	cal(s);
	cout << result;
	




}
