#include <iostream>
#include <vector>

//std:: 생략
using namespace std;

//컨테이너 벨트 2*n개의 각각 현재 상태 정보를 내구도,로봇 존재 여부로 판단하기 위해 구조체 형성
struct info { //내구도와 로봇 존재 여부
    int power; //내구도
    bool is_on; //로봇 존재 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

//컨베이너 벨트가 움직이는것을 인덱스 표시를 바꾸서 구현 
//1. 한칸 회전하는 단계 
int minusPosition(int n, int pos) { //인덱스 감소
    //belt 에는 0,1,..2*n 순으로 있으므로 인덱스가 하나 감소하는것을
    //하나 감소했을때 0보다 크면 그대로 그 지점을 이동한 인덱스로 표시하고
    if (--pos >= 0)
        //그대로 리턴
        return pos;
    //0보다 작다는것은 인덱스 0에서 컨베일트가 움직여서 2*n으로 움직였다는것
    //인덱스므로 2*n-1을 리턴
    return n * 2 - 1;
}

//2. 로봇 움직일수 있으면 움직이고 내구도 감소
void second(int n, int start, int end) {
    //현재 end에서 로봇이 내려서 빔
    int cur = end;

    while (cur != start) { //end - 1 부터 start 까지 검사
        //end-1,end-2,...start까지 하나씩 앞 인덱스로 가서 움직일수 있는거 있는지 검사
        cur = minusPosition(n, cur);
        
        int next = (cur + 1) % (n * 2); //다음 위치
        
        if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
            //지금 위치에는 이제 로봇없음
            belt[cur].is_on = false;
            //로봇이 next로 갔으므로 next의 내구도 -1 
            belt[next].power--;
           
            if (next != end) //내리는 위치 아닐 경우만
                //로봇 옮기기,내리는 위치였으면 로봇이 바로 내리는 작업을 해야하므로 표시 x
                belt[next].is_on = true; 
            //next로 가서 next의 내구도가 0이되면 갯수 +1 
            if (belt[next].power == 0)
                zero_power++;
        }
    }
}

//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리기
void third(int start) { //start 올리는 위치
    if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
        belt[start].is_on = true;  //로봇이 올라가게 됨
        belt[start].power--; //내구도는 -1 

        //내구도가 0이되면 zero_power 갯수 +1
        if (belt[start].power == 0)
            //전역변수 내구도 0인 갯수 세는 변수 +1
            zero_power++;
    } 
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
    //입출력 속도 개선
    ios_base::sync_with_stdio(false);
    //입출력 속도 개선
    cin.tie(NULL);

    //1 -n ,n+1-2n 두줄의 벨트 있게 n 입력받음
    //내구도가 0인 갯수가 k일때 종료
    int n, k;

    //n,k 입력
    cin >> n >> k;

    //2*n 칸의 벨트가 형성되므로 info형 벡터 belt에 2*n 갯수를 할당하고, 각 요소의 power과 is_on 값을 각각 0,false로 초기화한다
    belt.assign(n * 2, { 0, false });

    //각 1,2,..2*n의 내구도를 입력받음 (단 인덱스므로 -1)
    for (int i = 0; i < n * 2; i++)
        //info 구조 벡터는 power(내구도),is_on을 요소로 갖는데 power에 값 입력받아 저장
        cin >> belt[i].power;

    //연산
    //인덱스이므로 1번(올리는 위치)-> 0번 인덱스, n번(내리는 위치)-> n-1
    int start = 0;    //처음 올리는 위치
    int end = n - 1;  //처음 내리는 위치

    //종료했을떄 몇단계였는지 카운트 해야하므로 step 설정
    int step = 0;     //단계 수
    
    //종료조건을 만족해 종료될때까지 반복
    while (true) {

        //1단계실행
        //올리는 위치의 인덱스 갱신
        start = minusPosition(n, start);
        //내리는 위치의 인덱스 갱신
        end = minusPosition(n, end);


        if (belt[end].is_on) //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
           //end 위치에는 즉시 로봇이 내려서 이제 없음
            belt[end].is_on = false;

        //2단계 실행
        second(n, start, end);
        //3단계 실행
        third(start);

        //1~3단계 실행, 1step 완료
        step++;

        //내구도 갯수 0인개 k이상이 되었는지 확인
        if (zero_power >= k)
            //맞으면 모든 작업을 종료
            break;
    }

    //몇단계까지 실행되었는지 step 출력
    cout << step << '\n';

    //종료
    return 0;
}
