#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26; //알파벳 갯수는 총 26개 

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) { //str을 입력받아서 
    vector<int> result(SIZE, 0); //26개의 알파벳에 대하여 
    for (int i = 0; i < str.size(); i++) //모두 탐색하여 등장하는 알파벳은
        result[str[i] - 'A']++; //+1해준다
    return result; //출현 횟수를 기록한 result 벡터를 반환
}

/**
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */
int main() {
    int n, ans = 0; //단어갯수, 정답
    string source, target; //검사하는 단어, 검사할 단어

    //입력
    cin >> n >> source; //단어갯수, 검사하는 대상의 단어

    //연산
    vector<int> source_alpha = alphaMap(source); //source 단어에 대해서 탐색할것임
    while (--n) { //n-1개의 단어에 대해서 비슷한 단어인지 탐색 
        cin >> target; //검사할 단어를 탐색 

        int diff = 0; //다른점 카춘트 
        vector<int> target_alpha = alphaMap(target); //target의 알파벳 출현 빈도 기록한 벡터
        for (int i = 0; i < SIZE; i++) //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); //단어의 차이가 있으면 +1
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나
            ans++;    //단어의 차이가 1가지면 ok, 단어의 차이가 2이면 길이가 같을때만 됨
    }

    //출력
    cout << ans;
}
