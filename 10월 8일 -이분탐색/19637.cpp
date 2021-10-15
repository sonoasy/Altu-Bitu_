#include <iostream>
#include <map>

using namespace std;

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() {
    ios::sync_with_stdio(false);//속도 향상
    cin.tie(NULL);//속도 향상

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; //칭호의 갯수, 캐릭터 갯수, 전투력
    string name; //이름

    //입력
    cin >> n >> m; //칭호의 갯수,캐릿터 갯수
    while (n--) { //모든 칭호에 대하여 
        cin >> name >> power;//이름,전투력을
        if (title[power].empty()) //새로 저장
            title[power] = name; //power 상한값, name
    }

    //출력
    while (m--) { //캐릭터 갯수만큼
        cin >> power;  //power를 입력받으면 
        cout << title.lower_bound(power)->second << '\n'; //될수 있는 가장 가까운 lower_bound의 이름을 출력
    }
}
